#include<stdio.h>

int main(){
    int n,i,n1,n2;
    printf("enter the number: ");
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++){
        printf("enter the element: ");
        scanf("%d",&arr[i]);
    }
    printf("enter the number and change number: ");
    scanf("%d %d",&n1,&n2);
    for(i=0;i<n;i++){
        if(arr[i]==n1){
            arr[i]=n2;
        }
    }
    printf("modified array is: ");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}