#include <stdio.h>
#define MAX 5
int rear = -1;

void print_queue(int queue[])
{
    if (rear == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("front-> ");
    for (int i = 0; i <= rear; i++)
    {
        printf("%d \t", queue[i]);
    }
    printf("<-rear\n");
}

void push(int queue[])
{
    if (rear == MAX - 1)
    {
        printf("Queue overflow\n");
    }
    rear++;
    printf("Enter element to push in queue: ");
    scanf("%d", &queue[rear]);
}

void pop(int queue[])
{
    if (rear > -1)
    {
        for (int i = 0; i < rear; i++)
        {
            queue[i] = queue[i + 1];
        }
        rear--;
        printf("Element popped!\n");
    }
    else
        printf("Queue is empty\n");
}

int main()
{
    int queue[MAX], choice;

    do
    {
        printf("\nPress 1 to push, 2 to pop, 3 to print queue, 4 to exit:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push(queue);
            break;
        case 2:
            pop(queue);
            break;
        case 3:
            print_queue(queue);
            break;
        case 4:
            break;
        default:
            printf("Invalid");
        }
    }while (choice != 4);
}