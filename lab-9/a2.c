// Write a program to reverse a linked list.
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

struct node *first1 = NULL;


void firstlinkedlist() {
    struct node *n1node, *save;

    n1node = (struct node *)malloc(sizeof(struct node));

    printf("Enter the new info: ");
    scanf("%d", &n1node->info);

    n1node->link = NULL;

    if (first1 == NULL) {
        first1 = n1node;
    } else {
        save = first1;
        while (save->link != NULL) {
            save = save->link;
        }
        save->link = n1node;
    }
}
void reversellinkedlist()
{
   struct node *prev = NULL, *current = first1, *save = NULL;

    while (current != NULL)
    {
        save = current->link;
        current->link = prev; 
        prev = current;     
        current = save;       
    }
    first1 = prev; 
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
void main(){
    
    int n;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        firstlinkedlist();
    }

    reversellinkedlist();

    displaylinkedlist();

    return 0;
}