#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode; // Initial next points to itself for circularity
    return newNode;
}

// Insert at the start
void insertAtStart(int data)
{
    struct Node *newNode = createNode(data);
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
}

// Insert at the end
void insertAtEnd(int data)
{
    struct Node *newNode = createNode(data);
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

// Insert at a specific index
void insertAtIndex(int index, int data)
{
    if (index == 0)
    {
        insertAtStart(data);
        return;
    }
    struct Node *newNode = createNode(data);
    struct Node *temp = head;
    int count = 0;

    while (temp->next != head && count < index - 1)
    {
        temp = temp->next;
        count++;
    }
    if (count == index - 1)
    {
        newNode->next = temp->next;
        temp->next = newNode;
    }
    else
    {
        printf("Index out of bounds\n");
    }
}

// Delete by value
void deleteByValue(int value)
{
    if (head == NULL)
        return;

    struct Node *temp = head;
    struct Node *prev = NULL;
    do
    {
        if (temp->data == value)
        {
            if (prev == NULL)
            { // Node to delete is the head
                struct Node *last = head;
                while (last->next != head)
                {
                    last = last->next;
                }
                if (head->next == head)
                { // Only one node
                    free(head);
                    head = NULL;
                }
                else
                {
                    last->next = head->next;
                    free(head);
                    head = last->next;
                }
            }
            else
            {
                prev->next = temp->next;
                free(temp);
            }
            return;
        }
        prev = temp;
        temp = temp->next;
    } while (temp != head);
}

// Delete by index
void deleteByIndex(int index)
{
    if (head == NULL)
        return;

    struct Node *temp = head, *prev = NULL;
    int count = 0;

    if (index == 0)
    { // Delete head node
        deleteByValue(head->data);
        return;
    }

    do
    {
        if (count == index)
        {
            prev->next = temp->next;
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
        count++;
    } while (temp != head);
    printf("Index out of bounds\n");
}

// Print the list
void printList()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = head;
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

// Main function to demonstrate the operations
int main()
{
    insertAtStart(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtIndex(1, 15);

    printf("List after insertions: ");
    printList();

    deleteByValue(20);
    printf("List after deleting by value 7: ");
    printList();

    deleteByIndex(1);
    printf("List after deleting at index 1: ");
    printList();

    return 0;
}