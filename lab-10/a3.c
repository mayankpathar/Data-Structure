// WAP to perform given operation in the linked list. There exist a Linked List.->
// Add a node that contains the GCD of those two nodes between every pair adjacent node of Linked List.
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

struct node *first1 = NULL;

void firstlinkedlist()
{
    struct node *n1node, *save;

    n1node = (struct node *)malloc(sizeof(struct node));

    printf("Enter the new info: ");
    scanf("%d", &n1node->info);

    n1node->link = NULL;

    if (first1 == NULL)
    {
        first1 = n1node;
    }
    else
    {
        save = first1;
        while (save->link != NULL)
        {
            save = save->link;
        }
        save->link = n1node;
    }
}
void gcdlinkedlist(){
    int gcd,min;
    struct node *prev,*save;
    prev = first1;
    save = prev->link;
    while (save!=NULL)
    {
        min=prev->info<save->info?prev->info:save->info;
        
        for (int i = 1; i <= min; i++)
        {
            if (prev->info%i==0 && save->info%i==0)
            {
                gcd=i;
            }
            
        }
        struct node *newnode;
        newnode=(struct node *)malloc(sizeof(struct node)); 
        newnode->info=gcd;
        newnode->link=save;
        prev->link=newnode;
        prev=newnode->link;
        save=save->link;
    }
    
}
void displaylinkedlist()
{
    struct node *save;

    if (first1 == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    save = first1;

    while (save != NULL)
    {
        printf("%d\t", save->info);
        save = save->link;
    }
}
int main()
{

    int n;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        firstlinkedlist();
    }

    gcdlinkedlist();

    displaylinkedlist();

    return 0;
}