
#include <stdio.h>

int main()
{
    int n = 4;

    for (int i = 0; i < 2 * n - 1; i++)
    {
        for (int j = 0; j < 2 * n - 1; j++)
        {
            int a = i;
            int b = j;

            if (i > 2 * n - 2 - i)
                a = 2 * n - 2 - i;

            if (j > 2 * n - 2 - j)
                b = 2 * n - 2 - j;

            if (a < b)
                printf("%d ", n - a);
            else
                printf("%d ", n - b);
        }

        printf("\n");
    }

    return 0;
}
