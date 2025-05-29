%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdbool.h>

    int yylex(void);
    int yyerror(const char *s);

    #define MAX_VARS 100
    typedef struct
    {
        char *type;
        char *name;
        int value;
        char *str;
    } symbol;

    symbol symbolTable[MAX_VARS];

    int symbol_count = 0;

    // Symbol table function;
    int lookup(char *name);                                    // for loocking for a variable
    void insert(char *name, char *type, int value, char *str); // for inserting a variable
    int getIntValue(char *name);                               // for getting the value of a variable
    char* getStringValue(char *name);                          // for getting the value of a variable
    void setValue(char *name, int value, char *str);           // for setting the value of a variable

    // AST
    #include "AST.h"

    // Evaluation function
    int eval_expr(ASTNode * node);
    void eval(ASTNode * node);

%}

%union {
    int value;
    char *id;
    char *str;
    struct ASTNode *node;
};

%right ASSIGN 
%left YUG_OR 
%left YUG_AND 
%left YUG_EQUAL YUG_NOT_EQUAL 
%left YUG_LESS YUG_LESS_EQUAL YUG_GREATER YUG_GREATER_EQUAL 
%nonassoc YUG_IF 
%nonassoc YUG_ELSE 
%left PLUS MINUS 
%left MULTIPLY DIVIDE 
%right YUG_NOT 
%left LPARAN RPARAN

%token PLUS MINUS MULTIPLY DIVIDE LPARAN RPARAN LBRACE RBRACE ASSIGN 
%token YUG_EQUAL YUG_NOT_EQUAL YUG_LESS YUG_LESS_EQUAL YUG_GREATER YUG_GREATER_EQUAL YUG_AND YUG_OR YUG_NOT
%token YUG_DECLARATION YUG_INT YUG_EOS YUG_STR 
%token YUG_IF YUG_IF_THEN YUG_ELSE 
%token YUG_KO YUG_SE YUG_TAK 
%token YUG_INIT YUG_PRINT_END 

%token<value> NUMBER 
%token<id> IDENTIFIER 
%token<str> STRING

%type<node> assign 
%type<node> ifstatement 
%type<node> forstatement 
%type<node> blockstatement 
%type<node> body 
%type<node> printstatement 
%type<node> expr


%%
program : statement 
        | program statement;

statement : assign { eval($1); }
        | ifstatement { eval($1); }
        | forstatement { eval($1); }
        | printstatement { eval($1); };

assign : YUG_DECLARATION IDENTIFIER ASSIGN expr YUG_INT YUG_EOS { $$ = makeVarDeclNode("int", makeIDNode(strdup($2)), $4); }

        | YUG_DECLARATION IDENTIFIER ASSIGN STRING YUG_STR YUG_EOS { 
                $$ = makeVarDeclNode("string", makeIDNode(strdup($2)), makeStringLiteralNode(strdup($4)));
            }

        | IDENTIFIER ASSIGN expr YUG_EOS {
                if (lookup($1) != -1) {
                    $$ = makeAssignNode("int", makeIDNode(strdup($1)), $3);
                } else {
                    printf("Error: Variable \'%s\' is not declared.....\n", $1);
                    exit(1);
                }
            }

        | IDENTIFIER ASSIGN STRING YUG_EOS {
                if (lookup($1) != -1) {
                    $$ = makeAssignNode("string", makeIDNode(strdup($1)), makeStringLiteralNode(strdup($3)));
                } else {
                    printf("Error: Variable \'%s\' is not declared.....\n", $1);
                    exit(1);
                }
            };

ifstatement : YUG_IF expr YUG_IF_THEN LBRACE blockstatement RBRACE { $$ = makeIfNode($2, $5, NULL); }
        | YUG_IF expr YUG_IF_THEN LBRACE blockstatement RBRACE YUG_ELSE LBRACE blockstatement RBRACE {
                $$ = makeIfNode($2, $5, $9);
            };

forstatement : YUG_INIT IDENTIFIER YUG_KO expr YUG_SE expr YUG_TAK YUG_EOS LBRACE blockstatement RBRACE { 
                $$ = makeForNode(makeIDNode(strdup($2)), $4, $6, $10); 
            }
        | YUG_INIT IDENTIFIER YUG_KO expr YUG_TAK YUG_EOS LBRACE blockstatement RBRACE {
                int idx = lookup($2);
                if (idx != -1) {
                    $$ = makeForNode(makeIDNode(strdup($2)), makeLiteralNode(symbolTable[idx].value), $4, $8);                    
                } else {
                    printf("Error: Variable \'%s\' is not declared.....\n", $2);
                    exit(1);
                }
            }
            
            ;

