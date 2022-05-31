#include "linked_list.h"

list* create_list(){
    list* l;
    l = (list*) malloc(sizeof(list));
    l->head = NULL;
    l->tail = NULL;
    l->size = 0;
    return l;
}

void push_back(list* l, int value){ 
    if(l->head == NULL){
        l->head = new_node(value);
        l->tail = l->head;
    }else{
        l->tail->next = new_node(value);
        l->tail = l->tail->next;
    }
    l->size++;
}

void push_front(list *l, int value){
    if(l->head == NULL)push_back(l, value);
    else{
        node* n = new_node(value);
        n->next = l->head;
        l->head = n;
    }
    l->size++;
}

void insert(list* l, int value, int position){
    if(l->head != NULL){
        if(position == 0) push_front(l, value);
        else if(position > 0){
            int index = 0;
            for(node* temp_node = l->head; temp_node != NULL; temp_node = temp_node->next, index++){
                if(index == position - 1){
                    node* n = new_node(value);
                    n->next = temp_node->next;
                    temp_node->next = n;
                }
            }
        }
        else return;
    }
    l->size++;
}
