
#include <stdio.h>

int main()
{
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("%d", 2 * j - 1);

            if (j < i)
                printf(" * ");
        }

        for (int j = i - 1; j >= 1; j--)
        {
            printf(" * %d", 2 * j - 1);
        }

        printf("\n");
    }

    return 0;
}