blockstatement : body { $$ = makeBlockNode($1); };

body : body assign { $$ = makeBodyNode($1, $2); }
        | body ifstatement { $$ = makeBodyNode($1, $2); }
        | body forstatement { $$ = makeBodyNode($1, $2); }
        | body printstatement { $$ = makeBodyNode($1, $2); }
        | assign { $$ = makeBodyNode(NULL, $1); }
        | ifstatement { $$ = makeBodyNode(NULL, $1); }
        | printstatement { $$ = makeBodyNode(NULL, $1); }
        | forstatement { $$ = makeBodyNode(NULL, $1); }
        ;
        

printstatement : YUG_INIT STRING YUG_PRINT_END YUG_EOS { $$ = makePrintNode(makeStringLiteralNode(strdup($2))); }
        | YUG_INIT expr YUG_PRINT_END YUG_EOS { $$ = makePrintNode($2); };

expr : expr PLUS expr { $$ = makeBinExprNode($1, PLUS, $3); }
        | expr MINUS expr { $$ = makeBinExprNode($1, MINUS, $3); }
        | expr MULTIPLY expr { $$ = makeBinExprNode($1, MULTIPLY, $3); }
        | expr DIVIDE expr { $$ = makeBinExprNode($1, DIVIDE, $3); }

        | expr YUG_EQUAL expr { $$ = makeBinExprNode($1, YUG_EQUAL, $3); }
        | expr YUG_NOT_EQUAL expr { $$ = makeBinExprNode($1, YUG_NOT_EQUAL, $3); }

        | expr YUG_LESS expr { $$ = makeBinExprNode($1, YUG_LESS, $3); }
        | expr YUG_LESS_EQUAL expr { $$ = makeBinExprNode($1, YUG_LESS_EQUAL, $3); }
        | expr YUG_GREATER expr { $$ = makeBinExprNode($1, YUG_GREATER, $3); }
        | expr YUG_GREATER_EQUAL expr { $$ = makeBinExprNode($1, YUG_GREATER_EQUAL, $3); }

        | expr YUG_OR expr { $$ = makeBinExprNode($1, YUG_OR, $3); }
        | expr YUG_AND expr { $$ = makeBinExprNode($1, YUG_AND, $3); }
        | expr YUG_NOT expr { $$ = makeBinExprNode($1, YUG_NOT, $3); }

        | LPARAN expr RPARAN { $$ = $2; }

        | NUMBER { $$ = makeLiteralNode($1); }
        | IDENTIFIER { $$ = makeIDNode($1); };
%%

int main() {
    return yyparse();
}

int yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
    return 0;
}

