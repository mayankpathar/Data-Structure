// WAP to find whether a number is Odd or Even without using a % operator.
#include <stdio.h>

int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    if (n & 1)
    {
        printf("odd");
    }
    else
    {
        printf("even");
    }

    return 0;
}