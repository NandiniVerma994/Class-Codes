#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Initialize the stack (top pointer)
struct Node* top = NULL;

// Function to push an element onto the stack
void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Stack Overflow\n");
        return;
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("%d pushed to stack\n", value);
}

// Function to pop an element from the stack
int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    int poppedValue = top->data;
    struct Node* temp = top;
    top = top->next;
    free(temp);
    return poppedValue;
}

// Function to check if the stack is empty
int isEmpty() {
    return top == NULL;
}

// Function to display all elements in the stack
void display() {
    if (isEmpty()) {
        printf("Stack is empty\n");
    } else {
        struct Node* temp = top;
        printf("Stack elements are:\n");
        while (temp != NULL) {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}

// Main function with a menu-driven interface
int main() {
    int choice, value;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. IsEmpty\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                value = pop();
                if (value != -1)
                    printf("Popped value is %d\n", value);
                break;
            case 3:
                if (isEmpty())
                    printf("Stack is empty\n");
                else
                    printf("Stack is not empty\n");
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
