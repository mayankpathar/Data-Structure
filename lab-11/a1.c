// Write a menu driven program to implement following operations on the circular linked list.
//  Insert a node at the front of the linked list.
//  Delete a node from specified position.
//  Insert a node at the end of the linked list.
//  Display all nodes.
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int info;
    struct Node *link;
};
struct Node *first=NULL;
void insertfirst(){
    struct Node *newnode;
    newnode=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter the new info: ");
    scanf("%d",&newnode->info);
    if(first==NULL){
        first=newnode;
        newnode->link=first;
    }
    else{
        struct Node *temp=first;
        while(temp->link!=first){
            temp=temp->link;
        }
        temp->link=newnode;
        newnode->link=first;
        first=newnode;
    }

}
void insertlast(){
    struct Node *newnode;
    newnode=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter the new info: ");
    scanf("%d",&newnode->info);
    if(first==NULL){
        first=newnode;
        newnode->link=first;
    }
    else{
        struct Node *temp=first;
        while(temp->link!=first){
            temp=temp->link;
        }
        temp->link=newnode;
        newnode->link=first;
    }
}
void deletepos(){
    int pos;
    printf("Enter the position to delete: ");
    scanf("%d",&pos);
    if(first==NULL){
        printf("List is empty.\n");
        return;
    }
    struct Node *temp=first;
    if(pos==1){
        while(temp->link!=first){
            temp=temp->link;
        }
        struct Node *todelete=first;
        first=first->link;
        temp->link=first;
        free(todelete);
        return;
    }
    for(int i=1;i<pos-1;i++){
        temp=temp->link;
        if(temp==first){
            printf("Position out of bounds.\n");
            return;
        }
    }
    struct Node *todelete=temp->link;
    temp->link=todelete->link;
    free(todelete);
}
void display(){
    if(first==NULL){
        printf("List is empty.\n");
        return;
    }
    struct Node *temp=first;
    printf("Circular Linked List: ");
    do{
        printf("%d ",temp->info);
        temp=temp->link;
    }while(temp!=first);
    printf("\n");
}
void main(){
    
    int n;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        insertfirst();
    }

    

    display();

    return 0;
}
