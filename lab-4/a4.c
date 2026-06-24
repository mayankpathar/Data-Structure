#include<stdio.h>

int main(){
    int n,i,n1,lo;
    printf("enter the number: ");
    scanf("%d",&n);
    int arr[n];
    for ( i = 0; i < n; i++)
    {
        printf("enter the element of arr: ");
        scanf("%d",&arr[i]);
    }
    printf("enter the delete of arr element: ");
    scanf("%d",&n1);
    for(i = 0; i < n; i++)
    {
        if (arr[i]==n1)
        {
            lo=i;
            break;
        }
    }
    for ( i = lo; i < n-1; i++)
    {
        arr[i]=arr[i+1];
    }
    for ( i = 0; i < n-1; i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}