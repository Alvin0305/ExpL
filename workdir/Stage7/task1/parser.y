%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "node/node.h"
    #include "node/library/node_library.h"
    #include "node/user_type/node_user_type.h"
    #include "node/pointer/node_pointer.h"
    #include "code_gen/code_gen.h"
    #include "code_gen/function/function.h"
    #include "define/constants.h"
    #include "g_symbol_table/g_symbol_table.h"
    #include "local_symbol_table/local_symbol_table.h"
    #include "util/util.h"
    #include "error_handler/error_handler.h"
    #include "type_table/type_table.h"
    #include "register/register.h"

    int yylex(void);
    void yyerror(char const *msg);

    FILE *target_file;
    extern FILE *yyin;
    extern int lineNumber;
    extern char *yytext;
%}

%union {
    struct tnode *node;
    struct FieldList *field;
}

%type program programBody
%type <node> globalDecl globalTupleDecl globalVarList
%type <node> funcDefBlock funcDef funcCall argList
%type <node> paramList param 
%type <node> funcDeclParamList funcDeclParam
%type <node> mainBlock body

%type <node> expr boolexpr
%type <field> typeField typeFieldList 
%type <node> stmtList stmt assignmentStmt compoundAssignment
%type <node> whileStmt ifStmt repeatUntilStmt doWhileStmt
%type <node> inputStmt outputStmt allocStmt freeStmt initStmt
%type <node> localDeclBlock idList 
%type <node> type
%type <node> dimensionDecl dimensionUsage

%type <node> returnStmt 
%type <node> tupleFieldList tupleField tupleIdList 
%type <node> fieldAssignStmt fieldAccess

%token KW_READ KW_WRITE KW_ALLOC KW_FREE KW_INIT
%token PLUS MUL MINUS DIV MOD 
%token ASSIGN 
%token COMMA SEMI DOT ARROW
%token AMPERSAND
%token GT GE LT LE NE EQ
%token KW_BEGIN KW_END KW_IF KW_THEN KW_ELSE KW_ENDIF
%token KW_WHILE KW_DO KW_ENDWHILE KW_BREAK KW_CONTINUE KW_REPEAT KW_UNTIL
%token KW_DECL KW_ENDDECL 
%token TYPE_INT TYPE_STRING TYPE_VOID KW_TUPLE
%token AND OR NOT
%token INCREMENT DECREMENT
%token ASSIGN_ADD ASSIGN_SUB ASSIGN_MUL ASSIGN_DIV ASSIGN_MOD
%token KW_RETURN MAIN KW_BRKP
%token KW_TYPE KW_ENDTYPE
%token KW_NULL

%token <node> ID NUM STRING_LITERAL

%left OR
%left AND
%right NOT

%nonassoc GE GT LE LT NE EQ

%left PLUS MINUS
%left MUL DIV MOD

%%

program : programBody                                               { exit(0); }
    ;

programBody : typeDefBlock globalDeclBlock funcDefBlock mainBlock
    | typeDefBlock globalDeclBlock mainBlock
    | mainBlock
    ;

typeDefBlock : KW_TYPE typeDefList KW_ENDTYPE                       { printTypeTable(); }
    | KW_TYPE KW_ENDTYPE
    |
    ;

typeDefList : typeDefList typeDef
    | typeDef
    ;

typeDef : ID { createNewType($1->varName, USER_TYPE); } '{' typeFieldList '}'  { setFieldsOfType($1->varName, $4); }
    ;

typeFieldList : typeFieldList typeField                             { $$ = mergeTypeFields($1, $2); }
    | typeField                                                     { $$ = $1; }
    ;

typeField : TYPE_INT ID SEMI                                        { $$ = createNewTypeField($2->varName, lookupTT("INT")); }
    | TYPE_STRING ID SEMI                                           { $$ = createNewTypeField($2->varName, lookupTT("STRING")); }
    | ID ID SEMI                                                    { $$ = createNewTypeField($2->varName, lookupTT($1->varName)); }
    ;

globalDeclBlock : KW_DECL globalDeclList KW_ENDDECL                 { printGST(); }
    | KW_DECL KW_ENDDECL
    ;

globalDeclList : globalDeclList globalDecl
    | globalDecl
    ;

globalDecl : type globalVarList SEMI                                { addToGST($1, $2); }
    | globalTupleDecl SEMI
    ;

