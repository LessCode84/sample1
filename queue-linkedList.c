#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue();
void dequeue();
void display();

int main()
{
    int choice;

    while (choice != 4)
    {
        printf("\n Main Menu");
        printf("\n1. Insert an Item \n2. Delete an Item \n3. Show Queue \n4. Exit");
        printf("\n Please enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);
                break;

            default:
                printf("\n Please enter a valid choice: ");
        }
    }

    return 0;
}

void enqueue()
{
    struct node *ptr;
    int element;

    ptr = (struct node *)malloc(sizeof(struct node));

    if (ptr == NULL)
    {
        printf("\n Overflow");
        return;
    }

    printf("\n Please insert value: ");
    scanf("%d", &element);
    ptr->data = element;
    ptr->next = NULL;

    if (front == NULL)
    {
        front = ptr;
        rear = ptr;
    }
    else
    {
        rear->next = ptr;
        rear = ptr;
    }
}

void dequeue()
{
    struct node *ptr;

    if (front == NULL)
    {
        printf("\n Underflow");
        return;
    }

    ptr = front;
    front = front->next;
    free(ptr);
}

void display()
{
    struct node *ptr;
    ptr = front;

    if (front == NULL)
    {
        printf("\n Empty Queue");
    }
    else
    {
        printf("\n Show Values");
        while (ptr != NULL)
        {
            printf("\n %d", ptr->data);
            ptr = ptr->next;
        }
    }
}
    