// Symbol Table function
int lookup(char *name) {
    for (int i = 0; i < symbol_count; i++)  {
        if (strcmp(symbolTable[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void insert(char *name, char *type, int value, char *str) {
    int idx = lookup(name);
    if (idx == -1 && symbol_count < MAX_VARS) {
        symbolTable[symbol_count].name = name;
        symbolTable[symbol_count].type = type;
        symbolTable[symbol_count].value = value;
        symbolTable[symbol_count].str = str;
        symbol_count++;
    }
    else if (idx != -1) {
        // throw error
        printf("ErrorInserting: Variable \'%s\' already declared.....\n", name);
        exit(1);
    }
}

int getIntValue(char *name) {
    int index = lookup(name);
    if (index != -1) {
        return symbolTable[index].value;
    }
    else {
        // throw error
        printf("ErrorGetting: Variable \'%s\' is not declared.....\n", name);
        exit(1);
    }
}

char *getStringValue(char *name) {
    int index = lookup(name);
    if (index != -1) {
        return symbolTable[index].str;
    } else {
        // throw error
        printf("ErrorGetting: Variable \'%s\' is not declared.....\n", name);
        exit(1);
    }
}

void setValue(char *name, int value, char *str) {
    int index = lookup(name);
    if (index != -1) {
        if (str == NULL && symbolTable[index].type == "int") { 
            symbolTable[index].value = value;
        } else if (str && symbolTable[index].type == "string") {
            symbolTable[index].str = str;
        } else {
            printf("ErrorSetting: Variable \'%s\' is not declared.....\n", name);
            exit(1);
        }
    } else {
        printf("ErrorSetting: Variable \'%s\' is not declared.....\n", name);
    }
}

// AST Functions
ASTNode *makeLiteralNode(int value) {
    ASTNode *newNode = (ASTNode *)malloc(sizeof(ASTNode));
    newNode->type = Literal;
    newNode->Literal.value = value;
    return newNode;
}

ASTNode *makeStringLiteralNode(char *value) {
    ASTNode *newNode = (ASTNode *)malloc(sizeof(ASTNode));
    newNode->type = StringLiteral;
    newNode->StringLiteral.value = value;
    return newNode;
}

ASTNode *makeIDNode(char *value) {
    ASTNode *newNode = (ASTNode *)malloc(sizeof(ASTNode));
    newNode->type = Identifier;
    newNode->Identifier.value = value;
    return newNode;
}

ASTNode *makeBinExprNode(ASTNode *left, int op, ASTNode *right) {
    ASTNode *newNode = (ASTNode *)malloc(sizeof(ASTNode));
    newNode->type = BinaryExpression;
    newNode->BinaryExpression.left = left;
    newNode->BinaryExpression.op = op;
    newNode->BinaryExpression.right = right;
    return newNode;
}

ASTNode *makeVarDeclNode(char *type, ASTNode *id, ASTNode *init) {
    ASTNode *newNode = (ASTNode *)malloc(sizeof(ASTNode));
    newNode->type = VariableDeclaration;
    newNode->VariableDeclaration.type = type;
    newNode->VariableDeclaration.id = id;
    newNode->VariableDeclaration.init = init;
    return newNode;
}

ASTNode *makeAssignNode(char *type, ASTNode *id, ASTNode *value) {
    ASTNode *newNode = (ASTNode *)malloc(sizeof(ASTNode));
    newNode->type = Assignment;
    newNode->Assignment.type = type;
    newNode->Assignment.id = id;
    newNode->Assignment.value = value;
    return newNode;
}

ASTNode *makeIfNode(ASTNode *test, ASTNode *consequent, ASTNode *alternate) {
    ASTNode *newNode = (ASTNode *)malloc(sizeof(ASTNode));
    newNode->type = IfStatement;
    newNode->IfStatement.test = test;
    newNode->IfStatement.consequent = consequent;
    newNode->IfStatement.alternate = alternate;
    return newNode;
}

ASTNode *makeBlockNode(ASTNode *body) {
    ASTNode *newNode = (ASTNode *)malloc(sizeof(ASTNode));
    newNode->type = BlockStatement;
    newNode->BlockStatement.body = body;
    return newNode;
}

ASTNode *makeBodyNode(ASTNode *insideBody, ASTNode *value) {
    ASTNode *newNode = (ASTNode *)malloc(sizeof(ASTNode));
    newNode->type = Body;
    newNode->Body.InsideBody = insideBody;
    newNode->Body.value = value;
    return newNode;
}

ASTNode *makePrintNode(ASTNode *value) {
    ASTNode *newNode = (ASTNode *)malloc(sizeof(ASTNode));
    newNode->type = PrintStatement;
    newNode->PrintStatement.value = value;
    return newNode;
}

ASTNode *makeForNode(ASTNode *id, ASTNode *start, ASTNode *end, ASTNode *body) {
    ASTNode *newNode = (ASTNode *)malloc(sizeof(ASTNode));
    newNode->type = ForStatement;
    newNode->ForStatement.id = id;
    newNode->ForStatement.start = start;
    newNode->ForStatement.end = end;
    newNode->ForStatement.body = body;
}

void eval(ASTNode *node) {
    if (node == NULL)
        return;
    int expr_value;
    char *id_value;
    switch (node->type) {
        case VariableDeclaration:
            id_value = node->VariableDeclaration.id->Identifier.value;
            if (node->VariableDeclaration.type == "int") {
                expr_value = eval_expr(node->VariableDeclaration.init);
                insert(id_value, node->VariableDeclaration.type, expr_value, NULL);
            } else if (node->VariableDeclaration.type == "string") {
                char* str_value = node->VariableDeclaration.init->StringLiteral.value;
                insert(id_value, node->VariableDeclaration.type, -999, str_value);
            }
            // printf("%s %s %d\n", node->VariableDeclaration.type, id_value, expr_value);)
            break;

        case Assignment:
            id_value = node->Assignment.id->Identifier.value;
            int idx = lookup(id_value);
            if (node->Assignment.type == symbolTable[idx].type) {
                if (symbolTable[idx].type == "int") {
                    expr_value = eval_expr(node->Assignment.value);
                    setValue(id_value, expr_value, NULL);
                } else if (symbolTable[idx].type == "string"){
                    setValue(id_value, -999, getStringValue(id_value));
                }
            } else {
                exit(1);
            }
            // printf("%s %d\n",id_value, expr_value);
            break;

        case PrintStatement:
            if (node->PrintStatement.value->type == Identifier) {
                char* id = node->PrintStatement.value->Identifier.value;
                int idx = lookup(id);
                if ( idx == -1 ) {
                    printf("Error: Variable \'%s\' is not declared.....\n", id);
                    exit(1);
                }
                if ( symbolTable[idx].type == "int" ) {
                    printf("%d\n", getIntValue(id));
                } else if ( symbolTable[idx].type == "string" ) {
                    printf("%s\n", getStringValue(id));
                }
            }else if (node->PrintStatement.value->type == StringLiteral) {
                    printf("%s\n", node->PrintStatement.value->StringLiteral.value);
            } else {
                int eval_val = eval_expr(node->PrintStatement.value);
                printf("%d\n", eval_val);
            }
            break;

        case IfStatement:
            if (eval_expr(node->IfStatement.test)) {
                eval(node->IfStatement.consequent);
            } else {
                eval(node->IfStatement.alternate);
            }
            break;

        case ForStatement:
            char* id = node->ForStatement.id->Identifier.value;
            int i = node->ForStatement.start->Literal.value;
            bool inST = false;
            if(lookup(id) != -1) {
                inST = true;                
            }
            // if (lookup(id) == -1) {
            //     // printf("hello\n");
            //     i = node->ForStatement.start->Literal.value;
            //     insert(id, "int", i, NULL);
            // } else {
            //     // printf("world");
            //     inST = true;
            //     i = getIntValue(id);
            // }

            insert(id, "int", i, NULL);
            int end = node->ForStatement.end->Literal.value;
            // printf("No way.....%d\t%d\n", i, end);


            for (; i < end; i++) {
                setValue(node->ForStatement.id->Identifier.value, i, NULL);
                eval(node->ForStatement.body);
            }

            if (inST) {
                setValue(id, i, NULL);
            } else {
                symbol_count--;
            }
            // printf("\n%d\n", lookup(node->ForStatement.id->Identifier.value));
            break;

        case BlockStatement:
            eval(node->BlockStatement.body);
            break;

        case Body:
            eval(node->Body.InsideBody);
            eval(node->Body.value);
            break;

        default:
            exit(1);
    };   
};

char* strExpr(ASTNode *node) {
    switch (node->type)
    {
    case Identifier:
        return getStringValue(node->Identifier.value);
        break;
    
    default:
        break;
    }
}

int eval_expr(ASTNode *node) {
    switch (node->type) {
        case Literal:
            return node->Literal.value;
        case Identifier:
            return getIntValue(node->Identifier.value);
        case BinaryExpression:
            int l = eval_expr(node->BinaryExpression.left);
            int r = eval_expr(node->BinaryExpression.right);
            switch (node->BinaryExpression.op) {
                case PLUS:
                    return l + r;
                case MINUS:
                    return l - r;
                case MULTIPLY:
                    return l * r;
                case DIVIDE:
                    return l / r;

                case YUG_EQUAL:
                    return l == r;
                case YUG_NOT_EQUAL:
                    return l != r;
                case YUG_GREATER:
                    return l > r;
                case YUG_GREATER_EQUAL:
                    return l >= r;
                case YUG_LESS:
                    return l < r;
                case YUG_LESS_EQUAL:
                    return l <= r;

                case YUG_AND:
                    return l && r;
                case YUG_OR:
                    return l || r;
                default:
                    exit(1);
            }

        default:
            exit(1);
    };
};
