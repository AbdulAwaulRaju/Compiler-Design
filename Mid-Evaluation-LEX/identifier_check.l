%{
#include <stdio.h>
#include <ctype.h>
%}

%%

[a-zA-Z_][a-zA-Z0-9_]*   { printf("%s is valid identifier\n", yytext); }

[0-9]+                   { printf("%s is invalid identifier\n", yytext); }

.                        ;

%%

int main()
{
    printf("Enter input:\n");
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}
