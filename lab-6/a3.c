/*WAP to calculate the sum of n numbers using Pointer.*/
#include<stdio.h>

int main(){
    int n;
    printf("Enter the number of elements :- ");
    scanf("%d",&n);
    int arr[n];
    int *ptr = arr;
    printf("Enter the elements :- ");
    for(int i=0; i<n; i++){
        scanf("%d",(ptr+i));
    }
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += *(ptr+i);
    }
    printf("The sum of elements is :- %d",sum);
    return 0;
}