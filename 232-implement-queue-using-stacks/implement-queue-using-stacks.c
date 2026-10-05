#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Stack structure
typedef struct {
    int* data;
    int top;
    int capacity;
} Stack;

// Create a new stack
Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->data = (int*)malloc(sizeof(int) * capacity);
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

// Check if stack is empty
bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Check if stack is full
bool isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Push element onto stack
void push(Stack* stack, int x) {
    if (isFull(stack)) return;
    stack->data[++stack->top] = x;
}

// Pop element from stack
int pop(Stack* stack) {
    if (isEmpty(stack)) return -1;
    return stack->data[stack->top--];
}

// Peek top element of stack
int peek(Stack* stack) {
    if (isEmpty(stack)) return -1;
    return stack->data[stack->top];
}

// Queue structure using two stacks
typedef struct {
    Stack* stackIn;   // For push operations
    Stack* stackOut;  // For pop/peek operations
} MyQueue;

// Create a new queue
MyQueue* myQueueCreate() {
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
    queue->stackIn = createStack(MAX_SIZE);
    queue->stackOut = createStack(MAX_SIZE);
    return queue;
}

// Push element x to the back of queue
void myQueuePush(MyQueue* obj, int x) {
    push(obj->stackIn, x);
}

// Helper: Move all elements from stackIn to stackOut
void transferElements(MyQueue* obj) {
    if (isEmpty(obj->stackOut)) {
        while (!isEmpty(obj->stackIn)) {
            push(obj->stackOut, pop(obj->stackIn));
        }
    }
}

// Removes the element from in front of queue and returns it
int myQueuePop(MyQueue* obj) {
    transferElements(obj);
    return pop(obj->stackOut);
}

// Get the front element
int myQueuePeek(MyQueue* obj) {
    transferElements(obj);
    return peek(obj->stackOut);
}

// Returns true if the queue is empty, false otherwise
bool myQueueEmpty(MyQueue* obj) {
    return isEmpty(obj->stackIn) && isEmpty(obj->stackOut);
}

// Free the queue
void myQueueFree(MyQueue* obj) {
    free(obj->stackIn->data);
    free(obj->stackIn);
    free(obj->stackOut->data);
    free(obj->stackOut);
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 * int param_2 = myQueuePop(obj);
 * int param_3 = myQueuePeek(obj);
 * bool param_4 = myQueueEmpty(obj);
 * myQueueFree(obj);
 */