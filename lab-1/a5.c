#include<stdio.h>

int main(){
    int n;
    printf("enter the number:");
    scanf("%d",&n);
    if (n%4==0 || n%100==0 && n%400==0)
    {
        printf("leap year");
    }else
    {
        printf("not leap year");
    }
    
    
    return 0;
}