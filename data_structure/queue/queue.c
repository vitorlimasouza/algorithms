#include "queue.h"

queue* create_queue(){
    queue* q;
    q = (queue*) malloc(sizeof(queue));
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q;
}

void enqueue(queue* q, int value){
    if(q->rear == NULL){
        q->rear = new_node(value);
        q->front = q->rear;
    }else{
        q->rear->next = new_node(value);
        q->rear = q->rear->next;
    }
}

queue* dequeue(queue* q){
    if(q->front == NULL) return NULL;
    else{
        queue* value = q;
        if(q->front->next == NULL){
            q->front = NULL;
        }else{
            q->front = q->front->next;
        }
        return value;
    }
}
