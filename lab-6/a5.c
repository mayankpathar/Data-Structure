/*WAP to sort the array elements using Pointer.*/
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
   
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1-i; j++){
            if(*(ptr+j) > *(ptr+j+1)){
                int temp = *(ptr+j);
                *(ptr+j) = *(ptr+j+1);
                *(ptr+j+1) = temp;
            }
        }
    }
    printf("The sorted elements are :- ");
    for(int i=0; i<n; i++){
        printf("%d ",*(ptr+i));
    }
    return 0;
}