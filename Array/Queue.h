#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef struct
{
    int *queue;
    int front;
    int rare;
    int size;
} Queue;

Queue* createQueue(int size);
bool isQueueFull(Queue *q);
bool isQueueEmpty(Queue *q);
int enqueue(Queue *q, int item);
int dequeue(Queue *q);
void printQueue(Queue *q);

#endif /* QUEUE_H */
