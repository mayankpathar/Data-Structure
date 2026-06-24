#include <stdio.h>

int main()
{
    int n,i,sum=0,avg;
    printf("enter the number:");
    scanf("%d", &n);
   for ( i = 1; i <= n; i++)
    {
        sum=sum+i;

    }
    printf("sum:%d\n",sum);
    avg=sum/n;
    printf("avg:%d",avg);

    
    return 0;
}