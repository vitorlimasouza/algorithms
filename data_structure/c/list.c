#include <stdlib.h>

struct node{
    int value;
    struct node *next;
};

typedef struct list{
    int size;
    struct node *head;
    struct node *tail;
}List;

List *createList();
struct node *newNodeL(int value);
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

struct node *newNodeL(int value){
    struct node *n; 
    n = (struct node *) malloc(sizeof(List));
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
        struct node *node;
        if(position == 0){
            node = newNodeL(value);
            node->next = list->head;
            list->head = node;
            list->size++;
            return;
        }else for(struct node *temp = list->head;
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

// void freeList(List **list){
//     while((*list) != NULL){
//         List *temp = (*list)->next;
//         free((*list));
//         (*list) = temp;
//     }
// }
