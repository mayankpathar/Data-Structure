// WAP to find a prime number between range (range should be entered by user).
#include <stdio.h>

int main()
{
    int s, e, i, flag = 0;
    printf("Enter a start number of rang: ");
    scanf("%d", &s);
    printf("Enter a end number of rang: ");
    scanf("%d", &e);
    for (i = s; i < e; i++)
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
        flag = 0;
    }

    return 0;
}