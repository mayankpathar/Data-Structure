#include <stdio.h>
#include <string.h>

#define max 100

char stack[max];
int top = -1;

void push(char ch)
{
    if(top == max - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = ch;
}

char pop()
{
    if(top == -1)
    {
        printf("Stack Underflow\n");
        return '\0';
    }
    return stack[top--];
}

void display()
{
    for(int i = 0; i <= top; i++)
    {
        printf("%c", stack[i]);
    }
    printf("\n");
}

int main()
{
    char str[max];

    printf("Enter the string: ");
    scanf("%s", str);

    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == '*')
        {
            pop();
        }
        else
        {
            push(str[i]);
        }
    }

    display();

    
}