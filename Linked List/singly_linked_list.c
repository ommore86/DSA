#include <stdio.h>
#include <stdlib.h>

// Structure of node
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;

// Insert element at the beginning
void insertAtBeginning(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

// Insert element at the end
void insertAtEnd(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Insert element at a specified index
void insertAtIndex(int data, int index)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    if (index == 0)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    struct Node *temp = head;
    for (int i = 1; i < index && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Position out of bounds\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete a node from a specific index
void deleteAtIndex(int index)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;

    if (index == 0)
    {
        head = temp->next;
        free(temp);
        return;
    }

    struct Node *prev = NULL;
    for (int i = 0; i < index && temp != NULL; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Position out of bounds\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Delete a node by value
void deleteNode(int value)
{
    struct Node *temp = head;
    struct Node *prev = NULL;

    if (temp != NULL && temp->data == value)
    {
        head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Value %d not found in the list.\n", value);
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Display linked list
void displayList()
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    insertAtBeginning(3);
    insertAtBeginning(2);
    insertAtBeginning(1);
    printf("List after inserting at beginning: ");
    displayList();

    insertAtEnd(6);
    insertAtEnd(7);
    printf("List after inserting at end: ");
    displayList();

    insertAtIndex(4, 3);
    insertAtIndex(5, 4);
    printf("List after inserting at specific index: ");
    displayList();

    deleteNode(3);
    printf("List after deleting value 3: ");
    displayList();

    deleteAtIndex(2);
    printf("List after deleting index 2 element: ");
    displayList();

    return 0;
}