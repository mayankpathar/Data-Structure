#include<stdio.h>

int main(){
    int i,m,n,sum=0;
    printf("enter the number m to n: ");
    scanf("%d %d",&m,&n);
    for ( i = m; i <= n; i++)
    {
        sum=sum+i;

    }
    printf("sum:%d",sum);

    return 0;
}