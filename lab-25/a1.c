// Write a program to implement Bubble using Array.
#include <stdio.h>

int main()
{
    int n, i,temp;
    printf("enter the arr size: ");
    scanf("%d", &n);
    int arr[n];

    for (i = 0; i < n; i++)
    {
        printf("enter the arr element: ");
        scanf("%d", &arr[i]);
    }
    for ( i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (arr[j]>arr[j+1])
            {
             temp=arr[j];
             arr[j]=arr[j+1];
             arr[j+1]=temp;
    
            }
            
        }
      
    }
      for (i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
    
    }
    

    return 0;
}