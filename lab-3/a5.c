#include<stdio.h>
//Write a program to find whether the array contains a duplicate number or not.
int main(){
     
    int n,i,j;
    printf("enter the number: ");
    scanf("%d",&n);
    int arr[n];
    for ( i = 0; i < n; i++)
    {
        printf("enter the element of arr: ");
        scanf("%d",&arr[i]);
    }
    for ( i = 0; i < n; i++)
    {
        for ( j = i+1; j < n; j++)
        {
            if (arr[i]==arr[j])
            {
                printf("array contains a duplicate number: %d",arr[j]);
                return 0;

            }
            
        }
        
    }
    printf("array does not contain any duplicate number");
    return 0;
}