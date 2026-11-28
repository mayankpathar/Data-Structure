// WAP to find weather given number is Kaprekar or not.
// A Kaprekar number is a non-negative integer that, when squared, can be split into two parts
// whose sum equals the original number.
// For E.g. 45 is a Kaprekar number because 45 squared (2025) can be split into 20 and 25, and 20 +
// 25 = 45.

#include <stdio.h>

int main()
{
    int n, square, temp, digits = 0;
    int divisor = 1, left, right;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("Not a Kaprekar Number");
        return 0;
    }

    square = n * n;
    temp = n;

    if (n == 0)
        digits = 1;

    while (temp > 0)
    {
        digits++;
        temp = temp / 10;
    }

    for (int i = 1; i <= digits; i++)
    {
        divisor = divisor * 10;
    }

    left = square / divisor;
    right = square % divisor;

    if (left + right == n)
    {
        printf("Kaprekar Number");
    }
    else
    {
        printf("Not a Kaprekar Number");
    }
    printf("%d %d",left,right);
    return 0;
}
