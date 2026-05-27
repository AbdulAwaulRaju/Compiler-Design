#include <stdio.h>
#include <string.h>

#define MAX 100

void displayStack(char stack[], int top)
{
    for (int i = 0; i <= top; i++)
        printf("%c", stack[i]);
    printf("\t");
}

void displayInput(char input[], int pos)
{
    for (int i = pos; i < strlen(input); i++)
        printf("%c", input[i]);
    printf("\n");
}

int main()
{
    char stack[MAX], input[MAX];
    int top = -1, pos = 0;

    strcpy(input, "abba$");   // input string
    stack[++top] = '$';
    stack[++top] = 'A';       // start symbol

    printf("Stack\tInput\n");
    printf("-----\t-----\n");

    while (top >= 0)
    {
        displayStack(stack, top);
        displayInput(input, pos);

        char topSymbol = stack[top];
        char currInput = input[pos];

        // match case
        if (topSymbol == currInput)
        {
            top--;
            pos++;
        }

        // A → aCa
        else if (topSymbol == 'A' && currInput == 'a')
        {
            top--;
            stack[++top] = 'a';
            stack[++top] = 'C';
            stack[++top] = 'a';
        }

        // C → bC
        else if (topSymbol == 'C' && currInput == 'b')
        {
            top--;
            stack[++top] = 'C';
            stack[++top] = 'b';
        }

        // C → ε
        else if (topSymbol == 'C' && (currInput == 'a' || currInput == '$'))
        {
            top--;
        }

        else
        {
            printf("Error: Invalid input or grammar rule.\n");
            return 1;
        }
    }

    if (pos == strlen(input))
        printf("Parsing successful!\n");
    else
        printf("Error: Input not fully consumed.\n");

    return 0;
}
