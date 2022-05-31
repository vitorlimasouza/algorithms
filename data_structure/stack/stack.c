#include "stack.h"

stack* create_stack(){
    stack* s;
    s = (stack*) malloc(sizeof(stack));
    s->base = NULL;
    s->top = NULL;
    s->size = 0;
    return s;
}

void push(stack *s, int value){
    if(s->top == NULL){
        s->top = new_node(value);
        s->base = s->top;
    }else{
        s->top->next = new_node(value);
        s->top->next->previous = s->top;
        s->top = s->top->next;
    }
    s->size++;
}

stack* pop(stack *s){
    if(s->top == NULL)return NULL;
    else{
        node* top = s->top;
        stack* value = s;
        if(top->previous == NULL){
            s->top = NULL;
        }else{
            s->top = top->previous;
            s->top->next = NULL;
        }
        s->size++;
        return value;
    }
}
