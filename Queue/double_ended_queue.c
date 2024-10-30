#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // maximum size of deque

int deque[MAX];
int front = -1, rear = -1;

// Check if the deque is full
int isFull() {
    return ((front == 0 && rear == MAX - 1) || front == rear + 1);
}

// Check if the deque is empty
int isEmpty() {
    return (front == -1);
}

// Insert at the front end of deque
void insertFront(int x) {
    if (isFull()) {
        printf("Deque is full. Insertion failed.\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else if (front == 0) {
        front = MAX - 1;
    } else {
        front--;
    }
    deque[front] = x;
}

// Insert at the rear end of deque
void insertRear(int x) {
    if (isFull()) {
        printf("Deque is full. Insertion failed.\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else if (rear == MAX - 1) {
        rear = 0;
    } else {
        rear++;
    }
    deque[rear] = x;
}

// Delete from the front end of deque
void deleteFront() {
    if (isEmpty()) {
        printf("Deque is empty. Deletion failed.\n");
        return;
    }
    printf("Deleted %d from front\n", deque[front]);
    if (front == rear) {
        front = rear = -1;
    } else if (front == MAX - 1) {
        front = 0;
    } else {
        front++;
    }
}

// Delete from the rear end of deque
void deleteRear() {
    if (isEmpty()) {
        printf("Deque is empty. Deletion failed.\n");
        return;
    }
    printf("Deleted %d from rear\n", deque[rear]);
    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = MAX - 1;
    } else {
        rear--;
    }
}

// Display the deque
void display() {
    if (isEmpty()) {
        printf("Deque is empty.\n");
        return;
    }
    printf("Deque: ");
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

// Main function
int main() {
    insertRear(1);
    insertRear(2);
    insertFront(3);
    display();
    
    deleteFront();
    display();
    
    deleteRear();
    display();
    
    insertFront(4);
    display();
    
    return 0;
}