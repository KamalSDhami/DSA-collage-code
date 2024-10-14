#include  <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct dequeue{
    int max;
    int *dq;
    int front;
    int rear;
};

void create_dequeue(struct dequeue *qu) {
    printf("Enter the size of the queue: ");
    scanf("%d",&qu->max);
    qu->dq = (int *) malloc(qu->max * sizeof(int));
    qu->front = -1;
    qu->rear =-1;
}

void insurt_front(struct dequeue *qu,int item){
    if (qu->front == (qu->rear +1)%qu->max){
        printf("Error : Queue Overflow\n");
        return;
    }
    if(qu->front ==-1){
        qu->front = 0;
        qu->rear =0;
    }else if(qu->front ==0 ){
        qu->front = qu->max -1;
    }else{
        qu->front = qu->front-1;
    }
    qu->dq[qu->front]= item;
}
void insurt_rare(struct dequeue *qu,int item){
    if (qu->front == (qu->rear +1)%qu->max){
        printf("Error : Queue Overflow\n");
        return;
    }
    if(qu->front ==-1){
        qu->front = 0;
        qu->rear =0;
    }else if(qu->rear == qu->max-1){
        qu->rear = qu->rear +1;
    }else{
        qu->rear= qu->rear +1;
    }
    qu->dq[qu->rear] = item;
}
void dequeue_front (struct dequeue *qu){
    if (qu->front ==-1){
        printf("Error Underflow\n");
        return;
    }
    if(qu->front == qu->rear){
        qu->front =-1;
        qu->rear = -1;
    }else if(qu->front == qu->max-1){
        qu->front =0;
    }else{
        qu->front = qu->front +1;
    }
}
void dequeue_rair(struct dequeue *qu){
    if (qu->front ==-1){
        printf("Error Underflow\n");
        return;
    }
    if(qu->front == qu->rear){
        qu->front =-1;
        qu->rear = -1;
    }else if(qu->rear ==0){
        qu->rear = qu->max -1;
    }else{
        qu->rear = qu->rear -1;
    }
}
void display_queue(struct dequeue *qu){
    if (qu->front == -1){
        printf("Error : Underflow \n");
    }else{
        printf("Deque element are : ");
        int i = qu->front;
        do{
            printf("%d ",qu->dq[i]);
            if (i==qu->rear){
                break;
            }
            i= (i+1)% qu->max;
        }while (1);
        printf("\n");
    }
}

int user_input(){
    int value;
    printf("Ther the value : ");
    scanf("%d",&value);
    return value;
}


int main(){
    int choice;
    struct dequeue qu;
    create_dequeue(&qu);

    do {
        printf("Enter Your choice\n1)Inqueue_front\n2)Inqueue_rear\n3)dequeue_front\n4)dequeue_back\n5)Display\n6)exit\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            insurt_front(&qu,user_input());
            break;
        case 2:
            insurt_rare(&qu,user_input());
            break;
        case 3:
            dequeue_front(&qu);
            break;
        case 4:
            dequeue_rair(&qu);
            break;
        case 5:
            display_queue(&qu);
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("Invalid Input.\n");
        }
    }while(1);

    return 0;
}