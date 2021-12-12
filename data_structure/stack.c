#include <stdlib.h>

struct nodeStack{
    int value;
    struct nodeStack *next;
    struct nodeStack *previous;
};

typedef struct stack{
    struct nodeStack *base;
    struct nodeStack *top;
}
Stack;

struct nodeStack *newNodeS(int value);
void push(Stack *stack, int value);
int pop(Stack *stack);
int peek(Stack *stack);
void freeStack(Stack **stack);

Stack *createStack(){
    Stack *stack; 
    stack = (Stack *) malloc(sizeof(Stack));
    stack->base = NULL;
    stack->top = NULL;
    return stack;
}

struct nodeStack *newNodeS(int value){
    struct nodeStack *n;
    n = (struct nodeStack *) malloc(sizeof(struct nodeStack));
    n->value = value;
    n->next = NULL;
    n->previous = NULL;
    return n;
}

void push(Stack *stack, int value){
    if(stack->top == NULL){
        stack->top = newNodeS(value);
        stack->base = stack->top;
    }else{
        stack->top->next = newNodeS(value);
        stack->top->next->previous = stack->top;
        stack->top = stack->top->next;
    }
}

int pop(Stack *stack){
    if(stack->top == NULL){
        return -1;
    }else{
        struct nodeStack *top = stack->top;
        int value = top->value;
        if(top->previous == NULL){
             stack->top = NULL;
        }else{
            stack->top = top->previous;
            stack->top->next = NULL;
        }
        return value;
    }
}
