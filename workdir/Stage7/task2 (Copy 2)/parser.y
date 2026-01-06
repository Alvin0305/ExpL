%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <signal.h>
    
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
    #include "class_table/class_table.h"
    #include "semantic_context/semantic_context.h"

    int yylex(void);
    void yyerror(char const *msg);
    void segFaultHandler(int sigNum);

    FILE *target_file;
    extern FILE *yyin;
    extern int lineNumber;
    extern char *yytext;
%}

%union {
    struct tnode *node;

    struct FieldList *field;
    
    struct ClassField *classField;
    struct ClassMethod *classMethod;
    
    struct Param *param;

    struct TupleField *tupleField;

    struct Dimension *dimension;
    struct TypeInfo *typeInfo;
    struct VarList *varList;
}

%type program programBody
%type <node> funcDefBlock funcDef funcCall argList

%type <node> mainBlock body

%type <node> expr boolexpr newStmt
%type <field> typeField typeFieldList 
%type <node> stmtList stmt assignmentStmt compoundAssignment
%type <node> whileStmt ifStmt repeatUntilStmt doWhileStmt
%type <node> inputStmt outputStmt allocStmt freeStmt initStmt
%type <node> localDeclBlock

%type <node> dimensionUsage

%type <node> returnStmt 
%type <node> fieldAssignStmt fieldAccess methodBodyBlock methodCall

%type <classField> classFieldDecl classFieldsDeclList
%type <param> methodParamList methodParam
%type <param> funcDeclParamList funcDeclParam
%type <param> paramList param
%type <classMethod> classMethodDecl classMethodsDeclList

%type <tupleField> tupleField tupleFieldList
%type <dimension> dimensionDecl

%type <typeInfo> type
%type <varList> globalVarList idList tupleIdList 

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
%token KW_CLASS KW_ENDCLASS KW_NEW

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

programBody : typeDefBlock classDefBlock globalDeclBlock funcDefBlock mainBlock
    | typeDefBlock classDefBlock globalDeclBlock mainBlock
    | mainBlock
    ;

classDefBlock : KW_CLASS classDefList KW_ENDCLASS                   { printCT(); }
    | KW_CLASS KW_ENDCLASS;
    |
    ;

classDefList : classDefList classDef
    | classDef
    ;

classDef : ID                                           { createNewClass($1->varName); } 
        '{' classFieldsDeclBlock classMethodsDefBlock '}'
    ;

classFieldsDeclBlock : KW_DECL classFieldsDeclList classMethodsDeclList KW_ENDDECL   { setFieldsToClass($2); setMethodsToClass($3); }
    | KW_DECL KW_ENDDECL
    |
    ;

classFieldsDeclList : classFieldsDeclList classFieldDecl                { $$ = mergeClassFields($1, $2); }
    | classFieldDecl                                                    { $$ = $1; }
    ;

classFieldDecl : type idList SEMI                                       { $$ = installVarsToCT($1, $2); }
    ;

classMethodsDeclList : classMethodsDeclList classMethodDecl             { $$ = mergeClassMethods($1, $2); }
    | classMethodDecl                                                   { $$ = $1; }
    ;

classMethodDecl : type ID '(' methodParamList ')' SEMI                        { $$ = createNewClassMethod($1, $2->varName, $4); }
    ;

classMethodsDefBlock : classMethodDefList
    |
    ;

classMethodDefList : classMethodDefList classMethodDef              
    | classMethodDef
    ;

classMethodDef : type ID                                                { activeMethod = lookupMethodInActiveClass($2->varName); }
        '(' methodParamList ')'                                         { addMethodParamsToLST($5); }
        '{' methodLocalDeclBlock methodBodyBlock '}'                    { checkMethodSignature($1, $2->varName, $5);
                                                                            generateFunctionCode(activeMethod->methodLabel, $10);
                                                                            freeLocalSymbolTable(); activeMethod = NULL; }
    ;

methodParamList : methodParamList COMMA methodParam                     { $$ = mergeParams($1, $3); }
    | methodParam                                                       { $$ = $1; }
    |                                                                   { $$ = NULL; }
    ;

methodParam : type ID                                                   { $$ = createParam($1, $2->varName, false); }
    | type MUL ID                                                       { $$ = createParam($1, $3->varName, true); }
    ;

methodLocalDeclBlock : KW_DECL methodLocalDeclList KW_ENDDECL           { printLST(); }
    | KW_DECL KW_ENDDECL                                                { printLST(); }
    ;

methodLocalDeclList : methodLocalDeclList methodLocalDecl
    | methodLocalDecl
    ;

methodLocalDecl : type idList SEMI                                      { installVarsToLST($1, $2); }
    ;

methodBodyBlock : KW_BEGIN stmtList KW_END                          { $$ = $2; }
    ;

