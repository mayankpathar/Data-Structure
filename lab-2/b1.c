#include<stdio.h>

int main(){
    int n,f=1;
    printf("enter the number:");
    scanf("%d",&n);
    while (n>0)
    {
        f=f*n;
        n--;
    }
    printf("factorial is %d",f);
    return 0;
}

        
    

