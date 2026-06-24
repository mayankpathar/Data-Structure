#include<stdio.h>

int main(){
    int n,flag=0;
    printf("enter the number:");
    scanf("%d",&n);
    for (int  i = 2; i < n-1; i++)
    {
        if (n%i==0)
        {
            flag=1;
        }
        
    }
    if (flag==0)
    {
        printf("prime");
    
    }
    else
    {
        printf("not prime");
    }
    
    
    return 0;
}