typeDefBlock : KW_TYPE typeDefList KW_ENDTYPE                       { printTypeTable(); }
    | KW_TYPE KW_ENDTYPE                                            { printTypeTable(); }
    |                                                               { printTypeTable(); }
    ;

typeDefList : typeDefList typeDef
    | typeDef
    ;

typeDef : ID                                { createNewType($1->varName, TYPE); } 
        '{' typeFieldList '}'               { setFieldsOfType($1->varName, $4); }
    ;

typeFieldList : typeFieldList typeField                             { $$ = mergeTypeFields($1, $2); }
    | typeField                                                     { $$ = $1; }
    ;

typeField : TYPE_INT ID SEMI                                        { $$ = createNewTypeField($2->varName, lookupTT("INT")); }
    | TYPE_STRING ID SEMI                                           { $$ = createNewTypeField($2->varName, lookupTT("STRING")); }
    | ID ID SEMI                                                    { $$ = createNewTypeField($2->varName, lookupTT($1->varName)); }
    ;

globalDeclBlock : KW_DECL globalDeclList KW_ENDDECL                 { printGST(); }
    | KW_DECL KW_ENDDECL                                            { printGST(); }
    ;

globalDeclList : globalDeclList globalDecl
    | globalDecl
    ;

globalDecl : type globalVarList SEMI                                { installVarsToGST($1, $2); }    
    | globalTupleDecl SEMI
    ;

globalVarList : globalVarList COMMA ID                              { $$ = mergeVars($1, createVar($3->varName, false, false, NULL, NULL)); }
    | globalVarList COMMA ID dimensionDecl                          { $$ = mergeVars($1, createVar($3->varName, false, false, NULL, $4)); }
    | globalVarList COMMA MUL ID                                    { $$ = mergeVars($1, createVar($4->varName, true, false, NULL, NULL)); }
    | globalVarList COMMA ID '(' funcDeclParamList ')'              { $$ = mergeVars($1, createVar($3->varName, false, true, $5, NULL)); }
    | ID dimensionDecl                                              { $$ = createVar($1->varName, false, false, NULL, $2); }
    | MUL ID                                                        { $$ = createVar($2->varName, true, false, NULL, NULL); }
    | ID                                                            { $$ = createVar($1->varName, false, false, NULL, NULL); }
    | ID '(' funcDeclParamList ')'                                  { $$ = createVar($1->varName, false, true, $3, NULL); }
    ;

globalTupleDecl : KW_TUPLE ID               { createNewTupleType($2->varName); } 
    '(' tupleFieldList ')'                  { setFieldsToTupleType($2->varName, $5); }
    tupleIdList                             { installVarsToGST(createTypeInfo(TUPLE, lookupTupleTypeTable($2->varName), lookupTT($2->varName), NULL), $8); }
    ;

tupleFieldList : tupleFieldList COMMA tupleField                    { $$ = mergeTupleFields($1, $3); }
    | tupleField                                                    { $$ = $1; }
    ;

tupleField : type ID                                                { $$ = createTupleField($1, $2->varName); }
    ;

tupleIdList : tupleIdList COMMA ID                                  { $$ = mergeVars($1, createVar($3->varName, false, false, NULL, NULL)); }
    | tupleIdList COMMA MUL ID                                      { $$ = mergeVars($1, createVar($4->varName, true, false, NULL, NULL)); }
    | MUL ID                                                        { $$ = createVar($2->varName, true, false, NULL, NULL); }
    | ID                                                            { $$ = createVar($1->varName, false, false, NULL, NULL); }
    ;

funcDeclParamList : funcDeclParamList COMMA funcDeclParam           { $$ = mergeParams($1, $3); }
    | funcDeclParam                                                 { $$ = $1; }
    |                                                               { $$ = NULL; }
    ;

funcDeclParam : type ID                                             { $$ = createParam($1, $2->varName, false); }
    | type MUL ID                                                   { $$ = createParam($1, $3->varName, true); }
    ;

type : TYPE_INT                                 { $$ = createTypeInfo(INT, NULL, lookupTT("INT"), NULL); }
    | TYPE_STRING                               { $$ = createTypeInfo(STRING, NULL, lookupTT("STRING"), NULL); }
    | KW_TUPLE ID                               { $$ = createTypeInfo(TUPLE, lookupTupleTypeTable($2->varName), NULL, NULL); }
    | TYPE_VOID                                 { $$ = createTypeInfo(VOID, NULL, lookupTT("VOID"), NULL); }
    | ID                                        { $$ = createTypeInfo(UNKNOWN, NULL, lookupTT($1->varName), lookupCT($1->varName)); }
    ;

funcDefBlock : funcDefBlock funcDef                                 { $$ = createConnectorNode($1, $2); }   
    | funcDef                                                       { $$ = $1; }
    ;

