// Write a program to take 2 numbers from user and find out the distance between them. (How to
// compute distance: If number is 10 and 18 then 10 in binary 1010 and 18 in binary is 10010 and
// distance is 2 means total number of bits that needs to be changed when 10 is converted into 18
// or 18 is converted into 10, do not convert the number into binarya

#include <stdio.h>

int main()
{
    int a, b, count = 0, x;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    x = a ^ b;

    while (x > 0)
    {
        if (x % 2 == 1)
        {
            count++;
        }

        x = x / 2;
    }

    printf("Distance = %d", count);

    return 0;
}
