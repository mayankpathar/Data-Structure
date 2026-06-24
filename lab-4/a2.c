/*Write a program to delete a number from a given location in an array. */
#include<stdio.h>

int main(){
    int n,i,lo;
    printf("enter the number: ");
    scanf("%d",&n);
    int arr[n];
    for ( i = 0; i < n; i++)
    {
        printf("enter the element of arr: ");
        scanf("%d",&arr[i]);
    }
    printf("enter the location: ");
    scanf("%d",&lo);
    for(i=lo; i < n; i++)
    {
        arr[i]=arr[i+1];
    }
    n--;
    for ( i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }

    return 0;
}