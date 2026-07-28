#include <stdio.h>

#define MAX 1000

char stack[MAX];
int top = -1;

void push(char ch)
{
    if(top == MAX - 1)
        return;
    stack[++top] = ch;
}

char pop()
{
    if(top == -1)
        return '\0';
    return stack[top--];
}

void display()
{
    for(int i = 0; i <= top; i++)
        printf("%c", stack[i]);
    printf("\n");
}

int isVowel(char ch)
{
    return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u');
}

int main()
{
    int T, n;
    char s[1001];

    scanf("%d", &T);

    while(T--)
    {
        scanf("%d", &n);
        scanf("%s", s);

        top = -1;

        for(int i = 0; i < n; i++)
        {
            if(isVowel(s[i]))
            {
                char temp[MAX];
                int k = 0;

                while(top != -1)
                    temp[k++] = pop();

                for(int j = 0; j < k; j++)
                    push(temp[j]);
            }

            push(s[i]);
        }

        display();
    }

    return 0;
}