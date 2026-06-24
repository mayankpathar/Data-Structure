/*   1
    1 1
   1 2 1
  1 3 3 1
 1 4 6 4 1
*/
#include<stdio.h>

int main(){
    int n,i,j;
    printf("enter the number: ");
    scanf("%d",&n);
    
    for(i=0;i<n;i++){
        for(j=0;j<=n-i-2;j++){
            printf(" ");
        }
        int num=1;
        for(j=0;j<=i;j++){
            printf("%d ",num);
            num=num*(i-j)/(j+1);
        }
        printf("\n");
    }
    
    return 0;
}