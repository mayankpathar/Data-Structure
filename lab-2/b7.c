#include<stdio.h>

int main(){
    int n,a=0,sum=0;
    printf("enter the number:");
    scanf("%d", &n);
    for (int i = 1; i <=n; i++)
    {
        printf("(%d+%d)+",a,i);
        a=a+i;
        
        sum=sum+a;
        
    }
    printf(":");
    printf("%d",sum);
    
    return 0;
}