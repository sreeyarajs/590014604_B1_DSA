#include <stdio.h>
#define MAX 5  // Define maximum stack size

int stack[MAX];  // Stack array
int top = -1;    // Initialize top to -1 (empty stack)

// Function to push an element into the stack
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");  // Stack is full
    } else {
        top++;
        stack[top] = value;
        printf("Inserted %d into the stack\n", value);
    }
}

// Function to pop an element from the stack
void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");  // Stack is empty
    } else {
        printf("Deleted %d from the stack\n", stack[top]);
        top--;
    }
}

// Main function to demonstrate stack operations
int main() {
    push(10);
    push(20);
    push(30);
    pop();
    pop();
    pop();
    pop();  // Will result in Stack Underflow
    return 0;
}
