#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef struct Queue Queue; // Forward declaration

Queue* createQueue(int size);
bool isQueueFull(Queue *q);
bool isQueueEmpty(Queue *q);
int enqueue(Queue *q, int item);
int dequeue(Queue *q);
void printQueue(Queue *q);

#endif /* QUEUE_H */
