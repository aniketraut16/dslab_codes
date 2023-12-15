// Aniket Raut
// B-22

#include <stdio.h>
#define MAX 20

// Define a stack using structure
struct stack
{
    char arr[MAX];
    int tos;
};

// method to initilize stack
void initilize(struct stack *stk)
{
    stk->tos = -1;
}

// method to push element in stack
void push(struct stack *stk, char val)
{

    if (stk->tos == MAX - 1)
    { // checking for overflow condition
        printf("Stack overflow!!\n");
        return;
    }
    stk->tos++;
    stk->arr[stk->tos] = val;
}

// method to display stack
void display(struct stack *stk)
{
    for (int i = stk->tos; i >= 0; i--)
    {
        printf("%c ", stk->arr[i]);
    }
    printf("\n");
}

// method to pop element in stack
void pop(struct stack *stk)
{
    if (stk->tos == -1)
    {
        printf("Stack Underflow!!\n");
        return;
    }
    stk->tos--;
}

char tos(struct stack *stk)
{
    if (stk->tos != -1)
    {
        return stk->arr[stk->tos];
    }
}

void main()
{
    struct stack stk;
    initilize(&stk);
    char expression[100];
    printf("Enter any Exprression");
    scanf("%s", expression);
    int isValid = 1;
    int i = 0;
    while (expression[i] != '\0')
    {
        if (expression[i] == '[' || expression[i] == '(' || expression[i] == '{')
        {
            push(&stk, expression[i]);
        }
        if (expression[i] == ']')
        {
            if (tos(&stk) == '[')
            {
                pop(&stk);
            }
            else
            {
                isValid = 0;
                break;
            }
        }
        else if (expression[i] == '}')
        {
            if (tos(&stk) == '{')
            {
                pop(&stk);
            }
            else
            {
                isValid = 0;
                break;
            }
        }
        else if (expression[i] == ')')
        {
            if (tos(&stk) == '(')
            {
                pop(&stk);
            }
            else
            {
                isValid = 0;
                break;
            }
        }

        i++;
    }
    if (isValid)
    {
        printf("Expression is valid \n");
    }
    else
    {
        printf("Expression is not valid \n");
    }
}
