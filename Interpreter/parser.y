%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdbool.h>
    
    #include "symbol_table.h"

    int yylex(void);
    int yyerror(const char *s);   

    int label = 0;

    int lookup(char *name) {
        for (int i = 0; i < symbol_count; i++)
        {
            if (strcmp(symbol_table[i].name, name) == 0)
            {
                return i;
            }
        }
        return -1;
    }

    void insert(char *name, char *type, int value) {
        int index = lookup(name);
        if (index == -1 && symbol_count < MAX_VARS){
            symbol_table[symbol_count].name = name;
            symbol_table[symbol_count].type = type;
            symbol_table[symbol_count].value = value;
            symbol_count++;
        } else if (index != -1) {
            // throw error
            printf("Error: Variable '%s' already exists in the symbol table.\n", name);
            exit(1);
        }
    }

    int getValue(char* name) {
        int index = lookup(name);
        if (index != -1) {
            return symbol_table[index].value;
        } else {
            // throw error
            printf("Error: Variable '%s' does not exist in the symbol table.\n", name);
            exit(1);
        }
    }

    void setValue(char* name, int value) {
        int index = lookup(name);
        if (index != -1) {
            symbol_table[index].value = value;
        } else {
            // throw error
            printf("Error: Variable '%s' does not exist in the symbol table.\n", name);
            exit(1);
        }
    }

    typedef struct {
        char* name;
        struct node* left;
        struct node* right;
    } node;

    node* create_node(char* name, node* left, node* right);
%}


%union {
    int value;
    char* id;
    char* str;
}

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

%token YUG_DECLARATION YUG_INT YUG_EOS 
%token YUG_IF YUG_IF_THEN YUG_ELSE
%token YUG_PRINT_INIT YUG_PRINT_END
%token <value> NUMBER
%token <id> IDENTIFIER
%token <str> STRING


%type<value> expr


%%
program: statement
       | statement program
       ;

statement: YUG_DECLARATION IDENTIFIER ASSIGN expr YUG_INT YUG_EOS { 
            insert($2, "int", $4); 
            printf("%d: INT %s = %d\n", label++, $2, $4); 
        }

         | YUG_DECLARATION IDENTIFIER YUG_INT YUG_EOS { 
            insert($2, "int", 0);
            printf("Declaration: %s\n", $2); 
        }

         | IDENTIFIER ASSIGN expr YUG_EOS { 
            setValue($1, $3);
            printf("Assignment: %s = %d\n", $1, $3);
        }
        
        | YUG_IF expr YUG_IF_THEN LBRACE statement RBRACE YUG_ELSE LBRACE statement RBRACE { 
           if ($3) {
               printf("If statement: %d\n", $3);
           } else {
               printf("Else statement\n");
           }
       }

         | YUG_IF LPARAN expr RPARAN YUG_IF_THEN LBRACE statement RBRACE { 
            if ($3) {

                printf("If statement: %d\n", $3);
            } 
        }

         | YUG_PRINT_INIT LPARAN STRING RPARAN YUG_PRINT_END YUG_EOS { 
            printf("Print statement: %s\n", $3); 
        }

         | YUG_PRINT_INIT LPARAN expr RPARAN YUG_PRINT_END YUG_EOS { 
            printf("Print statement: %d\n", $3); 
        }
         ;

expr: expr PLUS expr { printf("%d: t1 = %d + %d\n", label++, $$, $1, $3); $$ = $1 + $3; }
    | expr MINUS expr { printf("%d: %d = %d - %d\n", label++, $$, $1, $3); $$ = $1 - $3; }
    | expr MULTIPLY expr { printf("%d: %d * %d\n", label++, $1, $3); $$ = $1 * $3; }
    | expr DIVIDE expr { printf("%d: %d / %d\n", label++, $1, $3); $$ = $1 / $3; }

    | expr YUG_EQUAL expr { $$ = $1 == $3; printf("Equality: %d == %d\n", $1, $3); }
    | expr YUG_NOT_EQUAL expr { $$ = $1 != $3; printf("Not Equal: %d != %d\n", $1, $3); }

    | expr YUG_LESS expr { $$ = $1 < $3; printf("Less: %d < %d\n", $1, $3); }
    | expr YUG_LESS_EQUAL expr { $$ = $1 <= $3; printf("Less Equal: %d <= %d\n", $1, $3); }
    | expr YUG_GREATER expr { $$ = $1 > $3; printf("%d: %d > %d = %d\n", label++, $1, $3, $1>$3); }
    | expr YUG_GREATER_EQUAL expr { $$ = $1 >= $3; printf("Greater Equal: %d >= %d\n", $1, $3); }

    | expr YUG_OR expr { $$ = $1 || $3; printf("Logical OR: %d || %d\n", $1, $3); }
    | expr YUG_AND expr { $$ = $1 && $3; printf("Logical AND: %d && %d\n", $1, $3); }
    | expr YUG_NOT expr { $$ = !$3; printf("Logical NOT: !%d\n", $3); }

    | LPARAN expr RPARAN { $$ = $2; printf("Parentheses: (%d)\n", $2); }
    | NUMBER { $$ = $1; printf("Number: %d\n", $1); }
    | IDENTIFIER { $$ = getValue($1);  printf("Identifier: %s\n", $1);  }
    ;
%%

int main() {
    return yyparse();
}

int yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
    return 0;
}

node *create_node(char *name, node *left, node *right) {
    node *newnode = (node*)malloc(sizeof(node));
    char* newstr = (char*)malloc(strlen(name) + 1);
    strcpy(newstr, name);
    node->name = newstr;
    node->left = left;
    node->right = right;
    return newnode;
}