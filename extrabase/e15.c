// WAP for following Scenario.
// Given n rupees and a chocolate price of m for each chocolate, with a wrapper exchange offer of 1
// chocolate per k wrappers, calculate the total number of chocolates you can eat with n rupees.

#include <stdio.h>

int main()
{
    int n, m, k;
    int chocolates, wrappers;

    printf("Enter total rupees: ");
    scanf("%d", &n);

    printf("Enter chocolate price: ");
    scanf("%d", &m);

    printf("Enter wrapper exchange limit: ");
    scanf("%d", &k);

    if (n < 0 || m <= 0 || k <= 1)
    {
        printf("Invalid input");
        return 0;
    }

    chocolates = n / m;
    wrappers = chocolates;

    while (wrappers >= k)
    {
        int newChocolates = wrappers / k;

        chocolates = chocolates + newChocolates;

        wrappers = wrappers % k + newChocolates;
    }

    printf("Total chocolates = %d", chocolates);

    return 0;
}
