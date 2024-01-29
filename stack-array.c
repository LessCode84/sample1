#include<stdio.h>

int stack[100], i, j, choice = 0, n, top = -1;

void push();
void pop();
void show();

void main() {
    printf("Enter the number of elements in the stack: ");
    scanf("%d", &n);
    printf("Stack Operations using Array\n");

    while (choice != 4) {
        printf("Choose one from below options:\n");
        printf("1. Push\n2. Pop\n3. Show\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                show();
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Please enter a valid choice.\n");
        }
    }
}

void push() {
    int val;
    if (top == n - 1)
        printf("Overflow: Stack is full.\n");
    else {
        printf("Enter value: ");
        scanf("%d", &val);
        top = top + 1;
        stack[top] = val;
    }
}

void pop() {
    if (top == -1)
        printf("Underflow: Stack is empty.\n");
    else
        top = top - 1;
}

void show() {
    if (top == -1) {
        printf("Stack is Empty.\n");
    } else {
        printf("Stack elements: ");
        for (i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

