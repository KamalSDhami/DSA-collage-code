#include<stdio.h>
#include<stdlib.h>
#define max 10

void enqueue(int queue[], int* front, int* rare){
	if (*rare==max-1){
		printf("Error : Queue Overflow.\n");
		exit(0);
	}
	int item;
	printf("Enter the value you want to insuret : ");
	scanf("%d",&item);
	if(*rare == -1 ){
		*front = *rare = 0;
	}else{
		*rare = *rare +1;
	}
	queue[*rare]= item;
}

void dequeue(int queue[],int* front,int* rare){
	if(*rare == -1){
		printf("Error : Queue Underflow\n");
		exit(0);
	}
	printf("Deleating the %d form Queue.\n",queue[*front]);
	if (*front == * rare){
		*front = * rare = -1;
	}
	else{
		*front = *front +1;
	}
}

void transverse (int queue[], int* front, int* rear){
	if(*rear == -1){
		printf("Error : array is empty.\n");
	}else{
		for (int i =*front;i <= *rear;i++){
			printf("%d\t",queue[i]);
		}
	}
}

int main(){
	printf("Welcome To the code.\n");
    int choice,front,rare =-1,* queue = (int *) calloc(sizeof (int), max) ;
    do {
        printf("Choose the opetion to proceed :\n");
        printf("1: Enqueue\n2: Deque\n3: display\nChoice : ");
        scanf("%d",&choice);
        
        switch (choice){
            case 1:
                enqueue(queue,&front,&rare);
                break;
            case 2:
                dequeue(queue,&front,&rare);
                break;
            case 3:
                transverse(queue,&front,&rare);
                break;
            default :
                exit(1);
                break;
        }
    } while (1);
	return 0;
}