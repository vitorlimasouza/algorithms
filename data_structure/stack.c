#include "node.h"

typedef struct stack{
    Node* base;
    Node* top;
}Stack;

Stack* create_stack(){
    Stack* stack; 
    stack = (Stack*) malloc(sizeof(Stack));
    stack->base = NULL;
    stack->top = NULL;
    return stack;
}

void push(Stack* stack, int value){
    if(stack->top == NULL){
        stack->top = new_node(value);
        stack->base = stack->top;
    }else{
        stack->top->next = new_node(value);
        stack->top->next->previous = stack->top;
        stack->top = stack->top->next;
    }
}

int pop(Stack* stack){
    if(stack->top == NULL){
        return -1;
    }else{
        Node* top = stack->top;
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
