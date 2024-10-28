#include <stdio.h>
#include <stdlib.h>

// Node Structure
struct Node
{
    int data;
    struct Node *next;
};
struct Node *front = NULL;
struct Node *rear = NULL;

// Insertion of element (Enqueue)
void enqueue(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (rear == NULL)
    { // if queue is empty
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

// Deletion of element (Dequeue)
void dequeue()
{
    struct Node *temp;
    if (front == NULL)
    {
        printf("Queue is empty\n");
    }

    // Queue only has one element
    if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        temp = front;
        front = front->next;
        printf("%d is deleted\n", temp->data);
        free(temp);
    }
}

// Peek
void peek()
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Front element in queue is %d\n", front->data);
    }
}

// Display
void display()
{
    struct Node *temp;
    if (front == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        temp = front;
        while (temp != NULL)
        {
            printf("%d->", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void main()
{
    int choice, ele;

    do
    {
        printf("\n1.Enqueue\t2.Dequeue\t3.Peek\t4.Display\t5.Exit: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element to enqueue: ");
            scanf("%d", &ele);
            enqueue(ele);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            peek();
            break;

        case 4:
            display();
            break;

        case 5:
            printf("Thank you\n");
            break;

        default:
            printf("Enter valid choice!\n");
            break;
        }
    } while (choice != 5);
}