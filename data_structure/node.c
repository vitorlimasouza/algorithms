#include "node.h"

node* new_node(int value){
    node* n; 
    n = (node*) calloc(sizeof(node),1);
    n->value = value;
    return n;
}