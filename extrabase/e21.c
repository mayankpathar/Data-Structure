// WAP to Convert a Decimal to Hexa-decimal and vice versa.

#include <stdio.h>

int main()
{
    int n, choice, arr[20], i = 0;
    int decimal = 0, rem;

    printf("1. Decimal to Hexadecimal\n");
    printf("2. Hexadecimal to Decimal\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("Enter decimal number: ");
        scanf("%d", &n);

        if (n == 0)
            printf("Hexadecimal = 0");

        while (n > 0)
        {
            arr[i] = n % 16;
            i++;
            n = n / 16;
        }

        printf("Hexadecimal = ");

        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] < 10)
                printf("%d", arr[j]);
            else
                printf("%c", arr[j] - 10 + 'A');
        }
    }
    else if (choice == 2)
    {
        char hex[20];

        printf("Enter hexadecimal number: ");
        scanf("%s", hex);

        for (int j = 0; hex[j] != '\0'; j++)
        {
            if (hex[j] >= '0' && hex[j] <= '9')
                rem = hex[j] - '0';
            else if (hex[j] >= 'A' && hex[j] <= 'F')
                rem = hex[j] - 'A' + 10;
            else if (hex[j] >= 'a' && hex[j] <= 'f')
                rem = hex[j] - 'a' + 10;
            else
            {
                printf("Invalid hexadecimal number");
                return 0;
            }

            decimal = decimal * 16 + rem;
        }

        printf("Decimal = %d", decimal);
    }
    else
        printf("Invalid choice");

    return 0;
}
