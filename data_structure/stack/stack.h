#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include "../node.h"

//#############################################################################
//                               STRUCTS
//#############################################################################

typedef struct stack{
    node *base;
    node *top;
    int size;
}stack;

//#############################################################################
//                               METHODS
//#############################################################################

stack* create_stack();
void push(stack* s, int value);
stack* pop(stack* s);

#endif