%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "node/node.h"
    #include "code_gen/code_gen.h"
    #include "code_gen/function/function.h"
    #include "define/constants.h"
    #include "g_symbol_table/g_symbol_table.h"
    #include "local_symbol_table/local_symbol_table.h"
    #include "util/util.h"
    #include "error_handler/error_handler.h"
    #include "type_table/type_table.h"

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

%type <node> expr statementList statement inputStatement outputStatement assignmentStatement compoundAssignment
%type <node> whileStatement ifStatement repeatUntilStatement doWhileStatement boolexpr
%type <node> globalDeclarationsBlock globalDeclarationList globalDecl globalVarList type dimensionDecl dimensionUsage
%type <node> paramList param 
%type <node> mainBlock body
%type <node> functionDefinitionBlock functionDefinition localDeclBlock localDeclList localDecl idList argList functionCall returnStatement funcDeclParamList funcDeclParam
%type <node> globalTupleDeclaration tupleFieldList tupleIdList tupleField localTupleDecl tupleAssignmentStatement tupleAccess 
%type <node> fieldAccess fieldAssignmentStatement memberAccess
%type program programBody
%type <field> typeField typeFieldList 

%token READ WRITE
%token PLUS MUL MINUS DIV MOD ASSIGN SEMI AMPERSAND
%token GT GE LT LE NE EQ
%token KW_BEGIN KW_END KW_IF KW_THEN KW_ELSE KW_ENDIF
%token KW_WHILE KW_DO KW_ENDWHILE KW_BREAK KW_CONTINUE KW_REPEAT KW_UNTIL
%token KW_DECL KW_ENDDECL TYPE_INT TYPE_STRING TYPE_VOID COMMA
%token AND OR NOT
%token INCREMENT DECREMENT
%token ASSIGN_ADD ASSIGN_SUB ASSIGN_MUL ASSIGN_DIV ASSIGN_MOD
%token KW_RETURN MAIN KW_BRKP
%token KW_TUPLE DOT ARROW
%token KW_TYPE KW_ENDTYPE

%token <node> ID NUM STRING_LITERAL

%left OR
%left AND
%right NOT

%nonassoc GE GT LE LT NE EQ

%left PLUS MINUS
%left MUL DIV MOD

%%

program : programBody                                       { exit(0); }
    ;

programBody : typeDefBlock globalDeclarationsBlock functionDefinitionBlock mainBlock
    | typeDefBlock globalDeclarationsBlock mainBlock
    | mainBlock
    ;

typeDefBlock : KW_TYPE typeDefList KW_ENDTYPE                       { printTypeTable(); }
    | KW_TYPE KW_ENDTYPE
    |
    ;

typeDefList : typeDefList typeDef
    | typeDef
    ;

typeDef : ID { createNewType($1->varName); } '{' typeFieldList '}'  { setFieldsOfType($1->varName, $4); }
    ;

typeFieldList : typeFieldList typeField                     { $$ = mergeTypeFields($1, $2); }
    | typeField                                             { $$ = $1; }
    ;

typeField : TYPE_INT ID SEMI                                { $$ = createNewTypeField($2->varName, typeTableLookup("INT")); }
    | TYPE_STRING ID SEMI                                   { $$ = createNewTypeField($2->varName, typeTableLookup("STRING")); }
    | ID ID SEMI                                            { $$ = createNewTypeField($2->varName, typeTableLookup($1->varName)); }
    ;

globalDeclarationsBlock : KW_DECL globalDeclarationList KW_ENDDECL  { printGST(); $$ = NULL; }
    | KW_DECL KW_ENDDECL                                            { $$ = NULL; }
    ;

globalDeclarationList : globalDeclarationList globalDecl    { $$ = NULL; }
    | globalDecl                                            { $$ = NULL; }
    ;

globalDecl : type globalVarList SEMI                        { addToGST($1, $2); $$ = NULL; }
    | globalTupleDeclaration SEMI                           { $$ = NULL; }
    ;

