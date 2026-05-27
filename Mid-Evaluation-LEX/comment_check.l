%{
#include <stdio.h>
%}

%%

"//".*   { printf("Single line comment\n"); }

"/*"([^*]|\*+[^*/])*\*+"/"   { printf("Multi line comment\n"); }

.*       { printf("Not a comment\n"); }

%%

int main()
{
    printf("Enter line:\n");
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}
