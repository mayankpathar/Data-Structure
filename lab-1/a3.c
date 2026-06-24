#include<stdio.h>

int main(){
    char c;
    printf("enter the char:");
    scanf("%c",&c);
    if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U')
    {
        printf("vowel");
    }else
    {
        printf("not vowel");
    }
    
    
    return 0;
}