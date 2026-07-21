// Write a program to simulate music player application using suitable data structure.=>
// There is no estimation about number of music files to be managed by the music player.=>
// Your program should support all the basic music player operations to play and manage the playlist.struct node

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char str[100];
    struct node *lpter;
    struct node *rpter;
};

struct node *first = NULL, *last = NULL, *current = NULL;

void addSong()
{
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter Song Name: ");
    getchar();
    gets(newnode->str);

    newnode->lpter = NULL;
    newnode->rpter = NULL;

    if (first == NULL)
    {
        first = last = newnode;
    }
    else
    {
        last->rpter = newnode;
        newnode->lpter = last;
        last = newnode;
    }

    if (current == NULL)
        current = first;
}

void display()
{
    struct node *temp = first;

    if (first == NULL)
    {
        printf("Playlist is Empty.");
        return;
    }

    printf("Playlist:\n");
    while (temp != NULL)
    {
        printf("%s\n", temp->str);
        temp = temp->rpter;
    }
}

void playCurrent()
{
    if (current == NULL)
        printf("No Song Available.");
    else
        printf("Now Playing : %s", current->str);
}

void nextSong()
{
    if (current == NULL)
    {
        printf("Playlist Empty.");
        return;
    }

    if (current->rpter != NULL)
    {
        current = current->rpter;
        printf("Now Playing : %s", current->str);
    }
    else
        printf("Last Song Reached.");
}

void previousSong()
{
    if (current == NULL)
    {
        printf("Playlist Empty.");
        return;
    }

    if (current->lpter != NULL)
    {
        current = current->lpter;
        printf("Now Playing : %s", current->str);
    }
    else
        printf("This is First Song.");
}

void deleteSong()
{
    char name[100];
    struct node *temp;

    if (first == NULL)
    {
        printf("Playlist Empty.");
        return;
    }

    printf("Enter Song Name to Delete: ");
    getchar();
    gets(name);

    temp = first;

    while (temp != NULL)
    {
        if (strcmp(temp->str, name) == 0)
        {
            if (temp == first)
            {
                first = first->rpter;
                if (first != NULL)
                    first->lpter = NULL;
            }
            else
                temp->lpter->rpter = temp->rpter;

            if (temp == last)
            {
                last = temp->lpter;
                if (last != NULL)
                    last->rpter = NULL;
            }
            else if (temp->rpter != NULL)
                temp->rpter->lpter = temp->lpter;

            if (current == temp)
                current = first;

            free(temp);
            printf("Song Deleted Successfully.");
            return;
        }
        temp = temp->rpter;
    }

    printf("Song Not Found.");
}

int main()
{
    int choice;

    do
    {
        printf("\n1. Add Song");
        printf("\n2. Display Playlist");
        printf("\n3. Play Current Song");
        printf("\n4. Next Song");
        printf("\n5. Previous Song");
        printf("\n6. Delete Song");
        printf("\n7. Exit");
        printf("\nEnter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addSong();
            break;

        case 2:
            display();
            break;

        case 3:
            playCurrent();
            break;

        case 4:
            nextSong();
            break;

        case 5:
            previousSong();
            break;

        case 6:
            deleteSong();
            break;

        case 7:
            printf("Thank You!");
            break;

        default:
            printf("Invalid Choice.");
        }
    } while (choice != 7);

    return 0;
}