// WAP to convert a Decimal number to BCD.
#include <stdio.h>

int main()
{
    int n, digit, arr[20], i = 0;

    printf("Enter decimal number: ");
    scanf("%d", &n);

    if (n == 0)
    {
        printf("BCD = 0000");
        return 0;
    }

    while (n > 0)
    {
        digit = n % 10;
        arr[i] = digit;
        i++;
        n = n / 10;
    }

    

    for (int j = i - 1; j >= 0; j--)
    {
        for (int k = 3; k >= 0; k--)
        {
            printf("%d", (arr[j] >> k) & 1);
        }
        printf(" ");
    }

    return 0;
}
