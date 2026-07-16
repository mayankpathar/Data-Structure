// WAP to split a circular linked list into two halves.
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

struct node *first1=NULL;
struct node *first2=NULL;

void twolinkedlist(struct node *first)
{
    struct node *slow_ptr = first;
    struct node *fast_ptr = first;

    if (first == NULL)
        return;

    while (fast_ptr->link != first && fast_ptr->link->link != first)
    {
        fast_ptr = fast_ptr->link->link;
        slow_ptr = slow_ptr->link;
    }

    if (fast_ptr->link->link == first)
        fast_ptr = fast_ptr->link;

    first1 = first;

    if (first->link != first)
        first2 = slow_ptr->link;

    fast_ptr->link = slow_ptr->link;
    slow_ptr->link = first;
}

