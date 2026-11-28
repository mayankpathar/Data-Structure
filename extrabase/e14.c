// WAP to find weather given number is Pronic or not.
// A Pronic Number is defined as a number that is the product of two consecutive non-negative
// integers. In other words, N is a Pronic Number if there exists a non-negative integer k such that N
// = k * (k + 1).
// E.g. 6 is a Pronic Number because 6=2*3

#include <stdio.h>

int main()
{
    int n, flag = 0;

    printf("Enter a number: ");
    scanf("%d", &n);

    for (int i = 0; i * (i + 1) <= n; i++)
    {
        if (i * (i + 1) == n)
        {
            flag = 1;
            break;
        }
    }

    if (flag == 1)
        printf("Pronic Number");
    else
        printf("Not a Pronic Number");

    return 0;
}
