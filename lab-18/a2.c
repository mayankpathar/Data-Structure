#include <stdio.h>

#define MAX 5

struct Queue
{
    int data;
    int priority;
};

struct Queue q[MAX];
int rear = -1;

void insert(int data, int priority)
{
    if (rear == MAX - 1)
    {
        printf("Priority Queue Overflow\n");
        return;
    }

    rear++;
    q[rear].data = data;
    q[rear].priority = priority;

    printf("Inserted: %d with Priority %d\n", data, priority);
}

void delete()
{
    if (rear == -1)
    {
        printf("Priority Queue Underflow\n");
        return;
    }

    int i, index = 0;

    for (i = 1; i <= rear; i++)
    {
        if (q[i].priority < q[index].priority)
            index = i;
    }

    printf("Deleted: %d\n", q[index].data);

    for (i = index; i < rear; i++)
    {
        q[i] = q[i + 1];
    }

    rear--;
}

void display()
{
    int i;

    if (rear == -1)
    {
        printf("Priority Queue is Empty\n");
        return;
    }

    printf("Data\tPriority\n");

    for (i = 0; i <= rear; i++)
    {
        printf("%d\t%d\n", q[i].data, q[i].priority);
    }
}

int main()
{
    int choice, data, priority;

    do
    {
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter Data: ");
            scanf("%d", &data);

            printf("Enter Priority: ");
            scanf("%d", &priority);

            insert(data, priority);
            break;

        case 2:
            delete();
            break;

        case 3:
            display();
            break;

        case 4:
            printf("Program Ended\n");
            break;

        default:
            printf("Invalid Choice\n");
        }

    } while (choice != 4);

    return 0;
}