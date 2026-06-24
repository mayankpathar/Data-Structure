#include<stdio.h>

int main(){
    int n,a,b,c;
    printf("enter the number:");
    scanf("%d",&n);
    if (n>=3600)
    {
        a=n/3600;
        n=n%3600;
    }
    if (n>=60)
    {
        b=n/60;
        n=n%60;
    }
    else
    {
        b=0;
    }
    c=n;
    printf("%d:%d:%d",a,b,c);
    return 0;
}