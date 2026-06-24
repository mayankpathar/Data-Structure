#include <stdio.h>

int main()
{
    int n,i,j,k;
    printf("enter the number: ");
    scanf("%d", &n);
    int arr[n];
    for (i = 0; i < n; i++)
    {
        printf("enter the element of arr: ");
        scanf("%d", &arr[i]);
    }
    for(i=0; i <n; i++){
        for(j=0;j<n;j++){
            if(arr[i]==arr[j] && i!=j){

                for(k=j;k<n-1;k++){
                    arr[k]=arr[k+1];
                }
                n--;
                j--;
               
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}