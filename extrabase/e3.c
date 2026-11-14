// WAP to find a total odd and total even digit of a given number.
#include <stdio.h>

int main()
{
    int n, rem, odd = 0, even = 0;

    printf("Enter a number: ");
    scanf("%d", &n);
    while (n>0)
    {
        rem=n%10;

        if (rem%2==0)
        {
           even++;
        }
        else
        {
            odd++;
        }
        
        n=n/10;
           
    }
    printf("Total Even Digits = %d\n", even);
    printf("Total Odd Digits = %d", odd);
    
    
    return 0;
}