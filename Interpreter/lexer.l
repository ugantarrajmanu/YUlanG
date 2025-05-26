%{
    #include <stdlib.h>
    #include <string.h>

    #include "y.tab.h"
%}

number       [0-9]+
identifier   [a-zA-Z_][a-zA-Z0-9]*
string       \"([^\\\"]|\\.)*\"




%%
[ \t\n]+             { /* Ignore whitespace */ }
"arey yug"          { return YUG_DECLARATION; }
"int"               { return YUG_INT; }
"yug agar"          { return YUG_IF; }
"hai to"            { return YUG_IF_THEN; }
"nahi to"           { return YUG_ELSE; }
"yug"               { return YUG_PRINT_INIT; }
"likhna"            { return YUG_PRINT_END; }
"hai"               { return YUG_EOS; }
{string}            { yylval.str = strdup(yytext); return STRING; }
{number}            { yylval.value = atoi(yytext); return NUMBER; }
{identifier}        { yylval.id = strdup(yytext); return IDENTIFIER; }

"+"                 { return PLUS; }
"-"                 { return MINUS; }
"*"                 { return MULTIPLY; }
"/"                 { return DIVIDE; }

"=="                { return YUG_EQUAL; }
"!="                { return YUG_NOT_EQUAL; }
"<"                 { return YUG_LESS; }
"<="                { return YUG_LESS_EQUAL; }
">"                 { return YUG_GREATER; }
">="                { return YUG_GREATER_EQUAL; }
"&&"                { return YUG_AND; }
"||"                { return YUG_OR; }

"="                 { return ASSIGN; }

"("                 { return LPARAN; }
")"                 { return RPARAN; }
"{"                 { return LBRACE; }
"}"                 { return RBRACE; }
%%

int yywrap() {
    return 1;
}

