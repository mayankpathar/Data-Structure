#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top;

void push(char ch)
{
    stack[++top] = ch;
}

char pop()
{
    if(top == -1)
        return '\0';
    return stack[top--];
}

int main()
{
    int T, i, flag;
    char str[MAX], ch;

    scanf("%d", &T);

    while(T--)
    {
        scanf("%s", str);

        top = -1;
        flag = 1;

        for(i = 0; str[i] != '\0'; i++)
        {
            if(str[i] == '(' || str[i] == '{' || str[i] == '[')
            {
                push(str[i]);
            }
            else
            {
                if(top == -1)
                {
                    flag = 0;
                    break;
                }

                ch = pop();

                if((str[i] == ')' && ch != '(') ||
                   (str[i] == '}' && ch != '{') ||
                   (str[i] == ']' && ch != '['))
                {
                    flag = 0;
                    break;
                }
            }
        }

        if(top != -1)
            flag = 0;

        if(flag)
            printf("1\n");
        else
            printf("0\n");
    }

    return 0;
}