funcDef : type ID                               { currentFunction = lookupGST($2->varName); }
    '(' paramList ')' 
    '{' localDeclBlock body '}'                 { checkFunctionSignature($1, $2->varName, $5);
                                                  generateFunctionCode(currentFunction->functionLabel, $9);
                                                  freeLocalSymbolTable();
                                                }
    ;

body : KW_BEGIN stmtList KW_END                                     { $$ = $2; }
    ;

paramList : paramList COMMA param                                   { $$ = mergeParams($1, $3); }
    | param                                                         { $$ = $1; }
    |                                                               { $$ = NULL; }
    ;

param : type ID                                         { $$ = createParam($1, $2->varName, false); 
                                                            installToLST($1, $2->varName, false, true, NULL); 
                                                        }
    | type MUL ID                                       { $$ = createParam($1, $3->varName, true); 
                                                            installToLST($1, $3->varName, true, true, NULL); 
                                                        }
    ;

localDeclBlock : KW_DECL localDeclList KW_ENDDECL                   { printLST(); }
    | KW_DECL KW_ENDDECL                                            { printLST(); }
    |                                                               { printLST(); }
    ;

localDeclList : localDeclList localDecl
    | localDecl
    | localDeclList localTupleDecl
    | localTupleDecl
    ;

localDecl : type idList SEMI                            { installVarsToLST($1, $2); }
    ;

localTupleDecl : KW_TUPLE ID                            { createNewTupleType($2->varName); } 
        '(' tupleFieldList ')'                          { setFieldsToTupleType($2->varName, $5); }
        tupleIdList SEMI                                { installVarsToLST(createTypeInfo(TUPLE, lookupTupleTypeTable($2->varName), lookupTT($2->varName), NULL), $8); }
    ;

idList : idList COMMA ID                                            { $$ = mergeVars($1, createVar($3->varName, false, false, NULL, NULL)); }
    | idList COMMA MUL ID                                           { $$ = mergeVars($1, createVar($4->varName, true, false, NULL, NULL)); }
    | ID                                                            { $$ = createVar($1->varName, false, false, NULL, NULL); }
    | MUL ID                                                        { $$ = createVar($2->varName, true, false, NULL, NULL); }
    ;

dimensionDecl : dimensionDecl '[' NUM ']'                           { $$ = mergeDimensions($1, createDimension($3->numVal)); }
    | '[' NUM ']'                                                   { $$ = createDimension($2->numVal); }
    ;

mainBlock : TYPE_INT MAIN '(' ')' '{' localDeclBlock body '}'       { generateMainCode($7); 
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
    | newStmt SEMI                                                  { $$ = $1; }
    | methodCall SEMI                                               { $$ = $1; }
    ;

newStmt : ID ASSIGN KW_NEW '(' ID ')'                               { $$ = createNewNode($1, $5); }
    | fieldAccess ASSIGN KW_NEW '(' ID ')'                                 { $$ = createNewNode($1, $5); }
    ;

initStmt : KW_INIT '(' ')'                                { $$ = createInitNode(); }
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

fieldAccess : fieldAccess DOT ID                                    { $$ = createMemberAccessNode($1, $3, ACCESS_DOT, false, NULL); }
    | ID dimensionUsage DOT ID                                      { $$ = createMemberAccessNode(createArrayAccessNode($1, $2), $4, ACCESS_DOT, false, NULL); }
    | ID DOT ID                                                     { $$ = createMemberAccessNode($1, $3, ACCESS_DOT, false, NULL); }
    | ID ARROW ID                                                   { $$ = createMemberAccessNode($1, $3, ACCESS_ARROW, false, NULL); }
    | methodCall
    ;

methodCall : ID DOT ID '(' argList ')'                              { $$ = createMemberAccessNode($1, $3, ACCESS_DOT, true, $5); }
    | fieldAccess DOT ID '(' argList ')'                            { $$ = createMemberAccessNode($1, $3, ACCESS_DOT, true, $5); }
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
    | KW_INIT '('')'                                                { $$ = createInitNode(); }
    ;

funcCall : ID '(' argList ')'                                       { $$ = createFunctionCallNode($1, $3); }
    ;

argList : argList COMMA expr                                        { $$ = createConnectorNode($1, $3); }
    | expr                                                          { $$ = $1; }
    |                                                               { $$ = NULL; }
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

void segFaultHandler(int sigNum) {
    printf("SEGMENTATION FAULT!!\n");
    printf("current line number is: %d\n", lineNumber);
    printf("current character is: %s\n", yytext);
    if (currentFunction) {
        printf("current expl function was %s\n", currentFunction->name);
    }
    exit(FAILURE);
}

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

    if (signal(SIGSEGV, segFaultHandler) == SIG_ERR) {
        printf("Error registering signal handler\n");
        return FAILURE;
    }

    return yyparse();
}