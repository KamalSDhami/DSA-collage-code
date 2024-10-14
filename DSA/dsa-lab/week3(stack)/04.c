#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<ctype.h>
#define max 100
int precedence(char c){
    if(c=='^'){
        return 3;
    }else if(c=='*' || c=='/'){
        return 2;
    }else if(c=='+' || c=='-'){
        return 1;
    }else{
        return -1;
    }
}
int main(){
    int i,j;
    char infix[100];
    scanf("%^[^\n]",infix);
    int len = strlen(infix);
    char *postfix =(char *) malloc(sizeof(char)*(len+2));
    char stack[max];
    int top=-1;
    for (i=0,j=0;i<len;i++){
        if(infix[i]==' ' || infix[i] == '\t'){
            continue;
        }if(isalnum(infix[i])){
            postfix[j++]=infix[i];
        }else if(infix[i] == '('){
            stack[++top]=infix[i];
        }else if(infix[i]==')'){
            while (top>-1 && stack[top]!='('){
                postfix[j++]=stack[top--];
            }
        }else{
            while (top>-1 && stack[top]!='(' && precedence(stack[top])>=precedence(infix[i])){
                postfix[j++]=stack[top--];
            }
            stack[++top]=infix[i];
        }
    }
    printf("%s\n",postfix);
}