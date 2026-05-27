#include<stdio.h>
#include<string.h>

char input[100];
int i = 0;

int E();
int EP();
int T();
int TP();
int F();

int main()
{
    printf("Recursive Descent Parsing\n");

    printf("Grammar:\n");
    printf("E -> TE'\nE' -> +TE' / epsilon\nT -> FT'\nT' -> *FT' / epsilon\nF -> (E) / a\n");

    printf("\nEnter string: ");
    gets(input);

    if(E())
    {
        if(input[i] == '\0')
            printf("String is ACCEPTED\n");
        else
            printf("String is NOT ACCEPTED\n");
    }
    else
        printf("String is NOT ACCEPTED\n");

    return 0;
}

int E()
{
    if(T())
        return EP();
    return 0;
}

int EP()
{
    if(input[i] == '+')
    {
        i++;
        if(T())
            return EP();
        return 0;
    }
    return 1;
}

int T()
{
    if(F())
        return TP();
    return 0;
}

int TP()
{
    if(input[i] == '*')
    {
        i++;
        if(F())
            return TP();
        return 0;
    }
    return 1;
}

int F()
{
    if(input[i] == '(')
    {
        i++;
        if(E())
        {
            if(input[i] == ')')
            {
                i++;
                return 1;
            }
            return 0;
        }
        return 0;
    }
    else if((input[i] >= 'a' && input[i] <= 'z') ||
            (input[i] >= 'A' && input[i] <= 'Z'))
    {
        i++;
        return 1;
    }
    return 0;
}
