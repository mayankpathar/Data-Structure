#include<stdio.h>

int main(){
    int n,i,lo,n1;
    printf("enter the number: ");
    scanf("%d",&n);
    int arr[n];
    for ( i = 0; i < n; i++)
    {
        printf("enter the element of arr: ");
        scanf("%d",&arr[i]);
    }
    printf("enter the location and new number: ");
    scanf("%d %d",&lo,&n1);
    for ( i = n-1; i >= lo; i--)
    {
        arr[i+1]=arr[i];
    }
    arr[lo]=n1;
    for ( i = 0; i < n+1; i++)
    {
        printf("%d ",arr[i]);
    }

    return 0;
}