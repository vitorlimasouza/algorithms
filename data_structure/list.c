#include <stdlib.h>
#include "node.h"

typedef struct list{
    int size;
    Node *head;
    Node *tail;
}List;

List* create_list(){
    List *n = (List *) malloc(sizeof(List));
    n->head = NULL;
    n->tail = NULL;
    n->size = 0;
    return n;
}

void push_back(List *list, int value){ 
    if(list->head == NULL){
        list->head = new_node(value);
        list->tail = list->head;
        list->size++;
    }else{
        list->tail->next = new_node(value);
        list->tail = list->tail->next;
        list->size++;
    }
}

void push_front(List *list, int value)
{
    if(list->head == NULL){
        push_back(list, value);
    }else{
        Node *node = new_node(value);
        node->next = list->head;
        list->head = node;
        list->size++;
    }
}

void insert(List *list, int value, int position){
    if(list->head != NULL){
        if(position == 0) push_front(list, value);
        if(position > 0)
        {
            int index = 0;
            for(Node *temp_node = list->head; temp_node != NULL; temp_node = temp_node->next, index++){
                if(index == position - 1)
                {
                    Node *node = new_node(value);
                    node->next = temp_node->next;
                    temp_node->next = node;
                    list->size++;
                }
            }
        }
    }
}

