#include<stdio.h>
#define MAX_SIZE 6

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

void enqueue(int element) {
    if ((rear + 1) % MAX_SIZE == front) {
        printf("The queue is Overflowing.\n");
    } else if (front == -1 && rear == -1) {
        front = 0;
        rear = 0;
        queue[rear] = element;
    } else {
        rear = (rear + 1) % MAX_SIZE;
        queue[rear] = element;
    }
}

void dequeue() {
    if (front == -1 && rear == -1) {
        printf("Queue is Underflow.\n");
    } else if (front == rear) {
        printf("The removed item from the queue is %d\n", queue[front]);
        front = -1;
        rear = -1;
    } else {
        printf("The removed item from the queue is %d\n", queue[front]);
        front = (front + 1) % MAX_SIZE;
    }
}

void display() {
    int i = front;
    if (front == -1 && rear == -1) {
        printf("The Queue is Empty.\n");
    } else {
        printf("The elements of the Queue are: ");
        while (i != rear) {
            printf("%d ", queue[i]);
            i = (i + 1) % MAX_SIZE;
        }
        printf("%d\n", queue[rear]);
    }
}

int main() {
    int choice = 1, x;
    while (choice < 4 && choice != 0) {
        printf("\n1. Insert an Element\n");
        printf("2. Delete an Element\n");
        printf("3. Show Element\n");
        printf("0. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &x);
                enqueue(x);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 0:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Please enter a valid choice.\n");
        }
    }
    return 0;
}
