#include<stdio.h>

int main(){
    int n;
    printf("enter the arr size:");
    scanf("%d",&n);
    int a1[n];
    for (int i = 0; i < n; i++)
    {
        printf("enter the arr element:");
        scanf("%d",&a1[i]);
    }
    for (int j = 0; j < n; j++)
    {
        printf(" arr:%d\n",a1[j]);
       
    }
    
    return 0;
}