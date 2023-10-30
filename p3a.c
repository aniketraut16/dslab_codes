#include<stdio.h>
#define MAX 10
struct Queue{
char data[MAX];
int front ;
int rear;
};

void initialise(struct Queue *que){
que->front = -1;
que->rear = -1;
}


void enqueue(struct Queue *que,char val){
if(que->front == -1 && que->rear == -1){
que->front = que->front +1;
que->rear = que->rear +1;
que->data[que->front] = val;
}
else if(que->rear == MAX-1){
printf("Queue Overflow!!\n");
}
else{
que->rear = que->rear +1;
que->data[que->rear] = val;
}
}


void dequeue(struct Queue *que){

if(que->front == -1 || que->front > que->rear){
printf("Queue Underflow!!\n");
}
else{
que->front = que->front +1;
}
}

void display(struct Queue *que){
printf("\n");

for(int i = 0 ; i< MAX ;i++){
if(i <= que->rear && i >= que->front ){
printf("| %c ",que->data[i]);
}
else{
printf("|   ");
}
}
printf("|");
printf("\n");
}
void main(){
struct Queue que;
initialise(&que);

enqueue(&que,' ');
enqueue(&que,'A');
enqueue(&que,'B');
enqueue(&que,'C');
enqueue(&que,'D');
enqueue(&que,'E');
dequeue(&que);
display(&que);
enqueue(&que,'F');
display(&que);
dequeue(&que);
dequeue(&que);
display(&que);
enqueue(&que,'G');
display(&que);
enqueue(&que,'H');
display(&que);
dequeue(&que);
dequeue(&que);
dequeue(&que);
dequeue(&que);
display(&que);
enqueue(&que,'I');
display(&que);
}
