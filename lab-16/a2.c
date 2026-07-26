#include <stdio.h>
#include <string.h>

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
    char prefix[MAX];
    int i, a, b, result;

    printf("Enter Prefix Expression: ");
    scanf("%s", prefix);

    for (i = strlen(prefix) - 1; i >= 0; i--)
    {
        if (prefix[i] >= '0' && prefix[i] <= '9')
        {
            push(prefix[i] - '0');
        }
        else
        {
            a = pop();
            b = pop();

            switch (prefix[i])
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

    printf("Result = %d\n", pop());

    return 0;
}