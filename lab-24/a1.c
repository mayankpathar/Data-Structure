// Write a program to implement a Linear Search using Array.
#include <stdio.h>

int main()
{
    int n, i,m;
    printf("enter the arr size: ");
    scanf("%d", &n);
    int arr[n];

    for (i = 0; i < n; i++)
    {
        printf("enter the arr element: ");
        scanf("%d", &arr[i]);
    }
     printf("enter the arr of search element: ");
    scanf("%d", &m);
    for ( i = 0; i < n; i++)
    {
      if (m==arr[i])
      {
       printf("yes arr element");
       break;
      }
    
    }
    

    return 0;
}