#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
} *top = NULL;

void push(int);
void pop();
void display();

int main() {
    int choice, value;
    printf("Stack using Linked List\n");

    while (1) {
        printf("1. Push \n2. Pop \n3. Show \n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);
                break;

            default:
                printf("Invalid Choice\n");
        }
    }
}

void push(int value) {
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if (top == NULL)
        newNode->next = NULL;
    else
        newNode->next = top;

    top = newNode;
    printf("Node is Inserted.\n");
}

void pop() {
    if (top == NULL)
        printf("Empty Stack\n");
    else {
        struct Node *temp = top;
        printf("Popped Element: %d\n", temp->data);
        top = temp->next;
        free(temp);
    }
}

void display() {
    if (top == NULL)
        printf("Empty Stack\n");
    else {
        printf("The Stack is: ");
        struct Node *temp = top;
        while (temp->next != NULL) {
            printf("%d--->", temp->data);
            temp = temp->next;
        }
        printf("%d--->NULL\n", temp->data);
    }
}
