/*WAP to find the largest element in the array using Pointer*/
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
    int largest = *(ptr+0);
    for(int i=1; i<n; i++){
        if(*(ptr+i) > largest){
            largest = *(ptr+i);
        }
    }
    printf("The largest element is :- %d",largest);
    return 0;
}