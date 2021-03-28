typedef struct list{
    int value;
    int size;
    struct list *next;
    struct list *tail;
}List;

List *newNodeL(int value);
void addend(List **list, int value);
void insert(List **list, int value, int position);
void freeList(List **list);

void addend(List **list, int value){ 
    if((*list) == NULL){
        (*list) = newNodeL(value);
        (*list)->tail = (*list);
        (*list)->size = 1;
    }else{
        (*list)->tail->next = newNodeL(value);
        (*list)->tail = (*list)->tail->next;
        (*list)->size = (*list)->size + 1;
    }
}

void insert(List **list, int value, int position){
    if((*list)->size < position) return;

    if((*list) != NULL){
        int i = 1;
        List *tempNode;
        if(position == 0){
            tempNode = newNodeL(value);
            tempNode->next = *list;
            *list = tempNode;
            return;
        }else for(List *temp = *list; i <= position; temp = temp->next, i++){
            if(i == position){
                tempNode = newNodeL(value);
                tempNode->next = temp->next;
                temp->next = tempNode;
                (*list)->size = (*list)->size + 1;
                return;
            }else if(temp->next == NULL){
                addend(list, value);
                return;
            }
        }
    }else{
        (*list) = newNodeL(value);
        (*list)->tail = (*list);
        (*list)->size = 1;
        return;
    }
}

List *newNodeL(int value){
    List *n; 
    n = (List *) malloc(sizeof(List));
    if(n == NULL) exit(1);
    n->value = value;
    n->next = NULL;
    return n;
}

void freeList(List **list){
    while((*list) != NULL){
        List *temp = (*list)->next;
        free((*list));
        (*list) = temp;
    }
}
