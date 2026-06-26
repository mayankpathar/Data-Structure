/*WAP to allocate and de-allocate memory for int, char and float variable at runtime.*/
#include<stdio.h>
#include<stdlib.h>
int main(){
    int *ptr1;
    char *ptr2;
    float *ptr3;
    ptr1 = (int*)malloc(sizeof(int));
    ptr2 = (char*)malloc(sizeof(char));
    ptr3 = (float*)malloc(sizeof(float));
    free(ptr1);
    free(ptr2);
    free(ptr3);
    return 0;
}