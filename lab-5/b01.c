#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>
void main(){
    int n;
    scanf("%d",&n);
    char words[n][100];
    int i;
    for ( i = 0; i < n; i++)
    {
        scanf("%s",words[i]);
    }
    srand(time(NULL));
    int random=rand()%n;
    char anagram[50];
    printf("Enter your anagram :- ");
    scanf("%s",anagram);
    char frq[]={0};
    char freq2[]={0};
    for ( i = 0; i < strlen(words[random]); i++)
    {
        frq[words[random][i]-'a']++;
    }
     for ( i = 0; i < strlen(anagram); i++)
    {
        freq2[anagram[i]-'a']++;
    }
    bool isana=true;
    for ( i = 0; i < strlen(anagram); i++)
    {
        if (frq[i]!=freq2[i])
        {
            isana=false;
            break;
        }
    }
    
    if (isana)
    {
        printf("Anagram..");
    }
    else{
        printf("Not Anagram..");
    }
    
}