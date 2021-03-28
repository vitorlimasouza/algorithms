typedef struct queue{
    int value;
    struct queue *next;
    struct queue *rear;
}
Queue;

void enQueue(Queue **queue, int value);
int deQueue(Queue **queue);
int returnFront(Queue *queue);
int returnRear(Queue *queue);
Queue *newNodeQ(int value);
void freeQueue(Queue **queue);

void enQueue(Queue **queue, int value){
    Queue *temp = *queue;
    if(temp == NULL){
        temp = newNodeQ(value);
        temp->rear = temp;
    }else{
        temp->rear->next = newNodeQ(value);
        temp->rear = temp->rear->next;
    }
    *queue = temp;
}

int deQueue(Queue **queue){
    if((*queue) == NULL){
        printf("fila vazia");
        return 0;
    }else{
        Queue *temp = *queue;
        int value = temp->value;
        if((*queue)->next == NULL){
            (*queue) = NULL;
        }else{
            (*queue)->next->rear = (*queue)->rear;
            (*queue) = (*queue)->next;
            free(temp);
        }
        return value;
    }
}

int returnFront(Queue *queue){
    return queue->value;
}

int returnRear(Queue *queue){
    return queue->rear->value;
}

Queue *newNodeQ(int value){
    Queue *n;
    n = (Queue *) malloc(sizeof(Queue));
    if(n == NULL) exit(0);
    n->value = value;
    n->next = NULL;
    n->rear = NULL;
    return n;
}

void freeQueue(Queue **queue){
    while((*queue) != NULL){
        Queue *tmp = (*queue)->next;
        free((*queue));
        (*queue) = tmp;
    }
}
