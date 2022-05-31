#ifndef QUEUE_H
#define QUEUE_H
#include <stdlib.h>
#include "../node.h"

//#############################################################################
//                               STRUCTS
//#############################################################################

typedef struct queue{
    node *front;
    node *rear;
    int size;
}queue;

//#############################################################################
//                               METHODS
//#############################################################################

queue* create_queue();
void enqueue(queue* q, int value);
queue* dequeue(queue* q);

#endif