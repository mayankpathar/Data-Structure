// Print a following pattern
// *********
// *******
// *****
// ***
// *

#include <stdio.h>

int main()
{
    int i, j;

    for (i = 9; i >= 1; i -= 2)
    {
        for (j = 1; j <= i; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
