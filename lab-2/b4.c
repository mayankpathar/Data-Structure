#include<stdio.h>

int main(){
    int n;
    printf("enter the number:");
    scanf("%d",&n);
    printf("factors of %d are: ",n);
    for (int i = 1; i <= n; i++)    
    {    
        if (n % i == 0)    
        {    
            printf("%d ",i);    
        }    
    }

    return 0;
}
