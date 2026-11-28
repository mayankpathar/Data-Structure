// WAP to find weather given number is Automorphic or not.
// An automorphic number is a number whose square ends with the same digits as the number
// itself.
// For example, 5 is automorphic because 5² = 25, which ends in 5.
// Similarly, 76 is automorphic because 76² = 5776, which ends in 76.
#include <stdio.h>

int main()
{
     int n, square, temp, digits = 0;
    int divisor = 1,right;
    printf("Enter a number: ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("Not a Automorphic Number");
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

    right = square % divisor;
    if (right==n){
        printf("Automorphic Number");
    }else
    {
        printf("Not a Automorphic Number");
    }
    
    
    return 0;
}