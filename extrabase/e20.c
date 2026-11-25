// WAP to Convert a Decimal to Octal and Vice versa.


#include <stdio.h>

int main()
{
    int n, choice, arr[20], i = 0;
    int decimal = 0, base = 1;

    printf("1. Decimal to Octal\n");
    printf("2. Octal to Decimal\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("Enter decimal number: ");
        scanf("%d", &n);

        if (n == 0)
            printf("Octal = 0");

        while (n > 0)
        {
            arr[i] = n % 8;
            i++;
            n = n / 8;
        }

        printf("Octal = ");

        for (int j = i - 1; j >= 0; j--)
            printf("%d", arr[j]);
    }
    else if (choice == 2)
    {
        printf("Enter octal number: ");
        scanf("%d", &n);

        while (n > 0)
        {
            int rem = n % 10;

            if (rem > 7)
            {
                printf("Invalid octal number");
                return 0;
            }

            decimal = decimal + rem * base;
            base = base * 8;
            n = n / 10;
        }

        printf("Decimal = %d", decimal);
    }
    else
        printf("Invalid choice");

    return 0;
}
