#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *ptr;
};

struct Node *top = 0;

void push(){
    int val;
    printf("Enter element: ");
    scanf("%d", &val);

    struct Node *newnode = (struct Node*) malloc(sizeof(struct Node));
    newnode->data = val;
    newnode->ptr = top;
    top = newnode;
}

void pop(){
    struct Node *temp;
    temp = top;

    if(top == 0){
        printf("Underflow!\n");
    }
    else{
        printf("Element %d is popped \n", top->data);
        top = top->ptr;
        free(temp);
    }
}

void peek(){
    if(top == 0){
        printf("Stack is empty!\n");
    }
    else{
        printf("Peeked element is: %d\n", top->data);
    }
}

void display(){
    struct Node *temp;
    temp = top;

    if (top == 0){
        printf("Stack is empty!\n");
    }
    else{
        printf("Elements in stack are: \n");
        while(temp!=0){
            printf("%d\n", temp->data);
            temp = temp->ptr;
        }
    }
}

int main(){
    int ch;

    do
    {
        printf("\nEnter Choice: 1-PUSH  2-POP 3-PEEK   4-DISPLAY   5-EXIT\n");
        scanf("%d", &ch);

        switch(ch){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("EXIT");
                break;
            default:
            printf("Please enter the valid choice!\n");
        }
    } while (ch!=5);

    return 0;
}