globalVarList : globalVarList COMMA ID                              { $$ = createConnectorNode($1, $3); }
    | globalVarList COMMA ID dimensionDecl                          { $$ = createConnectorNode($1, createNewArrayNode($3, $4)); }
    | globalVarList COMMA MUL ID                                    { $$ = createConnectorNode($1, createNewPointerNode($4)); }
    | globalVarList COMMA ID '(' funcDeclParamList ')'              { $$ = createConnectorNode($1, createFunctionDeclarationNode($3, $5)); }
    | ID dimensionDecl                                              { $$ = createNewArrayNode($1, $2); }
    | MUL ID                                                        { $$ = createNewPointerNode($2); }
    | ID                                                            { $$ = $1; }
    | ID '(' funcDeclParamList ')'                                  { $$ = createFunctionDeclarationNode($1, $3); }
    ;

globalTupleDecl : KW_TUPLE ID '(' tupleFieldList ')' tupleIdList    { addNewTupleTypeToGST($2, $4, $6); $$ = NULL; }
    ;

tupleFieldList : tupleFieldList COMMA tupleField                    { $$ = createConnectorNode($1, $3); }
    | tupleField                                                    { $$ = $1; }
    ;

tupleField : type ID                                                { $$ = createConnectorNode($1, $2); }
    ;

tupleIdList : tupleIdList COMMA ID                                  { $$ = createConnectorNode($1, $3); }
    | tupleIdList COMMA MUL ID                                      { $$ = createConnectorNode($1, createNewPointerNode($4)); }
    | MUL ID                                                        { $$ = createNewPointerNode($2); }
    | ID                                                            { $$ = $1; }
    ;

funcDeclParamList : funcDeclParamList COMMA funcDeclParam           { $$ = createConnectorNode($1, $3); }
    | funcDeclParam                                                 { $$ = $1; }
    |                                                               { $$ = NULL; }
    ;

funcDeclParam : type ID                                             { $$ = createParamNode($1, $2, false, false); }
    | type MUL ID                                                   { $$ = createParamNode($1, $3, false, true); }
    ;

type : TYPE_INT                                                     { $$ = createTypeNode(INT); }
    | TYPE_STRING                                                   { $$ = createTypeNode(STRING); }
    | KW_TUPLE ID                                                   { $$ = createTupleTypeNode($2); }
    | TYPE_VOID                                                     { $$ = createTypeNode(VOID); }
    | ID                                                            { $$ = createUserTypeNode($1); }
    ;

funcDefBlock : funcDefBlock funcDef                                 { $$ = createConnectorNode($1, $2); }   
    | funcDef                                                       { $$ = $1; }
    ;

funcDef : type ID '(' paramList ')' 
        { currentFunction = lookupGST($2->varName); } 
    '{' localDeclBlock body '}'
        { $$ = createFunctionDefinitionNode($1, $2, $4, $8, $9); }
    ;

body : KW_BEGIN stmtList KW_END                                     { $$ = $2; }
    ;

paramList : paramList COMMA param                                   { $$ = createConnectorNode($1, $3); }
    | param                                                         { $$ = $1; }
    |                                                               { $$ = NULL; }
    ;

param : type ID                                                     { $$ = createParamNode($1, $2, true, false); }
    | type MUL ID                                                   { $$ = createParamNode($1, $3, true, true); }
    ;

localDeclBlock : KW_DECL localDeclList KW_ENDDECL                   { printLST(); $$ = NULL; }
    | KW_DECL KW_ENDDECL                                            { $$ = NULL; }
    |                                                               { $$ = NULL; }
    ;

localDeclList : localDeclList localDecl
    | localDecl
    | localDeclList localTupleDecl
    | localTupleDecl
    ;

localDecl : type idList SEMI                                        { addToLST($1, $2); }
    ;

localTupleDecl : KW_TUPLE ID '(' tupleFieldList ')' tupleIdList SEMI        { addNewTupleTypeToLST($2, $4, $6); }
    ;

idList : idList COMMA ID                                            { $$ = createConnectorNode($1, $3); }
    | idList COMMA MUL ID                                           { $$ = createConnectorNode($1, createNewPointerNode($4)); }
    | ID                                                            { $$ = $1; }
    | MUL ID                                                        { $$ = createNewPointerNode($2); }
    ;

