// WAP to find a power a^b (without using power and multiplication operation)

#include <stdio.h>

int main()
{
    int a, b, result = 1;

    printf("Enter the base: ");
    scanf("%d", &a);

    printf("Enter the power: ");
    scanf("%d", &b);

    for (int i = 1; i <= b; i++)
    {
        int sum = 0;

        for (int j = 1; j <= a; j++)
        {
            sum = sum + result;
        }

        result = sum;
    }

    printf("Answer = %d", result);

    return 0;
}
