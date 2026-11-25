// WAP to convert an Octal into hexa-decimal.


#include <stdio.h>

int main()
{
    int n, decimal = 0, base = 1;
    int rem, arr[20], i = 0;

    printf("Enter octal number: ");
    scanf("%d", &n);

    while (n > 0)
    {
        rem = n % 10;
        decimal = decimal + rem * base;
        base = base * 8;
        n = n / 10;
    }

    while (decimal > 0)
    {
        rem = decimal % 16;
        arr[i] = rem;
        i++;
        decimal = decimal / 16;
    }

    printf("Hexadecimal = ");

    for (int j = i - 1; j >= 0; j--)
    {
        if (arr[j] < 10)
            printf("%d", arr[j]);
        else
            printf("%c", arr[j] - 10 + 'A');
    }

    return 0;
}
