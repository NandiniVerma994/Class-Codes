#include <stdio.h>
#include <stdlib.h>

// Define the structure for a priority queue node
struct Node {
    int data;
    int priority;
    struct Node* next;
};

struct Node* front = NULL;

// Function to enqueue an element into the priority queue
void enqueue(int value, int priority) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed. Cannot enqueue %d.\n", value);
        return;
    }
    newNode->data = value;
    newNode->priority = priority;
    newNode->next = NULL;

    // If the queue is empty or the new node has higher priority
    if (front == NULL || priority < front->priority) {
        newNode->next = front;
        front = newNode;
        printf("Enqueued %d with priority %d.\n", value, priority);
    } else {
        // Find the correct position to insert the new node
        struct Node* temp = front;
        while (temp->next != NULL && temp->next->priority <= priority) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        printf("Enqueued %d with priority %d.\n", value, priority);
    }
}

// Function to dequeue the element with the highest priority (lowest priority value)
void dequeue() {
    if (front == NULL) {
        printf("Priority queue is empty. Cannot dequeue.\n");
    } else {
        struct Node* temp = front;
        printf("Dequeued %d with priority %d.\n", temp->data, temp->priority);
        front = front->next;
        free(temp);
    }
}

// Function to display all elements in the priority queue
void traverse() {
    if (front == NULL) {
        printf("Priority queue is empty.\n");
    } else {
        struct Node* temp = front;
        printf("Priority Queue elements (in order):\n");
        while (temp != NULL) {
            printf("Value: %d, Priority: %d\n", temp->data, temp->priority);
            temp = temp->next;
        }
    }
}

// Main function with menu-driven interface
int main() {
    int choice, value, priority;

    while (1) {
        printf("\nPriority Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Traverse\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                printf("Enter priority of the value: ");
                scanf("%d", &priority);
                enqueue(value, priority);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                traverse();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
