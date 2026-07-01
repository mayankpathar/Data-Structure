//WAP to check whether 2 singly linked lists are same or not.
#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *link;
};

struct node *first1=NULL;

void firstlinkedlist(){
    struct node *n1node;
    n1node = (struct node *)malloc(sizeof(struct node));
    
    printf("enter the new info: ");
    scanf("%d",&n1node->info);
    n1node->link=first1;
    first1=n1node;
   printf("insert first done.\n");
}
struct node *first2=NULL;
void secondlinkedlist(){
    struct node *n2node;
    n2node = (struct node *)malloc(sizeof(struct node));
    
    printf("enter the new info: ");
    scanf("%d",&n2node->info);
    n2node->link=first2;
    first2=n2node;
   printf("insert first done.\n");
}

void samelinkedlist(){
    struct node *save1,*save2;
    save1=first1;
    save2=first2;
    if(first1==NULL && first2==NULL){
        printf("one empty or both empty.\n");

    }else
    {
        while(save1!=NULL && save2!=NULL){
            if(save1->info==save2->info){
                continue;
            }else{
                printf("not same linked list.\n");
                return;
            }
            save1=save1->link;
            save2=save2->link;
        }
        if(save1==NULL && save2==NULL){
            printf("same linked list.\n");
        }else{
            printf("not same linked list.\n");
        }
    }
    
}

void main(){
    int choice;
    while(1){
    printf("1. first linked list\n");
    printf("2. second linked list\n");
    printf("3. check if same\n");
    printf("4. exit\n");
    printf("enter your choice: ");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            firstlinkedlist();
            break;
        case 2:
            secondlinkedlist();
            break;
        case 3:
            samelinkedlist();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("invalid choice.\n");
    }
    }
}

