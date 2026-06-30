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
   printf("insert first done.\n");
}

void insertlast(){
    struct node *newnode,*save;
    newnode = (struct node *)malloc(sizeof(struct node));
    
    printf("enter the new info: ");
    scanf("%d",&newnode->info);
    newnode->link=NULL;
    if(first==NULL){
        first=newnode;
    }else{
        save=first;
        while(save->link!=NULL){
            save=save->link;
        }
        save->link=newnode;
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

void deletefirst(){
    struct node *save;
    if(first==NULL){
        printf("list is empty.\n");
    }else{
        save=first;
        first=first->link;
        free(save);
    }
}

void deletelast(){
    struct node *save,*prev;
   if(first==NULL){
        printf("list is empty.\n");
    }else{
        save=first;
        while(save->link!=NULL){
            prev=save;
            save=save->link;
        }
        prev->link=NULL;
        free(save);
    }
}


// Delete Node at Specific Position
void deletePosition()
{
    int pos, i;
    struct node *save, *prev;

    if (first == NULL)
    {
        printf("List is Empty.\n");
        return;
    }

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos == 1)
    {
        deletefirst();
        return;
    }

    save = first;

    for (i = 1; i < pos; i++)
    {
        prev = save;
        save = save->link;

        if (save == NULL)
        {
            printf("Invalid Position.\n");
            return;
        }
    }

    prev->link = save->link;
    free(save);

    printf("Node deleted.\n");
}



int countnodes(){
    struct node *save;
    int count=0;
    save=first;
    while(save!=NULL){
        count++;
        save=save->link;
    }
    return count;
}

void main(){
    int choice;
    while(1){
        printf("1. Insert First\n");
        printf("2. Insert Last\n");
        printf("3. Display\n");
        printf("4. Delete First\n");
        printf("5. Delete Last\n");
        printf("6. Delete Specific Position\n");
        printf("7. Count Nodes\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                insertfirst();
                break;
            case 2:
                insertlast();
                break;
            case 3:
                display();
                break;
            case 4:
                deletefirst();
                break;
            case 5:
                deletelast();
                break;
            case 6:
                deletePosition();
                break;
            case 7:
                printf("Number of nodes: %d\n",countnodes());
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}