#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}

int main()
{
    char postfix[MAX];
    int i, a, b, result;

    printf("Enter Postfix Expression: ");
    scanf("%s", postfix);

    for (i = 0; postfix[i] != '\0'; i++)
    {
        if (postfix[i] >= '0' && postfix[i] <= '9')
        {
            push(postfix[i] - '0');
        }
        else
        {
            b = pop();
            a = pop();

            switch (postfix[i])
            {
                case '+':
                    push(a + b);
                    break;
                case '-':
                    push(a - b);
                    break;
                case '*':
                    push(a * b);
                    break;
                case '/':
                    push(a / b);
                    break;
                case '^':
                {
                    result = 1;
                    while (b > 0)
                    {
                        result *= a;
                        b--;
                    }
                    push(result);
                    break;
                }
            }
        }
    }

    printf("Result = %d\n", pop());

    return 0;
}