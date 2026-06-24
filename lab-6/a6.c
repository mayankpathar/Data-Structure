/*WAP to check whether the string is Palindrome or not using Pointer.*/
#include<stdio.h>
#include<string.h>

int main(){
    char str[100];
    printf("Enter the string :- ");
    gets(str);
    int len = strlen(str);
    char *ptr1 = str;
    char *ptr2 = str + len - 1;
    int isPalindrome = 1;
    while(ptr1 < ptr2){
        if(*ptr1 != *ptr2){
            isPalindrome = 0;
            break;
        }
        ptr1++;
        ptr2--;
    }
    if(isPalindrome){
        printf("The string is a palindrome.");
    }
    else{
        printf("The string is not a palindrome.");
    }
    return 0;
}