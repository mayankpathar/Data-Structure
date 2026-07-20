// Write a menu driven program to implement following operations on the circular linked list.
//  Insert a node at the front of the linked list.
//  Insert a node at the end of the linked list.
//  Delete a node from the specified position of the linked list.


#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};
struct node *first = NULL;
struct node *last = NULL;
void insertfirst()
{
    struct node *new;
    new = malloc(sizeof(struct node));
   
    printf("Enter the new info: ");
    scanf("%d", &new->info);
  
    if (first == NULL)
    {
        first = last = new;
        new->link = first;
    }
    else
    {
        new->link = first;
        last->link = new;
        first = new;
    }
}

void lastinsert()
{
    struct node *new;
    new = malloc(sizeof(struct node));
   
    printf("Enter the new info: ");
    scanf("%d", &new->info);
  
    if (first == NULL)
    {
        first = last = new;
        new->link = first;
    }
    else
    {
        last->link = new;
        new->link = first;
        last = new;
    }
}
void deletespecified()
{
    int pos, i;
    struct node *temp, *prev;
    if (first == NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("Enter the position to delete: ");
    scanf("%d", &pos);
    temp = first;
    if (pos == 1)
    {
        if (first == last)
        {
            free(first);
            first = last = NULL;
        }
        else
        {
            first = first->link;
            last->link = first;
            free(temp);
        }
        return;
    }
    for (i = 1; i < pos && temp != last; i++)
    {
        prev = temp;
        temp = temp->link;
    }
    if (temp == last && i < pos)
    {
        printf("Position out of range\n");
        return;
    }
    prev->link = temp->link;
    if (temp == last)
    {
        last = prev;
    }
    free(temp);
}
void display()
{
    if (first == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct node *save = first;
    printf("Circular list elements: ");
    do
    {
        printf("%d ", save->info);
        save = save->link;
    } while (save != first);
    printf("\n");
}

int main()
{
    int n,m;
    printf("Enter the number of insertfirst nodes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        insertfirst();
        
    }
    printf("Enter the number of lastfirst nodes: ");
    scanf("%d", &m);
    for (int i = 0; i <m; i++)
    {
        lastinsert();
    }
    
    display();
    deletespecified();
    display();  
}
