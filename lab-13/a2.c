#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

struct node *top = NULL;

void push()
{
    struct node *newnode;

    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter value: ");
    scanf("%d",&newnode->info);

    newnode->link = top;
    top = newnode;
}

void pop()
{
    struct node *temp;

    if(top==NULL)
    {
        printf("Stack Underflow\n");
        return;
    }

    temp = top;

    printf("Deleted Element = %d\n",temp->info);

    top = top->link;

    free(temp);
}

void display()
{
    struct node *save;

    if(top==NULL)
    {
        printf("Stack Empty\n");
        return;
    }

    save = top;

    printf("Stack Elements:\n");

    while(save!=NULL)
    {
        printf("%d\n",save->info);
        save = save->link;
    }
}

void peep()
{
    struct node *save;
    int pos,i=1;

    if(top==NULL)
    {
        printf("Stack Empty\n");
        return;
    }

    printf("Enter position from TOP: ");
    scanf("%d",&pos);

    save = top;

    while(save!=NULL && i<pos)
    {
        save = save->link;
        i++;
    }

    if(save==NULL)
    {
        printf("Invalid Position\n");
    }
    else
    {
        printf("Element = %d\n",save->info);
    }
}

void change()
{
    struct node *save;
    int pos,value,i=1;

    if(top==NULL)
    {
        printf("Stack Empty\n");
        return;
    }

    printf("Enter position from TOP: ");
    scanf("%d",&pos);

    save = top;

    while(save!=NULL && i<pos)
    {
        save = save->link;
        i++;
    }

    if(save==NULL)
    {
        printf("Invalid Position\n");
        return;
    }

    printf("Enter new value: ");
    scanf("%d",&value);

    save->info = value;

}

int main()
{
    int choice;

    while(1)
    {
        printf("\n1.Push");
        printf("\n2.Pop");
        printf("\n3.Display");
        printf("\n4.Peep");
        printf("\n5.Change");
        printf("\n6.Exit");

        printf("\nEnter Choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: peep(); break;
            case 5: change(); break;
            case 6: return 0;
            default: printf("Invalid Choice\n");
        }
    }
}