dimensionDecl : dimensionDecl '[' NUM ']'                           { $$ = createConnectorNode($1, $3); }
    | '[' NUM ']'                                                   { $$ = $2; }
    ;

mainBlock : TYPE_INT MAIN '(' ')' '{' localDeclBlock body '}'       { printLST(); generateMainCode($7); 
                                                                    freeLocalSymbolTable(); $$ = NULL; }
    ;

stmtList : stmtList stmt                                            { $$ = createConnectorNode($1, $2); }
    | stmt                                                          { $$ = $1; }
    ;

stmt : inputStmt                                                    { $$ = $1; }
    | outputStmt                                                    { $$ = $1; }
    | assignmentStmt                                                { $$ = $1; }
    | ifStmt                                                        { $$ = $1; }
    | whileStmt                                                     { $$ = $1; }
    | KW_BREAK SEMI                                                 { $$ = createBreakNode(); }
    | KW_CONTINUE SEMI                                              { $$ = createContinueNode(); }
    | repeatUntilStmt                                               { $$ = $1; }
    | doWhileStmt                                                   { $$ = $1; }
    | KW_BRKP SEMI                                                  { $$ = createBreakPointNode(); }
    | funcCall SEMI                                                 { $$ = $1; }
    | returnStmt SEMI                                               { $$ = $1; }
    | allocStmt SEMI                                                { $$ = $1; }
    | freeStmt SEMI                                                 { $$ = $1; }
    | initStmt SEMI                                                 { $$ = $1; }
    ;

initStmt : ID ASSIGN KW_INIT '(' ')'                                { $$ = createInitNode($1); }
    ;

allocStmt : ID ASSIGN KW_ALLOC '(' ')'                              { $$ = createAllocNode($1); }
    | fieldAccess ASSIGN KW_ALLOC '(' ')'                           { $$ = createAllocNode($1); }
    | ID dimensionUsage ASSIGN KW_ALLOC '(' ')'                     { $$ = createAllocNode(createArrayAccessNode($1, $2)); }
    ;

freeStmt : KW_FREE '(' ID ')'                                       { $$ = createFreeNode($3); }
    ;

returnStmt : KW_RETURN expr                                         { $$ = createReturnNode($2); }
    ;

inputStmt : KW_READ '(' ID ')' SEMI                                 { $$ = createReadNode($3); }
    | KW_READ '(' ID dimensionUsage ')' SEMI                        { $$ = createReadToArrayNode($3, $4); }
    ;

outputStmt : KW_WRITE '(' expr ')' SEMI                             { $$ = createWriteNode($3); }
    ;

assignmentStmt : ID ASSIGN expr SEMI                                { $$ = createAssignNode($1, $3); }
    | ID dimensionUsage ASSIGN expr SEMI                            { $$ = createArrayAssignNode($1, $2, $4); }
    | MUL ID ASSIGN expr SEMI                                       { $$ = createAssignToDereferencedNode($2, $4); }
    | ID INCREMENT SEMI                                             { $$ = createIncrementNode($1); }
    | ID DECREMENT SEMI                                             { $$ = createDecrementNode($1); }
    | compoundAssignment SEMI                                       { $$ = $1; }
    | fieldAssignStmt SEMI                                          { $$ = $1; }
    ;

fieldAccess : fieldAccess DOT ID                                    { $$ = createMemberAccessNode($1, $3, ACCESS_DOT); }
    | ID dimensionUsage DOT ID                                      { $$ = createMemberAccessNode(createArrayAccessNode($1, $2), $4, ACCESS_DOT); }
    | ID DOT ID                                                     { $$ = createMemberAccessNode($1, $3, ACCESS_DOT); }
    | ID ARROW ID                                                   { $$ = createMemberAccessNode($1, $3, ACCESS_ARROW); }
    ;

fieldAssignStmt : fieldAccess ASSIGN expr                           { $$ = createMemberAssignmentNode($1, $3); }
    ;

compoundAssignment : ID ASSIGN_ADD expr                             { $$ = createCompoundAssignNode(NODE_ADD, $1, $3); }
    | ID ASSIGN_SUB expr                                            { $$ = createCompoundAssignNode(NODE_SUB, $1, $3); }
    | ID ASSIGN_MUL expr                                            { $$ = createCompoundAssignNode(NODE_MUL, $1, $3); }
    | ID ASSIGN_DIV expr                                            { $$ = createCompoundAssignNode(NODE_DIV, $1, $3); }
    | ID ASSIGN_MOD expr                                            { $$ = createCompoundAssignNode(NODE_MOD, $1, $3); }
    ;