globalVarList : globalVarList COMMA ID                      { $$ = createConnectorNode($1, $3); }
    | globalVarList COMMA ID dimensionDecl                  { $$ = createConnectorNode($1, createNewArrayNode($3, $4)); }
    | globalVarList COMMA MUL ID                            { $$ = createConnectorNode($1, createNewPointerNode($4)); }
    | globalVarList COMMA ID '(' funcDeclParamList ')'      { $$ = createConnectorNode($1, createFunctionDeclarationNode($3, $5)); }
    | ID dimensionDecl                                      { $$ = createNewArrayNode($1, $2); }
    | MUL ID                                                { $$ = createNewPointerNode($2); }
    | ID                                                    { $$ = $1; }
    | ID '(' funcDeclParamList ')'                          { $$ = createFunctionDeclarationNode($1, $3); }
    ;

globalTupleDeclaration : KW_TUPLE ID '(' tupleFieldList ')' tupleIdList        { addTupleTypeToGST($2, $4, $6); $$ = NULL; }
    ;

tupleFieldList : tupleFieldList COMMA tupleField            { $$ = createConnectorNode($1, $3); }
    | tupleField                                            { $$ = $1; }
    ;

tupleField : type ID                                        { $$ = createConnectorNode($1, $2); }
    ;

tupleIdList : tupleIdList COMMA ID                          { $$ = createConnectorNode($1, $3); }
    | tupleIdList COMMA MUL ID                              { $$ = createConnectorNode($1, createNewPointerNode($4)); }
    | MUL ID                                                { $$ = createNewPointerNode($2); }
    | ID                                                    { $$ = $1; }
    ;

funcDeclParamList : funcDeclParamList COMMA funcDeclParam   { $$ = createConnectorNode($1, $3); }
    | funcDeclParam                                         { $$ = $1; }
    |                                                       { $$ = NULL; }
    ;

funcDeclParam : type ID                                     { $$ = createParamNode($1, $2, false, false); }
    | type MUL ID                                           { $$ = createParamNode($1, $3, false, true); }
    ;

type : TYPE_INT                                             { $$ = createTypeNode(INT); }
    | TYPE_STRING                                           { $$ = createTypeNode(STRING); }
    | KW_TUPLE ID                                           { $$ = createTupleTypeNode($2); }
    | TYPE_VOID                                             { $$ = createTypeNode(VOID); }
    | ID                                                    { $$ = createUserTypeNode($1); }
    ;

functionDefinitionBlock : functionDefinitionBlock functionDefinition    { $$ = createConnectorNode($1, $2); }   
    | functionDefinition                                                { $$ = $1; }
    ;

functionDefinition : type ID '(' paramList ')' 
        { currentFunction = lookupGST($2->varName); } 
    '{' localDeclBlock body '}'  
        { $$ = createFunctionDefinitionNode($1, $2, $4, $8, $9); }
    ;

body : KW_BEGIN statementList KW_END                        { $$ = $2; }
    ;

paramList : paramList COMMA param                           { $$ = createConnectorNode($1, $3); }
    | param                                                 { $$ = $1; }
    |                                                       { $$ = NULL; }
    ;

param : type ID                                             { $$ = createParamNode($1, $2, true, false); }
    | type MUL ID                                           { $$ = createParamNode($1, $3, true, true); }
    ;

localDeclBlock : KW_DECL localDeclList KW_ENDDECL           { $$ = $2; }
    | KW_DECL KW_ENDDECL                                    { $$ = NULL; }
    |                                                       { $$ = NULL; }
    ;

localDeclList : localDeclList localDecl                     { $$ = createConnectorNode($1, $2); }
    | localDecl                                             { $$ = $1; }
    | localDeclList localTupleDecl                          { $$ = createConnectorNode($1, $2); }
    | localTupleDecl                                        { $$ = $1; }
    ;

localDecl : type idList SEMI                                { addToLST($1, $2); $$ = NULL; }
    ;

localTupleDecl : KW_TUPLE ID '(' tupleFieldList ')' tupleIdList SEMI        { addTupleTypeToLST($2, $4, $6); $$ = NULL; }
    ;

