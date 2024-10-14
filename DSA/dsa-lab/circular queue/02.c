#include <stdio.h>
#include <stdlib.h>

struct stack {
 int top;
 int size;
 int *arr;
};

void create(struct stack *st) {
 printf("Enter the size of the stack: ");
 scanf("%d", &st->size);
 st->top = -1;
 st->arr = (int *)malloc(st->size * sizeof(int));
}

int is_empty(struct stack *st) {
 return (st->top == -1);
}

int is_full(struct stack *st) {
 return (st->top == st->size - 1);
}

void push(struct stack *st, int value) {
 if (is_full(st)) {
 printf("Stack is full!\n");
 return;
 }
 st->top++;
 st->arr[st->top] = value;
}
int pop(struct stack *st) {
 if (is_empty(st)) {
 printf("Stack is empty!\n");
 return -1;
 }
 int temp = st->arr[st->top];
 st->top--;
 return temp;
}
int peek(struct stack *st) {
 if (!is_empty(st)) {
 return st->arr[st->top];
 }
 return -1;
}
void enqueue(struct stack *stack1, int value) {
 push(stack1, value);
}
int dequeue(struct stack *stack1, struct stack *stack2) {
 if (is_empty(stack2)) {
 while (!is_empty(stack1)) {
 int temp = pop(stack1);
 push(stack2, temp);
 }
 }
 if (!is_empty(stack2)) {
 return pop(stack2);
 } else {
 printf("Queue is empty!\n");
 return -1;
 }
}
int peek_queue(struct stack *stack1, struct stack *stack2) {
 if (is_empty(stack2)) {
 while (!is_empty(stack1)) {
 int temp = pop(stack1);
 push(stack2, temp);
 }
 }
 return peek(stack2);
}

void display(struct stack *stack1, struct stack *stack2) {
 if (!is_empty(stack2)) {
 for (int i = stack2->top; i >= 0; i--) {
 printf("%d ", stack2->arr[i]);
 }
 }

 if (!is_empty(stack1)) {
 for (int i = 0; i <= stack1->top; i++) {
 printf("%d ", stack1->arr[i]);
 }
 }
 printf("\n");
}
int main() {
 struct stack stack1, stack2;
 // Create two stacks for the queue
 create(&stack1);
 create(&stack2);
 int choice, value;
 do {
 printf("\nMenu:\n");
 printf("1. Enqueue\n");
 printf("2. Dequeue\n");
 printf("3. Peek\n");
 printf("4. Display Queue\n");
 printf("5. Exit\n");
 printf("Enter your choice: ");
 scanf("%d", &choice);
 switch (choice) {
 case 1: // Enqueue
 printf("Enter value to enqueue: ");
 scanf("%d", &value);
 enqueue(&stack1, value);
 break;
 case 2: // Dequeue
 value = dequeue(&stack1, &stack2);
 if (value != -1) {
 printf("Dequeued: %d\n", value);
 }
 break;
 case 3: // Peek
 value = peek_queue(&stack1, &stack2);
 if (value != -1) {
 printf("Front element: %d\n", value);
 }
 break;
 case 4: // Display
 printf("Queue elements: ");
 display(&stack1, &stack2);
 break;
 case 5: // Exit
 printf("Exiting...\n");
 free(stack1.arr);
 free(stack2.arr);
 break;
 default:
 printf("Invalid choice!\n");
 }
 } while (choice != 5);
 return 0;
}
