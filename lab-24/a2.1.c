// Write a program to implement a Binary Search using Array. (Iterative)
#include<stdio.h>

int main(){
    int n, i, l, h, m, search;
    printf("enter the arr size: ");
    scanf("%d", &n);
    int arr[n];

    for (i = 0; i < n; i++)
    {
        printf("enter the arr element: ");
        scanf("%d", &arr[i]);
    }
    printf("enter the arr of search element: ");
    scanf("%d", &search);
    l = 0;
    h = n - 1;
    while(l <= h){
        m = (l+ h) / 2;
        if(arr[m] == search){
            printf("Element found at index:", m);
            break;
        }
        else if(arr[m] < search){
            l = m+ 1;
        }
        else{
            h = m - 1;
        }
    }
    if(l > h){
        printf("Element not found\n");
    }
    return 0;
}