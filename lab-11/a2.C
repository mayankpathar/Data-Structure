// WAP to split a circular linked list into two halves.
#include <stdio.h>
#include<stdlib.h>
struct Node{
    int Info;
    struct Node *link;
};
struct Node *First = NULL;
struct Node *Last = NULL;

void insert(){
    struct Node *new;
    
    new = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter Info: ");
    scanf("%d", &new->Info);

    if (First == NULL){
        First = Last = new;
        new->link = First;
    }
    else
    {
        
        Last->link = new;
        Last = new;
        Last->link = First;
    }
}
void splitList(struct Node **First1, struct Node **First2){
    struct Node *half, *full;
    
    if (First == NULL)
        return;

    half = First;
    full = First;

    while (full->link != First && full->link->link != First)
    {
        half = half->link;
        full = full->link->link;
    }

    if (full->link->link == First){
        full = full->link;
    }
    *First1 = First;

    if (First->link != First)
        *First2 = half->link;

    half->link = *First1;
    full->link = *First2;
}
void display()
{
    struct Node *temp;

    if (First == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = First;
    do
    {
        printf("%d -> ", temp->Info);
        temp = temp->link;
    }
    while (temp != First);
    printf("(Back to First)\n");

    return;
}
void main(){
    int n;
    struct Node *First1 = NULL;
    struct Node *First2 = NULL;

    printf("ENter number of Nodes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        insert();
    }

    printf("Original Circular List:\n");
    display(First);

    splitList(&First1, &First2);

    printf("\nFirst Half:\n");
    display(First1);

    printf("\nSecond Half:\n");
    display(First2);
    return;
}