#include<stdio.h>
#include<stdlib.h>
#define max 100

void push(int stack[], int* top, int item){
    if (* top == max -1){
        printf("Error : Stack if full.\n");
    }else{
        *top = *top+1;
        stack[*top]= item;
    }
}
void pop(int stack[],int* top){
    if (*top ==-1){
        printf("Error : Stack is empty\n");
    }else{
        printf("The latest value is %d",stack[*top -1]);
        *top= *top-1;
    }
}
void display(int stack[], int* top){
    if (*top==-1){
        printf("Error : Stack is Empty.\n");
    }else{
        int temp = *top;
        for (int i =temp;i>=0;i--){
            printf("%d\t",stack[i]);
        }
    }
}

int main(){
    printf("Welcome To the code.\n");
    int choice,item,top =-1,* stack = (int *) calloc(sizeof (int), max) ;
    do {
        printf("Choose the opetion to proceed :\n");
        printf("1: push\n2: pop\n3: display\nChoice : ");
        scanf("%d",&choice);
        
        switch (choice){
            case 1:
                printf("Enter the item : ");
                scanf("%d",&item);
                push(stack,&top,item);
                break;
            case 2:
                pop(stack, &top);
                break;
            case 3:
                display(stack, &top);
                break;
            default :
                exit(1);
                break;
        }
    } while (1);
    return 0;
}