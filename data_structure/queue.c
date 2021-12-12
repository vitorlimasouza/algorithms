#include <stdlib.h>
#include <stdio.h>

struct nodeQueue{
    int value;
    struct nodeQueue *next;
};

typedef struct queue{
    struct nodeQueue *front;
    struct nodeQueue *rear;
}Queue;

Queue *createQueue();
struct nodeQueue *newNodeQ(int value);
void enQueue(Queue *queue, int value);
int deQueue(Queue *queue);

Queue *createQueue(){
    Queue *queue = (Queue *) malloc(sizeof(Queue));
    queue->rear = NULL;
    queue->front = NULL;
    return queue;
}

struct nodeQueue *newNodeQ(int value){
    struct nodeQueue *node;
    node = (struct nodeQueue *) malloc(sizeof(struct nodeQueue));
    if(node == NULL) exit(0);
    node->value = value;
    node->next = NULL;
    return node;
}

void enQueue(Queue *queue, int value){
    if(queue->rear == NULL){
        queue->rear = newNodeQ(value);
        queue->front = queue->rear;
    }else{
        queue->rear->next = newNodeQ(value);
        queue->rear = queue->rear->next;
    }
}

int deQueue(Queue *queue){
    if(queue->front == NULL){
        printf("fila vazia");
        return 0;
    }else{
        int value = queue->front->value;
        if(queue->front->next == NULL){
            queue->front = NULL;
        }else{
            queue->front = queue->front->next;
        }
        return value;
    }
}

