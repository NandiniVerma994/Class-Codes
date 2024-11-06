//Input-Restricted Deque: Allows insertion only at the rear but allows deletion from both front
// and rear.
//Output-Restricted Deque: Allows deletion only from the front but allows insertion at both front
// and rear.

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5  // Define the maximum size of the deque

int deque[SIZE];
int front = -1, rear = -1;

// Function to check if the deque is empty
int isEmpty() {
    return front == -1;
}

// Function to check if the deque is full
int isFull() {
    return (front == 0 && rear == SIZE - 1) || (front == rear + 1);
}

// Function to insert an element at the rear
void enqueueRear(int value) {
    if (isFull()) {
        printf("Deque is full. Cannot enqueue at rear.\n");
    } else {
        if (isEmpty()) {
            front = rear = 0;
        } else if (rear == SIZE - 1) {
            rear = 0;  // Wrap around
        } else {
            rear++;
        }
        deque[rear] = value;
        printf("Enqueued %d at rear.\n", value);
    }
}

// Function to insert an element at the front
void enqueueFront(int value) {
    if (isFull()) {
        printf("Deque is full. Cannot enqueue at front.\n");
    } else {
        if (isEmpty()) {
            front = rear = 0;
        } else if (front == 0) {
            front = SIZE - 1;  // Wrap around
        } else {
            front--;
        }
        deque[front] = value;
        printf("Enqueued %d at front.\n", value);
    }
}

// Function to delete an element from the front
void dequeueFront() {
    if (isEmpty()) {
        printf("Deque is empty. Cannot dequeue from front.\n");
    } else {
        printf("Dequeued %d from front.\n", deque[front]);
        if (front == rear) {  // Queue becomes empty
            front = rear = -1;
        } else if (front == SIZE - 1) {
            front = 0;  // Wrap around
        } else {
            front++;
        }
    }
}

// Function to delete an element from the rear
void dequeueRear() {
    if (isEmpty()) {
        printf("Deque is empty. Cannot dequeue from rear.\n");
    } else {
        printf("Dequeued %d from rear.\n", deque[rear]);
        if (front == rear) {  // Queue becomes empty
            front = rear = -1;
        } else if (rear == 0) {
            rear = SIZE - 1;  // Wrap around
        } else {
            rear--;
        }
    }
}

// Function to get the front element
void peekFront() {
    if (isEmpty()) {
        printf("Deque is empty. No front element.\n");
    } else {
        printf("Front element is %d.\n", deque[front]);
    }
}

// Function to get the rear element
void peekRear() {
    if (isEmpty()) {
        printf("Deque is empty. No rear element.\n");
    } else {
        printf("Rear element is %d.\n", deque[rear]);
    }
}

// Function to display the elements of the deque
void display() {
    if (isEmpty()) {
        printf("Deque is empty.\n");
    } else {
        printf("Deque elements: ");
        int i = front;
        while (1) {
            printf("%d ", deque[i]);
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        printf("\n");
    }
}

// Main function with menu-driven interface for both types of deques
int main() {
    int choice, value;
    int dequeType;

    printf("Choose Deque Type:\n");
    printf("1. Input-Restricted Deque\n");
    printf("2. Output-Restricted Deque\n");
    printf("Enter your choice: ");
    scanf("%d", &dequeType);

    while (1) {
        printf("\nDeque Operations:\n");
        printf("1. Enqueue at Rear\n");
        if (dequeType == 2) {
            printf("2. Enqueue at Front\n");
        }
        printf("3. Dequeue from Front\n");
        if (dequeType == 1) {
            printf("4. Dequeue from Rear\n");
        }
        printf("5. Peek Front\n");
        printf("6. Peek Rear\n");
        printf("7. IsEmpty\n");
        printf("8. IsFull\n");
        printf("9. Display\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue at rear: ");
                scanf("%d", &value);
                enqueueRear(value);
                break;
            case 2:
                if (dequeType == 2) {
                    printf("Enter value to enqueue at front: ");
                    scanf("%d", &value);
                    enqueueFront(value);
                } else {
                    printf("Invalid option for input-restricted deque.\n");
                }
                break;
            case 3:
                dequeueFront();
                break;
            case 4:
                if (dequeType == 1) {
                    dequeueRear();
                } else {
                    printf("Invalid option for output-restricted deque.\n");
                }
                break;
            case 5:
                peekFront();
                break;
            case 6:
                peekRear();
                break;
            case 7:
                printf(isEmpty() ? "Deque is empty.\n" : "Deque is not empty.\n");
                break;
            case 8:
                printf(isFull() ? "Deque is full.\n" : "Deque is not full.\n");
                break;
            case 9:
                display();
                break;
            case 10:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
