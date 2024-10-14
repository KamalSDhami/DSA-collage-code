#include<stdio.h>
#include<stdlib.h>

struct queue{
    int front;
    int rear;
    int *arr;
    int size;
};

void create(struct queue *q){
    q->front=-1;
    q->rear=-1;
    printf("Enter the size: ");
    scanf("%d",&(q->size));
    q->arr=(int*)malloc(sizeof(struct queue)* q->size);
}

int isFull(struct queue *q){
    return((q->rear +1)%q->size==q->front);
}

int isEmpty(struct queue *q){
    return(q->front==-1);
}

void enqueue(struct queue *q, int k){
    if(isFull(q)){
        printf("Queue is full\n");
        return;
    }
    if(isEmpty(q)){
        q->front=0;
    }
    q->rear=(q->rear+1)%q->size;
    q->arr[q->rear]=k;
}

void dequeue(struct queue *q){
    if(isEmpty(q)){
        printf("Queue is empty\n");
        return;
    }
    if(q->front==q->rear){  //when only one element is present
        q->front=q->rear=-1;
    }else{
        q->front=(q->front+1)%q->size;
    }
}

void tellSize(struct queue *q){
    if(isEmpty(q)){
        printf("Queue is empty\n");
        return;
    }
    int size;
    if (q->rear >= q->front) {
        size = q->rear - q->front + 1;
    } else {
        size = q->size - q->front + q->rear + 1;
    }
    printf("Size of queue is %d\n", size);
}

void printQueue(struct queue *q){
    if(isEmpty(q)){
        printf("Queue is empty\n");
        return;
    }
    int i=q->front;
    while(i!=q->rear){
        printf("%d ",q->arr[i]);
        i=(i+1)%q->size;    //circular increment
    }
    printf("%d\n",q->arr[q->rear]);
}


int main(){
    struct queue q;
    create(&q);
    int choice,k;
    do{
        printf("Enter choice: \n1) Enqueue\n2) Dequeue\n3) Tell current size\n4) Print\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d",&k);
                enqueue(&q,k);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                tellSize(&q);
                break;
            case 4:
                printQueue(&q);
                break;
            // case 5:
            //     reverse(&q);
            //     break;
            default:
                exit(0);
        }
    }while(1);
}