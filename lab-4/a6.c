#include<stdio.h>

int main(){
    int m,n,i,n1;
    printf("enter the arr1 number: ");
    scanf("%d", &m);
    int arr1[m];
    for(i=0;i<m;i++){
        printf("enter the element of arr1: ");
        scanf("%d", &arr1[i]);
    }
    printf("enter the arr2 number: ");
    scanf("%d", &n);
    int arr2[n];
    for(i=0;i<n;i++){
        printf("enter the element of arr2: ");
        scanf("%d", &arr2[i]);
    }
    n1=m+n;
    int arr3[n1];
    for(i=0;i<m;i++){
        arr3[i]=arr1[i];
    }
    for(i=0;i<n;i++){
        arr3[m+i]=arr2[i];
    }
    for(i=0;i<n1;i++){
        printf("%d ", arr3[i]);
    }
    return 0;
}