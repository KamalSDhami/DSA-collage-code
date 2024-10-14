#include<stdio.h>
#include<stdlib.h>

struct queue{
    int front;
    int rear;
    int *arr;
    int size;
};

struct stack {
    struct queue *q1;
    struct queue *q2;
};

void create(struct queue *q,int size){
    q->front=-1;
    q->rear=-1;
    q->arr=(int*)malloc(sizeof(struct queue)* q->size);
}

int isFull(struct queue *q){
    return((q->rear +1)%q->size==q->front);
}

int isEmpty(struct queue *q){
    return(q->front==-1);
}

void enqueue(struct queue *q, int k){
    //base case: overflow
    if(isFull(q)){
        printf("Stack is full\n");
        return;
    }
    if(isEmpty(q)){    //when queue is empty
        q->front=0;
    }
    q->arr[++ q->rear]=k;
}

int dequeue(struct queue *q){
    if(isEmpty(q)){
        printf("Empty queue\n");
        return -1;
    }
    int x=q->arr[q->front];
    if(q->front==q->rear){
        q->front=q->rear=-1;
    }else{
        q->front++;
    }
    return x;
}

void push(struct stack *s){
    int x;
    printf("Enter the element: ");
    scanf("%d",&x);
    
    enqueue(s->q1,x);

    while(!(isEmpty(s->q2))){
        enqueue(s->q1,dequeue(s->q2));
    }

    struct queue *temp=s->q1;
    s->q1=s->q2;
    s->q2=temp;
    /*
    Explanation of the function:
    1. Enqueue the element in q1
    2. Dequeue all the elements from q2 and enqueue them in q1
    3. Swap the names of q1 and q2
    why swap?
    1. To make the q1 always empty
    2. To make the q2 always have the elements in the order of stack

    */
}

int pop(struct stack *s){
    if(isEmpty(s->q2)){
        printf("Empty stack\n");
        return -1;
    }
    return dequeue(s->q2);
}

void print(struct stack *s){
    if(isEmpty(s->q2)){
        printf("Empty stack\n");
        return;
    }
    for(int i=s->q2->front; i<= s->q2->rear; i++){
        printf("%d\t",s->q2->arr[i]);
    }
    printf("\n");
}

int main(){
    struct queue q1,q2;
    int size;
    printf("Enter the size: ");
    scanf("%d",&size);
    create(&q1,size);
    create(&q2,size);

    struct stack s;
    s.q1=&q1;
    s.q2=&q2;

    do{
        int choice;
        printf("Enter your choice:\n");
        printf("1. Push\n2. Pop\n3. Print\n4. Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                push(&s);
                break;
            case 2:
                printf("Popped: %d\n",pop(&s));
                break;
            case 3:
                printf("Printing the stack:\n");
                print(&s);
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }while(1);
}