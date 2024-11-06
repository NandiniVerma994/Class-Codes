#include <stdio.h>
#include <stdlib.h>

#define SIZE 5  // Define the maximum size of the circular queue

int queue[SIZE];
int front = -1, rear = -1;

// Function to check if the queue is empty
int isEmpty() {
    return front == -1;
}

// Function to check if the queue is full
int isFull() {
    return (rear + 1) % SIZE == front;
}

// Function to add an element to the circular queue
void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full. Cannot enqueue %d.\n", value);
    } else {
        if (isEmpty()) {
            front = 0;  // Initialize front if it's the first element
        }
        rear = (rear + 1) % SIZE;  // Circular increment of rear
        queue[rear] = value;
        printf("Enqueued %d.\n", value);
    }
}

// Function to remove an element from the circular queue
void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot dequeue.\n");
    } else {
        printf("Dequeued %d.\n", queue[front]);
        if (front == rear) {  // Queue has only one element, reset to empty
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;  // Circular increment of front
        }
    }
}

// Function to display all elements in the circular queue
void traverse() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        int i = front;
        while (1) {
            printf("%d ", queue[i]);
            if (i == rear) break;
            i = (i + 1) % SIZE;  // Circular increment of i
        }
        printf("\n");
    }
}

// Main function with menu-driven interface
int main() {
    int choice, value;

    while (1) {
        printf("\nCircular Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Traverse\n");
        printf("4. IsEmpty\n");
        printf("5. IsFull\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                traverse();
                break;
            case 4:
                if (isEmpty()) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Queue is not empty.\n");
                }
                break;
            case 5:
                if (isFull()) {
                    printf("Queue is full.\n");
                } else {
                    printf("Queue is not full.\n");
                }
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
