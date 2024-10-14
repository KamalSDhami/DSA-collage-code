#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct snode{
    int info;
    struct snode *next;
};
struct snode* insert_start (struct snode *head){
    struct snode * temp;
    temp = (struct snode *)malloc(sizeof (struct snode));
    if(temp == NULL){
        printf("Error: Overflow");
    }else{
        printf("Enter info of node : ");
        scanf("%d",&(temp->info));
        temp -> next = head;
        head = temp;
    }
    return head;
    
}
struct snode* insert_last(struct snode *head){
    struct snode *temp ;
    temp = (struct snode *)malloc(sizeof (struct snode));
    if (temp == NULL){
        printf("Error : overflow\n");
    }else if(head == NULL){
        scanf("%d",&(temp->info));
        temp->next = NULL;
        head =temp;
    }else{
        struct snode *p1 =head;
        while(p1->next!=NULL){
            p1 = p1->next;
        }
        p1 -> next = temp;
        temp -> next = NULL;
        scanf("%d",&(temp->info));
    }
    return head;
}

void display (struct snode *head){
    struct snode *p1 = head;
    if (p1 == NULL){
        printf("List is empty");
        return;
    }else{
        while (p1){
            printf("%d ",p1->info);
            p1=p1->next;
        }
    }
}
void display_reverse(struct snode *head){
    struct snode *p1 = head;
    if (p1 == NULL){
        return;
    }else{
        display_reverse(p1->next);
    }
    printf("%d ",p1->info);
}

void insurt_before(struct snode *head){
    int value;
    struct snode *p1 = head,*p2 = NULL,*temp;
    printf("Enter the value, before wich you want to insuret the item : ");
    scanf("%d",&value);
    printf("Enter the value you want to insurt : ");
    scanf("%d",&temp->info);

    while (p1->info !=value && p1 -> next != NULL){
        p2 = p1;
        p1 = p1->next;
    }
    temp ->next = p2->next;
    p2->next = temp;
}

struct snode * reverse_link_list(struct snode *head){
    struct snode *p1 = NULL, *p2= head,*p3=NULL;
    while (p2 != NULL){
        p3 = p2 -> next;
        p2 -> next = p1;
        p1 = p2;
        p2 = p3;
    }
    head = p1;
    return head;
}

int main(){
    int choice;
    struct snode *head =NULL;
    do{
        printf("1)Insurt at start \n2)Insurt at end\n3)insurt before a value\n4)diaplay\n5)display reverse\n77)Reverse linked list\n99)exit\n");
        printf("Enter the choice : ");
        scanf("%d",&choice);
        
        switch (choice)
        {
        case 1:
            head = insert_start(head);
            break;
        case 2:
            head = insert_last(head);
            break;
        case 3:
            insurt_before(head);
            break;
        case 4:
            display(head);
            break;
        case 5 :
            display_reverse(head);
            break;
        case 77:
            head = reverse_link_list(head);
            break;
        case 99:
            exit(1);
        default:
            printf("Error : invalid input \n");
        }
    }while(1);
    return 0;
}