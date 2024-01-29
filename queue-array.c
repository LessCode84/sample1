#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Queue
{
    int items[MAX_SIZE];
    int front, rear;
};

void enqueue(struct Queue *q, int element);
int dequeue(struct Queue *q);
void display(struct Queue *q);

int main()
{
    struct Queue q;
    q.front = -1;
    q.rear = -1;

    int choice, element;

    while (1)
    {
        printf("\n Main Menu");
        printf("\n1. Insert an Item \n2. Delete an Item \n3. Show Queue \n4. Exit");
        printf("\n Please enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\n Please insert value: ");
            scanf("%d", &element);
            enqueue(&q, element);
            break;

        case 2:
            element = dequeue(&q);
            if (element != -1)
                printf("\n Removed element: %d", element);
            break;

        case 3:
            display(&q);
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

void enqueue(struct Queue *q, int element)
{
    if (q->rear == MAX_SIZE - 1)
    {
        printf("\n Overflow");
        return;
    }

    if (q->front == -1)
        q->front = 0;

    q->rear++;
    q->items[q->rear] = element;

    printf("\n Element enqueued: %d", element);
}

int dequeue(struct Queue *q)
{
    int element;

    if (q->front == -1)
    {
        printf("\n Underflow");
        return -1;
    }

    element = q->items[q->front];
    q->front++;

    if (q->front > q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }

    return element;
}

void display(struct Queue *q)
{
    if (q->front == -1)
    {
        printf("\n Empty Queue");
    }
    else
    {
        printf("\n Show Values");
        for (int i = q->front; i <= q->rear; i++)
        {
            printf("\n %d", q->items[i]);
        }
    }
}
