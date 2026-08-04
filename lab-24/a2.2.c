// Write a program to implement a Binary Search using Array. (recursive)
#include<stdio.h>
    int Binary_Search_recursive(int arr[], int l, int h, int search);
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
    int result = Binary_Search_recursive(arr,l,h,search);
    printf("Element found at index: %d", result);
    
    return 0;
}

int Binary_Search_recursive(int arr[], int l, int h, int search){
    int m;
    if(l <= h){
        m = (l+ h) / 2;
        if(arr[m] == search){
            return m;
        }
        else if(arr[m] < search){
            return Binary_Search_recursive(arr,m+1,h,search);
        }
        else{
            return Binary_Search_recursive(arr,l,m-1,search);
        }
    }
    else{
        printf("Element not found\n");
        return -1;
    }
}
