// WAP to find a summation of a digit of a given number. (recursive)
#include <stdio.h>

int sum(int n)
{
    if (n == 0)
        return 0;
    else
        return (n % 10) + sum(n / 10);
}

int main()
{
    int n, ans;

    printf("Enter a number: ");
    scanf("%d", &n);

    ans = sum(n);

    printf("Sum of digits = %d", ans);

    return 0;
}