#include <stdio.h>
#define MAX 5

int front = -1;
int rear = -1;
int my_queue[MAX];

void print_queue()
{
    if (front == -1)
    {
        printf("Circular queue is empty\n");
        return;
    }

    int i = front;
    while (i != rear)
    {
        printf("%d -> ", my_queue[i]); // Print elements until the rear
        i = (i + 1) % MAX;             // Circular increment
    }
    printf("%d -> NULL\n\n", my_queue[rear]); // Print the last element
}

void push()
{
    if ((rear + 1) % MAX == front)
    {
        printf("Circular queue overflow\n");
        return;
    }

    int ele;
    printf("Enter element to push in circular queue: ");
    scanf("%d", &ele);
    if (front == -1 && rear == -1)
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear + 1) % MAX;
    }
    my_queue[rear] = ele;
}

void pop()
{
    if (front == -1)
    {
        printf("Circular queue is empty\n");
        return;
    }
    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }
}

int main()
{
    int choice = 0, ele;

    while (choice != 4)
    {
        printf("\nPress 1 to push, 2 to pop, 3 to print queue, 4 to exit: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            print_queue();
            break;
        case 4:
            break;
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}