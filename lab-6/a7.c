/*WAP to define a C structure named Student (roll_no, name, branch and batch_no) and also to access the structure members using Pointer.*/
#include<stdio.h>
#include<string.h>
struct Student {
    int roll_no;
    char name[100];
    char branch[50];
    int batch_no;
};

int main(){

    struct Student *ptr = (struct Student *)malloc(sizeof(struct Student));
    ptr->roll_no = 1;
    strcpy(ptr->name, "John Doe");
    strcpy(ptr->branch, "Computer Science");
    ptr->batch_no = 2023;

    printf("Roll No: %d\n", ptr->roll_no);
    printf("Name: %s\n", ptr->name);
    printf("Branch: %s\n", ptr->branch);
    printf("Batch No: %d\n", ptr->batch_no);
    free(ptr);

    return 0;
}