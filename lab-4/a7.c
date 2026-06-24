/*WAP to replace lowercase characters by uppercase & vice-versa in a user specified string.*/
#include<stdio.h>
#include<string.h>
int main(){
    
char str[100];
int i;
printf("enter the string: ");
scanf("%s",str);
for(i=0;i<strlen(str);i++){
    if(str[i]>=97 && str[i]<=122){
        str[i]=str[i]-32;
    }
    else if(str[i]>=65 && str[i]<=90){
        str[i]=str[i]+32;
    }
}
printf("the modified string is: %s",str);

    return 0;
}