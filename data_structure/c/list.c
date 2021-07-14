#include <stdlib.h>

struct nodeList{
    int value;
    struct nodeList *next;
};

typedef struct list{
    int size;
    struct nodeList *head;
    struct nodeList *tail;
}List;

List *createList();
struct nodeList *newNodeL(int value);
void addEnd(List *list, int value);
void insert(List *list, int value, int position);
void freeList(List *list);

List *createList(){
    List *n = (List *) malloc(sizeof(List));
    n->head = NULL;
    n->tail = NULL;
    n->size = 0;
    return n;
}

struct nodeList *newNodeL(int value){
    struct nodeList *n; 
    n = (struct nodeList *) malloc(sizeof(struct nodeList));
    if(n == NULL) exit(1);
    n->value = value;
    n->next = NULL;
    return n;
}

void addEnd(List *list, int value){ 
    if(list->head == NULL){
        list->head = newNodeL(value);
        list->tail = list->head;
        list->size++;
    }else{
        list->tail->next = newNodeL(value);
        list->tail = list->tail->next;
        list->size++;
    }
}

void insert(List *list, int value, int position){
    int i = 0;
    if(list->head != NULL){
        struct nodeList *node;
        if(position == 0){
            node = newNodeL(value);
            node->next = list->head;
            list->head = node;
            list->size++;
            return;
        }else for(struct nodeList *temp = list->head;
                i <= position; 
                temp = temp->next, i++){
            if(i == position - 1){
                node = newNodeL(value);
                node->next = temp->next;
                temp->next = node;
                list->size++;
                return;
            }else if(temp->next == NULL){
                addEnd(list, value);
                return;
            }
        }
    }
}