idList : idList COMMA ID                                    { $$ = createConnectorNode($1, $3); }
    | idList COMMA MUL ID                                   { $$ = createConnectorNode($1, createNewPointerNode($4)); }
    | ID                                                    { $$ = $1; }
    | MUL ID                                                { $$ = createNewPointerNode($2); }
    ;

dimensionDecl : dimensionDecl '[' NUM ']'                   { $$ = createConnectorNode($1, $3); }
    | '[' NUM ']'                                           { $$ = $2; }
    ;

mainBlock : TYPE_INT MAIN '(' ')' '{' localDeclBlock body '}' { generateMainCode($7); printLocalSymbolTable(); freeLocalSymbolTable(); $$ = NULL; }
    ;

statementList : statementList statement                     { $$ = createConnectorNode($1, $2); }
    | statement                                             { $$ = $1; }
    ;

statement : inputStatement                                  { $$ = $1; }
    | outputStatement                                       { $$ = $1; }
    | assignmentStatement                                   { $$ = $1; }
    | ifStatement                                           { $$ = $1; }
    | whileStatement                                        { $$ = $1; }
    | KW_BREAK SEMI                                         { $$ = createBreakNode(); }
    | KW_CONTINUE SEMI                                      { $$ = createContinueNode(); }
    | repeatUntilStatement                                  { $$ = $1; }
    | doWhileStatement                                      { $$ = $1; }
    | KW_BRKP SEMI                                          { $$ = createBreakPointNode(); }
    | functionCall SEMI                                     { $$ = $1; }
    | returnStatement SEMI                                  { $$ = $1; }
    ;

returnStatement : KW_RETURN expr                            { $$ = createReturnNode($2); }
    ;

inputStatement : READ '(' ID ')' SEMI                       { $$ = createReadNode($3); }
    | READ '(' ID dimensionUsage ')' SEMI                   { $$ = createReadToArrayNode($3, $4); }
    ;

outputStatement : WRITE '(' expr ')' SEMI                   { $$ = createWriteNode($3); }
    ;

assignmentStatement : ID ASSIGN expr SEMI                   { $$ = createAssignNode($1, $3); }
    | ID dimensionUsage ASSIGN expr SEMI                    { $$ = createArrayAssignNode($1, $2, $4); }
    | MUL ID ASSIGN expr SEMI                               { $$ = createAssignToDereferencedNode($2, $4); }
    | ID INCREMENT SEMI                                     { $$ = createIncrementNode($1); }
    | ID DECREMENT SEMI                                     { $$ = createDecrementNode($1); }
    | compoundAssignment SEMI                               { $$ = $1; }
    // | tupleAssignmentStatement SEMI                         { $$ = $1; }
    | fieldAssignmentStatement SEMI                         { $$ = $1; }
    ;

memberAccess : memberAccess DOT ID                          { $$ = createMemberAccessNode($1, $3, ACCESS_DOT); }
    | ID DOT ID                                             { $$ = createMemberAccessNode($1, $3, ACCESS_DOT); }
    | ID ARROW ID                                           { $$ = createMemberAccessNode($1, $3, ACCESS_ARROW); }
    ;

// tupleAccess : ID DOT ID                                     { $$ = createTupleAccessNode($1, $3); }
//     | ID ARROW ID                                           { $$ = createTuplePointerAccessNode($1, $3); }
//     ;              

// fieldAccess : fieldAccess DOT ID                            { $$ = createUserTypeAccessNode($1, $3); }
//     | ID DOT ID                                             { $$ = createUserTypeAccessNode($1, $3); }
//     ;

// tupleAssignmentStatement : ID DOT ID ASSIGN expr            { $$ = createTupleAssignmentNode($1, $3, $5); }
//     | ID ARROW ID ASSIGN expr                               { $$ = createTuplePointerAssignmentNode($1, $3, $5); }
//     ;

fieldAssignmentStatement : memberAccess ASSIGN expr         { $$ = createMemberAssignmentNode($1, $3); }
    ;

