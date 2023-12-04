// Aniket Raut
// B-22

#include <stdio.h>
#define MAX 5
// Define a stack using structure
struct stack
{
    int arr[MAX];
    int tos;
};
// method to initilize stack
void initilize(struct stack *stk)
{
    stk->tos = -1;
}
// method to push element in stack
void push(struct stack *stk, int val)
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
        printf("%d ", stk->arr[i]);
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
void compare(struct stack *stk, struct stack *stk2)
{
    int i = stk->tos;
    int j = stk2->tos;
    if (i == -1 || j == -1)
    {
        printf("out of two one stack is empty , so no comparision possible!!\n");
        return;
    }
    while (i != -1 && j != -1)
    {
        if (stk->arr[i] > stk2->arr[j])
        {
            printf("top of 1st stack is greater than top of 2nd stack\n");
        }
        else if (stk->arr[i] < stk2->arr[j])
        {
            printf("top of 1st stack is smaller than top of 2nd stack\n");
        }
        else
        {
            printf("top of 1st stack is equal top of 2nd stack\n");
        }
        i--;
        j--;
    }
    if (i != j)
    {
        printf("out of two one stack is empty now so no comparision possible\n");
        return;
    }
}
void main()
{
    struct stack stk;
    struct stack stk2;
    initilize(&stk);
    initilize(&stk2);
    int tempstk1[MAX];
    int tempstk2[MAX];

    printf("Enter Elemnts of Stack1:");
    for (int i = 0; i < MAX; i++)
    {
        scanf("%d", &tempstk1[i]);
    }
    printf("Enter Elemnts of Stack2:");
    for (int i = 0; i < MAX; i++)
    {
        scanf("%d", &tempstk2[i]);
    }

    for (int i = 0; i < MAX; i++)
    {
        push(&stk, tempstk1[i]);
        push(&stk2, tempstk2[i]);
    }
    compare(&stk, &stk2);
}
