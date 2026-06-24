#include <stdio.h>

int main()
{
    int n, flag = 0;
    printf("enter the number:");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 2; j < i - 1; j++)
        {
            if (i % j == 0)
            {
                flag = 1;
            }
        }
        if (flag == 0)
        {
            printf("prime:%d", i);
        }
        flag=0;
    }

    return 0;
}