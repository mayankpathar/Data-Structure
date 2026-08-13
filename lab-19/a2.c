// Write a program to check whether the given two trees are same or not.
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *left;
    struct Node *right;
};

struct Node *insert(struct Node *root, int value)
{
    if (root == NULL)
    {
        struct Node *new = (struct Node *)malloc(sizeof(struct Node));

        new->info = value;
        new->left = NULL;
        new->right = NULL;

        return new;
    }

    if (value < root->info)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->info)
    {
        root->right = insert(root->right, value);
    }

    return root;
}
int isSameTree(struct Node *p, struct Node *q)
{
    if (p == NULL && q == NULL)
    {
        return 1;
    }
    if (p == NULL || q == NULL)
    {
        return 0;
    }
    if (p->info != q->info)
    {
        return 0;
    }

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main()
{
    struct Node *root1 = NULL;
    struct Node *root2 = NULL;
    int n;
    printf("Enter the number of elements for the first tree: ");
    scanf("%d", &n);
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int value;
            printf("Enter a value to insert into tree %d: ", i + 1);
            scanf("%d", &value);
            if (i == 0)
            {
                root1 = insert(root1, value);
            }
            else
            {
                root2 = insert(root2, value);
            }
        }
    }
        if (isSameTree(root1, root2))
        {
            printf("The two trees are the same.\n");
        }
        else
        {
            printf("The two trees are not the same.\n");
        }

        return 0;
    
}