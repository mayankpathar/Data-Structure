#include <stdio.h>

#define MAX 1000

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

void display()
{
    int i;
    for(i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

int main()
{
    int T, N;
    scanf("%d", &T);

    while(T--)
    {
        int A[MAX], B[MAX];
        int i, j = 0;
        top = -1;

        scanf("%d", &N);

        for(i = 0; i < N; i++)
            scanf("%d", &A[i]);

        int expected = 1;
        int possible = 1;

        for(i = 0; i < N; i++)
        {
            push(A[i]);

            while(top != -1 && stack[top] == expected)
            {
                B[j++] = pop();
                expected++;
            }
        }

        while(top != -1)
        {
            if(stack[top] == expected)
            {
                B[j++] = pop();
                expected++;
            }
            else
            {
                possible = 0;
                break;
            }
        }

        if(possible)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}