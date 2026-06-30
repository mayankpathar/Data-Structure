// Write a program to implement a node structure for singly linked list. Read the data in a node, print the node.
#include<stdio.h>
#include<stdlib.h>
struct node
{
   int info;
   struct node *link;
};

int main()
{
   struct node *temp;
   temp = (struct node *)malloc(sizeof(struct node));
   printf("Enter data for the node: ");
   scanf("%d", &temp->info);
   temp->link = NULL;
   printf("%d\n", temp->info);
   free(temp);
   return 0;
}