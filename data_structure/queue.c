#include "node.h"

typedef struct queue{
    Node* front;
    Node* rear;
}Queue;


Queue* create_queue(){
    Queue* queue = (Queue* ) malloc(sizeof(Queue));
    queue->rear = NULL;
    queue->front = NULL;
    return queue;
}

void enqueue(Queue* queue, int value){
    if(queue->rear == NULL){
        queue->rear = new_node(value);
        queue->front = queue->rear;
    }else{
        queue->rear->next = new_node(value);
        queue->rear = queue->rear->next;
    }
}

int dequeue(Queue* queue){
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

