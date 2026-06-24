#include<stdio.h>

int main(){
    int n=1,a,b;
    printf("enter the number a and b:");
    scanf("%d %d",&a,&b);
    while(b>0){
        n=n*a;
        b--;
    }
   printf("%d",n);
    return 0;
}