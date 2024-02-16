#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Queue.h"


Queue *createQueue(int size)
{
    Queue *q = malloc(1 * sizeof(Queue));
    q->front = q->rare = -1;
    q->size = size;
    q->queue = malloc(size * sizeof(int));
    return q;
}

bool isQueueFull(Queue *q)
{
    return (q->rare + 1) % (q->size) == q->front;
}

bool isQueueEmpty(Queue *q)
{
    return q->rare == -1;
}

int enqueue(Queue *q, int item)
{
    if (isQueueFull(q))
    {
        return -1;
    }
    if(q->front ==-1) q->front++;
    q->rare++;
    q->rare %= q->size;
    q->queue[q->rare] = item;
    return item;
}

int dequeue(Queue *q)
{
    if (isQueueEmpty(q))
    {
        return -1;
    }
    int returnValue = q->queue[q->front];

    if (q->rare == q->front)
    {
        q->rare = q->front = -1;
    }
    else
    {
        q->front++;
        q->front %= q->size;
    }
    return returnValue;
}

void printQueue(Queue *q)
{
    bool isWrapped = q->front > q->rare;
    for (int i = 0; i < q->size; i++)
    {
        if (isWrapped && (i <= q->rare || i >= q->front))
        {
            printf("%d |", q->queue[i]);
            continue;
        }
        if (!isWrapped && (i <= q->rare && i >= q->front))
        {
            printf("%d |", q->queue[i]);
            continue;
        }
        printf("  |");
    }
}