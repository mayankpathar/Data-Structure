#include<stdio.h>

int main(){
    int n;
    printf("enter the number:");
    scanf("%d",&n);
    int temp = 0;
    while (n != 0)
    {
        temp = temp * 10 + n % 10;
        n = n / 10;
    }
    printf("revers number %d",temp);
    return 0;
}