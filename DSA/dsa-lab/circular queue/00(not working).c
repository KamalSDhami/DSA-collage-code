#include <stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct circular_queue{
    int front ;
    int rear;
    int size;
    int *arr ;
    
}scq;

void create (scq *q){
    printf ("ENter the size of circular queue: ");
    scanf("%d",&q->size);
    q->front = q-> rear =-1;
    q->arr = (int *) malloc (sizeof(int) * q->size);
}
int is_full (scq *q){
    return ((q->rear +1)%q->size == q->front);
}
int is_empty(scq* q){
    return (q->front ==-1);
}

void enqueu (scq *q){
    if (is_full(q)){
        printf("Circular queue is full ! \n");
        return ;
    }
    if (is_empty(q)){
        q->front= q->rear =0 ;
    }else{
        q->rear = (q->front +1)%q->size;
    }
    printf("Enter the element : ");
    scanf("%d",q->arr[q->rear]);
}
int dequeue(scq *q){
    if (is_empty(q)){
        printf("Circular queue is empty !\n");
        return -1;
    }
    int temp = q->arr[q->front];
    if (q->front ==q->rear){
        q->front = q->rear =-1;
    }else{
        q->front = q->front +1;
    }
}
void display(scq* q){
    if (q->rear ==-1){
        printf("Error array is empty \n");
    }else{
        for (int i = q->front ; i<= q->rear ; i++){
            printf("%d ",q->arr[i]);
        }
    }
}

int main(){
    scq q;
    int choice;
    create(&q);
    do {
        printf("1) push \n2)pop \n3)display \n4)exit ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            enqueu(&q);
            break;
        case 2 :
            dequeue(&q);
            break;
        case 3 : 
            display(&q);
            break;
        case 4: 
            exit(1);
        default:
            printf("Invalid info ");
            break;
        }
    }while (1);
}