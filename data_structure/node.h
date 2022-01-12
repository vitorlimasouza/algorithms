#include <stdlib.h>

#ifndef NODE_H
#define NODE_H

typedef struct node{
    int value;
    struct node* next;
    struct node* previous;
}Node;

Node* new_node(int value){
    Node* n; 
    n = (Node*) malloc(sizeof(Node));
    if(n == NULL) exit(1);
    n->value = value;
    n->next = NULL;
    n->previous = NULL;
    return n;
}
#endif