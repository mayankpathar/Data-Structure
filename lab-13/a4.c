#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch)
{
    stack[++top] = ch;
}

char pop()
{
    return stack[top--];
}

int main()
{
    char str[MAX];
    int i = 0;

    printf("Enter the string: ");
    scanf("%s", str);

    while(str[i] == 'a')
    {
        push('a');
        i++;
    }

    if(top == -1)
    {
        printf("Invalid String");
        return 0;
    }


    while(str[i] == 'b')
    {
        if(top == -1)
        {
            printf("Invalid String");
            return 0;
        }
        pop();
        i++;
    }

    if(str[i] == '\0' && top == -1)
        printf("Valid String");
    else
        printf("Invalid String");

    return 0;
}