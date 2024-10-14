#include<stdio.h>
#include<malloc.h>
struct queue{
    int size;
    int front;
    int rear;
    int *arr;
};

void create (struct queue qu){
printf("Enter teh size: ");
scanf("%d",&qu->size);
qu->top=-1;
qu->rear =-1;
qu->qu(int*)malloc(qu->size*sizeof(int))
}
void enqueue(int x,struct queue q){
    if (rear ==q->size-1){
        printf("overfolow")
    }
}
void dequeue(struct queue q){
    int a = -1;
    if (rear ==q->size-1){
        printf("")
    }else{qu-> front ++}{
        x = q->arr[q->fornt];
    }
    return x;
}

int main(){
    struct queue q;
    create(sq);
    
}