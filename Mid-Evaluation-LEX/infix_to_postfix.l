%{
#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char c){ stack[++top] = c; }
char pop(){ return stack[top--]; }
char peek(){ return stack[top]; }

int precedence(char c)
{
    if(c=='+' || c=='-') return 1;
    if(c=='*' || c=='/') return 2;
    return 0;
}
%}

%%

[0-9a-zA-Z]   { printf("%s", yytext); }

[+\-*/] {
    while(top!=-1 && precedence(peek()) >= precedence(yytext[0]))
        printf("%c", pop());
    push(yytext[0]);
}

\n {
    while(top!=-1) printf("%c", pop());
    printf("\n");
}

%%

int main()
{
    printf("Enter infix expression:\n");
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}
