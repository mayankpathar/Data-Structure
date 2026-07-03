#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *link;
};

struct node *first=NULL;

void insertfirst(){
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    
    printf("enter the new info: ");
    scanf("%d",&newnode->info);
    newnode->link=first;
    first=newnode;
   
}
void duplicates(){
     struct node *save,*prev;
     save=first;
     if(first==NULL){
        printf("empty");
        return;
     }else{
        while (save!=NULL)
        {
            prev=save;
            save=save->link;
            if (prev->info==save->info)
            {
                save=save->link;
                prev->link=save;
            }else{
                continue;
            }
            
        }
        
     }
     
}
void display(){
    struct node *save;
    save=first;
    if(first==NULL){
        printf("list is empty.\n");
    }else{
        while(save!=NULL){
            printf("%d\n",save->info);
            save=save->link;

        }
    }
}
void  main(){
    int n;
    printf("enter the new node: ");
    scanf("%d",&n);
    for (int i = 1; i <=n; i++)
    {
        insertfirst();
    }
    duplicates();
    display();
    
}