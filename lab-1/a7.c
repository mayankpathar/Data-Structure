#include<stdio.h>

int main(){
    int n,a,b,c;
    printf("enter the day:");
    scanf("%d",&n);
    if (n>=365)
    {
        a=n/365;
        n=n%365;
    }
    if (n>=7)
    {
        b=n/7;
        n=n%7;
    }
    else
    {
        b=0;
    }
    c=n;
    printf("year:%d week:%d day:%d",a,b,c);
    return 0;
    return 0;
}