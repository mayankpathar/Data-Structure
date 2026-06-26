/*Read two matrices, first 3x2 and second 2x3, perform multiplication operation and store result in third matrix and print it.*/
#include<stdio.h>

int main(){
    int n,i,j;
    int arr1[3][2],arr2[2][3],arr3[3][3];
   
    for(i=0;i<3;i++){
        for(j=0;j<2;j++){
            scanf("arr1:%d",&arr1[i][j]);
        }
    }

    for(i=0;i<2;i++){
        for(j=0;j<3;j++){
            scanf("arr2:%d",&arr2[i][j]);
        }
    }
  
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            arr3[i][j]=0;
            for(n=0;n<2;n++){
                arr3[i][j]+=arr1[i][n]*arr2[n][j];
            }
        }
    }

    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("%d ",arr3[i][j]);
        }
        printf("\n");
    }
    return 0;
}