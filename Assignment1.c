
#include <stdio.h>
#include <stdlib.h>
#define MAX 100 
struct Stack {
    int top;
    int items[MAX];
};
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    return stack;
}
int isFull(struct Stack* stack) {
    return stack->top == MAX - 1;
}
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}
void push(struct Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack overflow! Cannot push %d\n", item);
        return;
    }
    stack->items[++stack->top] = item;
    printf("%d pushed to stack\n", item);
}
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow! Cannot pop from empty stack\n");
        return -1;
    }
    return stack->items[stack->top--];
}
int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty! No top element\n");
        return -1;
    }
    return stack->items[stack->top];
}
void display(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->items[i]);
    }
    printf("\n");
}
int main() {
    struct Stack* stack = createStack();

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    display(stack);

    printf("%d popped from stack\n", pop(stack));
    printf("Top element is %d\n", peek(stack));
    display(stack);

    free(stack);
    return 0;
}
