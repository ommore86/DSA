#include <stdio.h>
#define N 5
int stk[N];
int top = -1;

void push(){
   int n;

   if(top == N-1){
      printf("Stack Overflow!\n");
   }
   else{
      printf("Enter element: ");
      scanf("%d", &n);
      top++;
      stk[top] = n;
   }
}

void pop(){
   if(top == -1){
      printf("Stack Underflow!\n");
   }
   else{
      int del_value = stk[top];
      printf("Popped value is: %d\n", del_value);
      top--;   
   }
}

void peek(){
   if(top == -1){
      printf("Stack Underflow!");
   }
   else{
      printf("Peek value is: %d\n", stk[top]);   
   }
}

void display(){
   printf("Elements in stack are: \n");
   for(int i=top; i>=0; i--){
      printf("stk[%d] = %d\n", i, stk[i]);
   }
}

int main() {
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
         printf("Please enter the valid choice");
      }
   } while (ch!=5);

   return 0;
}