dimensionUsage : dimensionUsage '[' expr ']'                        { $$ = createConnectorNode($1, $3); }
    | '[' expr ']'                                                  { $$ = $2; }
    ;

ifStmt : KW_IF '(' boolexpr ')' KW_THEN stmtList KW_ELSE stmtList KW_ENDIF   { $$ = createIfElseNode($3, $6, $8); }
    | KW_IF '(' boolexpr ')' KW_THEN stmtList KW_ENDIF                       { $$ = createIfNode($3, $6); }
    ;

whileStmt : KW_WHILE '(' boolexpr ')' KW_DO stmtList KW_ENDWHILE    { $$ = createWhileNode($3, $6); }
    ;

repeatUntilStmt: KW_REPEAT stmtList KW_UNTIL '(' boolexpr ')' SEMI  { $$ = createRepeatUntilNode($2, $5); }
    ;

doWhileStmt: KW_DO stmtList KW_WHILE '(' boolexpr ')' SEMI          { $$ = createDoWhileNode($2, $5); }
    ;

expr : expr PLUS expr                                               { $$ = createArithOpNode(NODE_ADD, $1, $3); }
    | expr MINUS expr                                               { $$ = createArithOpNode(NODE_SUB, $1, $3); }
    | expr MUL expr                                                 { $$ = createArithOpNode(NODE_MUL, $1, $3); }
    | expr DIV expr                                                 { $$ = createArithOpNode(NODE_DIV, $1, $3); }
    | expr MOD expr                                                 { $$ = createArithOpNode(NODE_MOD, $1, $3); }
    | '(' expr ')'                                                  { $$ = $2; }
    | NUM                                                           { $$ = $1; }
    | ID                                                            { $$ = createVariableUsageNode($1->varName); }
    | STRING_LITERAL                                                { $$ = $1; }
    | ID dimensionUsage                                             { $$ = createArrayAccessNode($1, $2); }
    | MUL ID                                                        { $$ = createDereferenceNode($2); }
    | AMPERSAND ID                                                  { $$ = createAddressToNode($2); }
    | funcCall                                                      { $$ = $1; }
    | fieldAccess                                                   { $$ = $1; }
    | KW_NULL                                                       { $$ = createNullNode(); }
    ;

funcCall : ID '('')'                                                { $$ = createFunctionCallNode($1, NULL); }
    | ID '(' argList ')'                                            { $$ = createFunctionCallNode($1, $3); }

argList : argList COMMA expr                                        { $$ = createConnectorNode($1, $3); }
    | expr                                                          { $$ = $1; }
    ;

boolexpr : expr LE expr                                             { $$ = createConditionNode(NODE_LE, $1, $3); }
    | expr LT expr                                                  { $$ = createConditionNode(NODE_LT, $1, $3); }
    | expr GE expr                                                  { $$ = createConditionNode(NODE_GE, $1, $3); }
    | expr GT expr                                                  { $$ = createConditionNode(NODE_GT, $1, $3); }
    | expr NE expr                                                  { $$ = createConditionNode(NODE_NE, $1, $3); }
    | expr EQ expr                                                  { $$ = createConditionNode(NODE_EQ, $1, $3); }
    | boolexpr OR boolexpr                                          { $$ = createConditionNode(NODE_OR, $1, $3); }
    | boolexpr AND boolexpr                                         { $$ = createConditionNode(NODE_AND, $1, $3); }
    | NOT boolexpr                                                  { $$ = createConditionNode(NODE_NOT, $2, NULL); }
    | '(' boolexpr ')'                                              { $$ = $2; }
    ;

%%

void yyerror(char const *msg) {
    printf("[Error] : %s in line: %d [%s]\n", msg, lineNumber, yytext);
    return;
}

int main(int argc, char **argv) {
    FILE *source_file;
    if (argc == 2) {
        source_file = fopen(argv[1], "r");
    } else {
        source_file = fopen(SOURCE_FILE, "r");
    }

    if (!source_file) {
        compilerError(E_NO_SOURCE_FILE);
    }

    target_file = fopen(INTERMEDIATE_FILE, "w");

    yyin = source_file;
    initializeRegisters();
    generateHeader();
    initializeTypeTable();

    return yyparse();
}