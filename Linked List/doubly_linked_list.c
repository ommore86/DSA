#include <stdio.h>
#include <stdlib.h>

// struct Node structure for doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Node *head = NULL;

// Function to insert at the beginning
void insertAtBeginning(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    newNode->prev = NULL;
    
    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
}

// Function to insert at the end
void insertAtEnd(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }
    
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to insert at a specified index
void insertAtIndex(int data, int index) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    
    if (index == 0) {
        insertAtBeginning(data);
        return;
    }
    
    struct Node* temp = head;
    for (int i = 0; temp != NULL && i < index - 1; i++) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Index out of bounds.\n");
        return;
    }
    
    newNode->next = temp->next;
    newNode->prev = temp;
    
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    
    temp->next = newNode;
}

// Function to delete at beginning
void deleteAtBeginning(){
    if (head == NULL) {
        printf("List is empty");
        return;
    }

    struct Node* temp = head;

    head = temp->next;
    temp->next->prev = NULL;
    free(temp);
}

// Function to delete at end
void deleteAtEnd(){
    struct Node* temp = head;

    while (temp->next != NULL){
        temp = temp->next;
    }

    temp->prev->next = NULL;
    free(temp);
}

// Function to delete by index
void deleteByIndex(int index) {
    if (head == NULL) return;
    
    struct Node* temp = head;
    
    if (index == 0) {
        head = temp->next;
        if (head != NULL) (head)->prev = NULL;
        free(temp);
        return;
    }
    
    for (int i = 0; temp != NULL && i < index; i++) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Index out of bounds.\n");
        return;
    }
    
    if (temp->next != NULL) temp->next->prev = temp->prev;
    if (temp->prev != NULL) temp->prev->next = temp->next;
    
    free(temp);
}

// Function to delete by value
void deleteByValue(int value) {
    struct Node* temp = head;
    
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Value not found.\n");
        return;
    }
    
    if (temp->next != NULL) temp->next->prev = temp->prev;
    if (temp->prev != NULL) temp->prev->next = temp->next;
    else head = temp->next; // if deleting the head node
    
    free(temp);
}

// Function to display the list
void display() {
    struct Node* temp =head;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Forward Traversal
void forwardTraversal() {
    struct Node* temp = head;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Backward Traversal
void backwardTraversal() {
    struct Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }

    printf("\n");
}

// Searching
void search(int value){
    struct Node* temp = head;
    int index;

    for (index = 0; temp != NULL && temp->data != value; index++){
        temp = temp->next;
    }

    if (temp == NULL){
        printf("Value not found");
        return;
    }

    printf("Element %d found at index %d", value, index);
}


// Main function
int main() {

    // Inserting nodes - at beginning, at end and at specific index
    insertAtBeginning(50);
    insertAtBeginning(40);
    insertAtBeginning(30);
    insertAtBeginning(20);
    insertAtBeginning(10);
    insertAtEnd(60);
    insertAtEnd(70);
    insertAtEnd(80);
    insertAtIndex(52, 5);
    insertAtIndex(54, 6);
    insertAtIndex(56, 7);
    
    printf("List after insertions: ");
    display();

    // Displaying list by forward traversal
    printf("Forward Traversal: ");
    forwardTraversal();

    // Displaying list by backward traversal
    printf("Backward Traversal: ");
    backwardTraversal();

    // Delete at beginning
    deleteAtBeginning();
    printf("List after deletion at beginning: ");
    display();

    // Delete at end
    deleteAtEnd();
    printf("List after deletion at end: ");
    display();

    // Deleting by index
    deleteByIndex(2);
    printf("List after deleting by index 2: ");
    display();

    // Deleting by value
    deleteByValue(54);
    printf("List after deleting by value 54: ");
    display();

    //Searching
    search(56);

    return 0;
}