%{
#include <stdio.h>
%}

%%

"int"|"float"|"if"|"else"|"while"|"for"|"return"
        { printf("%s is keyword\n", yytext); }

[a-zA-Z_][a-zA-Z0-9_]*  
        { printf("%s is not keyword\n", yytext); }

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
