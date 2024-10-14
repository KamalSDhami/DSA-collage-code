#include<stdio.h>
#include<malloc.h>
#include<stdio.h>

typedef struct queue{
    int size;
    int *arr;
    int rear;
    int front;
}que;
void create (que *qu){
    printf("Enter the size of the array : ");
    scanf("%d",&qu->size);
    qu->arr = (int *) malloc((
        
        (qu->size)-1) * sizeof(int));
    qu->front=-1;
    qu->rear =-1;
}

void insert(que *qu){
    if (qu->rear > (qu->size)-2 ){
        printf("\n----------------------------\nOverflow\n----------------------------\n");
    }else{
        int item;
        printf("Enter the element you want to insurt : ");
        scanf("%d",&item);
        if (qu->rear ==-1){
            qu->front = qu->rear =0;
        }else{
            qu->rear = qu->rear +1;
        }
        qu->arr[qu->rear]= item;
    }
}
void reverce(que *qu){
    int p1 =qu->front,p2 = qu->rear,temp;
    while (p1<p2){
        temp = qu->arr[p1];
        qu->arr[p1++]= qu->arr[p2];
        qu->arr[p2--]= temp;
    }
}
void transverse (que *qu){
	if(qu->rear == -1){
		printf("\n----------------------------\nError : array is empty.\n----------------------------\n");
	}else{
		for (int i =qu->front;i <= qu->rear;i++){
			printf("%d\t",qu->arr[i]);
		}
	}printf("\n");
}
void delete(que *qu){
    if (qu->rear == -1){
        printf("\n----------------------------\nUnderflow\n----------------------------\n");
        return;
    }
    printf("Deleting the %d from queue \n",qu->arr[qu->front]);
    if (qu->front == qu->rear){
        qu->front=qu->rear = -1;
    }else{
        qu->front = qu->front +1;
    }
}
int isEmpty(que *qu){
    return qu->front==qu->rear;
}
void insurtfront(que *qu){
    if (qu->rear > (qu->size)-2 ){
        printf("\n----------------------------\nOverflow\n----------------------------\n");
    }else{
        if (qu->rear ==-1){
            qu->front = qu->rear =0;
        }else if (qu->rear == qu->size-1){
            printf("overflow");
        }
        else{
            for (int j = qu->rear;j>=0;j--){
                qu->arr[j+1]= qu->arr[j];
            }
        }
        printf("Enter the enement : ");
        scanf("%d",&qu->arr[0]);
        qu->rear = qu->rear +1;

    }
    if (dq->front ==-1) {
        printf("Over flow ");
    }
    else{
        dq->dq[dq->front]=x;
        dq->front--;
    }
}
void deleteback(que *qu){
    int x =-1;
    if (isEmpty(&qu)){
        printf("\n----------------------------\nUnderflow\n----------------------------\n");
        return;
    }
    // printf("Deleting the %d from queue \n",qu->arr[qu->front]);
    // if (qu->front == qu->rear){
    //     qu->front=qu->rear = -1;
    // }else{
    //     qu->rear = qu->rear-1;
    // }
    else{
        x = qu->arr[qu->rear];
        qu->rear--;
        }
    return x;
}
int main(){
    que qu;
    create(&qu);
    int choice;
    do {
        printf("1) enque\n2)display\n3)delete\n4)reverse\n5)Insurt front\n6)delete back\n7)exit\n");
        printf("Enter the choidce : ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            insert(&qu);
            break;
        case 2:
            transverse(&qu);
            break;
        case 3:
            delete(&qu);
            break;
        case 4:
            reverce(&qu);
            break;
        case 5:
            insurtfront(&qu);
            break;
        case 6:
            deleteback(&qu);
            break;
        case 7:
            exit(0);
            break;
        default:
            printf("\n----------------------------\ninvalid input\n----------------------------\n");
            break;
        }

    }while ((1));
    

    return 0;
}