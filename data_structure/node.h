#ifndef NODE_H
#define NODE_H
#include <stdlib.h>

//#############################################################################
//                               STRUCTS USED
//#############################################################################

typedef struct node{
    int value;
    struct node* next;
    struct node* previous;
}node;

//#############################################################################
//                               METHODS
//#############################################################################
node* new_node(int value);

#endif