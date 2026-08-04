// Write a program to implement Selection Sort using Array.
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
      for (int j = i+1; j <n; j++)
      {
        if (arr[i]>arr[j])
        {
           temp=arr[i];
           arr[i]=arr[j];
           arr[j]=temp;

        }
        
      }
      
    }
      for (i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
    
    }
    

    return 0;
}