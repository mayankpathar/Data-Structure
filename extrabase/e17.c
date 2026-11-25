// WAP to convert a Binary to Decimal.


#include <stdio.h>

int main()
{
    int n, digit, decimal = 0, base = 1;

    printf("Enter binary number: ");
    scanf("%d", &n);

    while (n > 0)
    {
        digit = n % 10;
        decimal = decimal + digit * base;
        base = base * 2;
        n = n / 10;
    }

    printf("Decimal = %d", decimal);

    return 0;
}
