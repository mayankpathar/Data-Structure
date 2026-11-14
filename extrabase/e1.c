// WAP to find a factorial of a given integer (iterative and recursive)
#include<stdio.h>

int main(){
    int n,i;
    printf("enter the factorial  number :");
    scanf("%d",&n);
    int fact=1;
    for ( i = 1; i <= n; i++)
    {
        fact=fact*i;
    }
    printf("%d",fact);
    

    return 0;
}