#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    return stack[top--];
}

// Check the precedence of operators
int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

void infixToPostfix(char *exp)
{
    for (int i = 0; exp[i] != '\0'; i++)
    {
        char ch = exp[i];

        // If the character is an operand, add it to output
        if (isalnum(ch))
        {
            printf("%c", ch);
        }
        // If the character is '(', push it to the stack
        else if (ch == '(')
        {
            push(ch);
        }
        // If the character is ')', pop and output until '(' is found
        else if (ch == ')')
        {
            while (stack[top] != '(')
            {
                printf("%c", pop());
            }
            pop(); // Remove '(' from stack
        }
        // If an operator is found
        else
        {
            while (top != -1 && precedence(stack[top]) >= precedence(ch))
            {
                printf("%c", pop());
            }
            push(ch);
        }
    }

    // Pop all the remaining operators in the stack
    while (top != -1)
    {
        printf("%c", pop());
    }
    printf("\n");
}

int main()
{
    char exp[MAX];
    printf("Enter infix expression: ");
    scanf("%s", exp);
    printf("Postfix expression: ");
    infixToPostfix(exp);
    return 0;
}