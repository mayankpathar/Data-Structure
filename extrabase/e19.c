// WAP to convert a hexa-decimal to Octal.


#include <stdio.h>

int main()
{
    int decimal = 0, rem, base = 1;
    int arr[20], i = 0;
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

    while (decimal > 0)
    {
        arr[i] = decimal % 8;
        i++;
        decimal = decimal / 8;
    }

    printf("Octal = ");

    if (i == 0)
        printf("0");

    for (int j = i - 1; j >= 0; j--)
        printf("%d", arr[j]);

    return 0;
}
