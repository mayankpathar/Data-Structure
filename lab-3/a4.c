#include<stdio.h>

int main(){
    int n,i,j,temp;
    printf("enter the number:");
    scanf("%d",&n);
    int arr[n];
    for ( i = 0; i < n; i++)
    {
        printf("enter the element of arr: ");
        scanf("%d",&arr[i]);
    }
    for ( i = 0; i <n; i++)
    {
        for ( j = 0; j < n-i-1; j++)
        {
            if (arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
                   
        }
        
    }
    printf("sm:%d la:%d",arr[0],arr[n-1]);
    
    
    return 0;
}