// WAP to find a quotient and reminder of 2 number (bigger number should be divided by lower
// number) and you are not allowed to use a division and quotient operator

#include <stdio.h>

int main()
{
    int a, b, temp, quo = 0, rem;

    printf("Enter first number: ");
    scanf("%d", &a);

    printf("Enter second number: ");
    scanf("%d", &b);

    if (a < 0 || b <= 0)
    {
        printf("Enter positive numbers");
        return 0;
    }

    if (a < b)
    {
        temp = a;
        a = b;
        b = temp;
    }

    rem = a;

    while (rem >= b)
    {
        rem = rem - b;
        quo++;
    }

    printf("Quotient = %d\n", quo);
    printf("Remainder = %d", rem);

    return 0;
}