compoundAssignment : ID ASSIGN_ADD expr                     { $$ = createCompoundAssignNode(NODE_ADD, $1, $3); }
    | ID ASSIGN_SUB expr                                    { $$ = createCompoundAssignNode(NODE_SUB, $1, $3); }
    | ID ASSIGN_MUL expr                                    { $$ = createCompoundAssignNode(NODE_MUL, $1, $3); }
    | ID ASSIGN_DIV expr                                    { $$ = createCompoundAssignNode(NODE_DIV, $1, $3); }
    | ID ASSIGN_MOD expr                                    { $$ = createCompoundAssignNode(NODE_MOD, $1, $3); }
    ;

dimensionUsage : dimensionUsage '[' expr ']'                { $$ = createConnectorNode($1, $3); }
    | '[' expr ']'                                          { $$ = $2; }
    ;

ifStatement : KW_IF '(' boolexpr ')' KW_THEN statementList KW_ELSE statementList KW_ENDIF   { $$ = createIfElseNode($3, $6, $8); }
    | KW_IF '(' boolexpr ')' KW_THEN statementList KW_ENDIF                                 { $$ = createIfNode($3, $6); }
    ;

whileStatement : KW_WHILE '(' boolexpr ')' KW_DO statementList KW_ENDWHILE                  { $$ = createWhileNode($3, $6); }
    ;

repeatUntilStatement: KW_REPEAT statementList KW_UNTIL '(' boolexpr ')' SEMI                { $$ = createRepeatUntilNode($2, $5); }
    ;

doWhileStatement: KW_DO statementList KW_WHILE '(' boolexpr ')' SEMI                        { $$ = createDoWhileNode($2, $5); }
    ;

expr : expr PLUS expr                                       { $$ = createArithOpNode(NODE_ADD, $1, $3); }
    | expr MINUS expr                                       { $$ = createArithOpNode(NODE_SUB, $1, $3); }
    | expr MUL expr                                         { $$ = createArithOpNode(NODE_MUL, $1, $3); }
    | expr DIV expr                                         { $$ = createArithOpNode(NODE_DIV, $1, $3); }
    | expr MOD expr                                         { $$ = createArithOpNode(NODE_MOD, $1, $3); }
    | '(' expr ')'                                          { $$ = $2; }
    | NUM                                                   { $$ = $1; }
    | ID                                                    { $$ = createVariableUsageNode($1->varName); }
    | STRING_LITERAL                                        { $$ = $1; }
    | ID dimensionUsage                                     { $$ = createArrayAccessNode($1, $2); }
    | MUL ID                                                { $$ = createDereferenceNode($2); }
    | AMPERSAND ID                                          { $$ = createAddressToNode($2); }
    | functionCall                                          { $$ = $1; }
    // | tupleAccess                                           { $$ = $1; }
    // | fieldAccess                                           { $$ = $1; }
    | memberAccess                                          { $$ = $1; }
    ;

functionCall : ID '('')'                                    { $$ = createFunctionCallNode($1, NULL); }
    | ID '(' argList ')'                                    { $$ = createFunctionCallNode($1, $3); }

argList : argList COMMA expr                                { $$ = createConnectorNode($1, $3); }
    | expr                                                  { $$ = $1; }
    ;

boolexpr : expr LE expr                                     { $$ = createConditionNode(NODE_LE, $1, $3); }
    | expr LT expr                                          { $$ = createConditionNode(NODE_LT, $1, $3); }
    | expr GE expr                                          { $$ = createConditionNode(NODE_GE, $1, $3); }
    | expr GT expr                                          { $$ = createConditionNode(NODE_GT, $1, $3); }
    | expr NE expr                                          { $$ = createConditionNode(NODE_NE, $1, $3); }
    | expr EQ expr                                          { $$ = createConditionNode(NODE_EQ, $1, $3); }
    | boolexpr OR boolexpr                                  { $$ = createConditionNode(NODE_OR, $1, $3); }
    | boolexpr AND boolexpr                                 { $$ = createConditionNode(NODE_AND, $1, $3); }
    | NOT boolexpr                                          { $$ = createConditionNode(NODE_NOT, $2, NULL); }
    | '(' boolexpr ')'                                      { $$ = $2; }
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
    generateHeader();
    initializeTypeTable();

    return yyparse();
}