//validate bracket 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack{
int top ;
char * s;
int size;
};
void create (struct stack *st ){
    // printf("Enter the size of stack: ");
    // scanf("%d",&st ->size);
    st ->size = 100;
    st -> top = -1;
    st ->s = (char* )malloc (st->size * sizeof (char));
}

void push(struct stack *st, int x){
    if (st -> top == st->size -1){
        printf("Error : Stack is full.\n");
    }else{
       st -> top++;
       st->s[st->top]= x;
    }
}
int pop(struct stack *st){
    int x = -1;
    if (st->top ==-1){
        printf("Stack underflow\n");
    }else{
        x = st->s[st->top];
        st-> top--;
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
    int times;
    printf("Enter thimes you want to run it : ");
    scanf("%d",&times);
    int count =0;
    for (int j = 0; j<times;j++){
    char br[st.size];
        fflush(stdin);
        scanf("%s",br);
        for (int i = 0; i< st.size;i++){
            if (br[i]=='('||br[i]=='{'||br[i]=='['){
                push(&st,br[i]);
            }else if(st.s[st.top] =='(' &&(br[i]==')')||(st.s[st.top] =='{' &&br[i]=='}')||(st.s[st.top] =='[' &&br[i]==']')){
                pop(&st);
            }else{
                break;
            }
        }
        display(st);
        count = (strlen(br) -(st.top+1)) -count;
        printf("strlen %d - %d -%d = %d\n",strlen(br),st.top+1,count,(strlen(br) -(st.top+1)) -count);
        printf("Count: %d\n",count);
    }
    return 0;
}