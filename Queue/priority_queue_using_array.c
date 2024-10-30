#include <stdio.h>

#define MAX 100

// Structure for a priority queue element
struct Element {
    int data;
    int priority;
};

struct Element queue[MAX];
int index = 0;

// Function to insert an element into the priority queue
void insert(int data, int priority) {
    if (index >= MAX) {
        printf("Queue Overflow\n");
        return;
    }
    
    // Create a new element and add it at the end
    queue[index].data = data;
    queue[index].priority = priority;
    index++;
}

// Function to delete the element with the highest priority
void deleteHighestPriority() {
    if (index == 0) {
        printf("Queue Underflow\n");
        return;
    }
    
    // Find the element with the highest priority
    int highestPriorityIndex = 0;
    for (int i = 1; i < index; i++) {
        if (queue[i].priority < queue[highestPriorityIndex].priority) {
            highestPriorityIndex = i;
        }
    }
    
    // Remove the element with the highest priority by shifting elements
    printf("Removed element with data %d and priority %d\n", queue[highestPriorityIndex].data, queue[highestPriorityIndex].priority);
    for (int i = highestPriorityIndex; i < index - 1; i++) {
        queue[i] = queue[i + 1];
    }
    index--;
}

// Function to display all elements in the priority queue
void display() {
    if (index == 0) {
        printf("Queue is empty\n");
        return;
    }
    
    printf("Queue elements (data, priority):\n");
    for (int i = 0; i < index; i++) {
        printf("(%d, %d) ", queue[i].data, queue[i].priority);
    }
    printf("\n");
}

// Main function to test the priority queue
int main() {
    insert(10, 2);
    insert(30, 1);
    insert(20, 3);
    
    display();
    
    deleteHighestPriority();
    
    display();
    
    return 0;
}