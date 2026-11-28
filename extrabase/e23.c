// Given an integer n, return the nth digit of the infinite integer sequence [1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
// 11, ...]
// Input: n = 11
// Output: 0
// Explanation: The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of
// the number 10.

#include <stdio.h>

int main()
{
    int n;
    long long digits = 1, count = 9, start = 1;

    printf("Enter n: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Invalid input");
        return 0;
    }

    while (n > digits * count)
    {
        n = n - digits * count;
        digits++;
        count = count * 10;
        start = start * 10;
    }

    long long number = start + (n - 1) / digits;
    int position = (n - 1) % digits;

    long long divisor = 1;

    for (int i = 0; i < digits - position - 1; i++)
    {
        divisor = divisor * 10;
    }

    int result = (number / divisor) % 10;

    printf("Nth digit = %d", result);

    return 0;
}
