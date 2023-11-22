#include <stdio.h>
#define MAX 60
struct CQueue
{
    int arr[MAX];
    int front;
    int rear;
};
void initialise(struct CQueue *cq)
{
    cq->front = -1;
    cq->rear = -1;
}

void push(struct CQueue *cq, int val)
{
    if ((cq->front == 0 && cq->rear == MAX - 1) || (cq->front == cq->rear + 1))
    {
        printf("Queue Overflow\n");
        return;
    }
    else if (cq->front == -1 && cq->rear == -1)
    {
        cq->front += 1;
        cq->rear += 1;
        cq->arr[cq->front] = val;
    }
    else
    {
        if (cq->rear == MAX - 1 && cq->front != 0)
        {
            cq->rear = 0;
        }
        else
        {
            cq->rear += 1;
        }
        cq->arr[cq->rear] = val;
    }
}

void pop(struct CQueue *cq)
{
    if (cq->rear - 1 == cq->front)
    {
        printf("Queue Underflow!!");
        return;
    }
    else if (cq->rear == cq->front)
    {
        cq->front = -1;
        cq->rear = -1;
    }
    else
    {
        if (cq->front == MAX - 1)
        {
            cq->front = 0;
        }
        else
        {
            cq->front += 1;
        }
    }
}

void display(struct CQueue *cq)
{
    if (cq->front == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    int i = cq->front;
    do
    {
        printf("%d ", cq->arr[i]);

        if (i == cq->rear)
            break;

        i = (i + 1) % MAX;
    } while (i != (cq->rear + 1) % MAX);
    printf("\n");
}

int front(struct CQueue *cq)
{
    return cq->arr[cq->front];
}

void main()
{
    struct CQueue hh , mh;
    initialise(&hh);
    initialise(&mh);
    int i;
    for (i = 1; i < 13; i++)
    {
        push(&hh, i);
    }
      for (i = 0; i < 60; i++)
    {
        push(&mh, i);
    }

    while (front(&hh) != 12)
    {
        printf("%d:%d\n", front(&hh),front(&mh));
        if (front(&mh) == 59)
        {
            int hfrt = front(&hh);
            pop(&hh);
            push(&hh,hfrt);
        }
         int mfrt = front(&mh);
            pop(&mh);
            push(&mh,mfrt);
    }
}