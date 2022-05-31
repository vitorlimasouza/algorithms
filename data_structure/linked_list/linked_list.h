#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>
#include "../node.h"

//#############################################################################
//                               STRUCTS
//#############################################################################

typedef struct list{
    int size;
    node *head;
    node *tail;
}list;

//#############################################################################
//                               METHODS
//#############################################################################

list* create_list();
void push_back(list *l, int value);
void push_front(list *l, int value);
void insert(list *l, int value, int position);

#endif