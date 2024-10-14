#include<stdio.h>
#include<stdlib.h>

struct stack{
int top ;
int * s;
int size;
};
void create (struct stack *st ){
    printf("Enter the size of stack: ");
    scanf("%d",&st ->size);
    st -> top = -1;
    st ->s = (int* )malloc (st->size * sizeof (int));
}

void push(struct stack *st, int x){
    if (st -> top == st->size -1){
        printf("Error : Stack is full.\n");
    }else{
       st -> top++;
       st->s[st->top]= x;
        printf("%d pushed onto the stack\n",x);
    }
}
int pop(struct stack *st){
    int x = -1;
    if (st->top ==-1){
        printf("Stack underflow\n");
    }else{
        x = st->s[st->top];
        st-> top--;
        printf("%d poped from the stack\n",x);
    }
    return x;
}
int size(struct stack *st){
    return st->top +1;
}

void display(struct stack st){
    if (st.top ==-1){
        printf("Stack is empty \n");
    }
    else{
        printf("stack element: \n");
        for (int i = st.top;i>= 0;i--){
            printf("%d ",st.s[i]);
        }
        printf("\n");
    }
}

int main(){
    printf("Welcome To the code.\n");
    int choice,value ;
    struct stack st;
    create(&st);
    do {
        printf("Choose the opetion to proceed :\n");
        printf("1: push\n2: pop\n3: to claculate size\n4)to exit\n5)Display\nChoice : ");
        scanf("%d",&choice);
        
        switch (choice){
            case 1:
                printf("Enter the item : ");
                scanf("%d",&value);
                push(&st,value);
                break;
            case 2:
                pop(&st);
                break;
            case 3:
                printf("Current stack size: %d\n",size(&st));
                break;
            case 4:
            printf("exiting...\n");
            exit(1);
            break;
            case 5: 
            display(st);
            break;
            default :
                printf("Invalid choice please try again.\n");
                break;
        }
    } while (1);
    return 0;
}