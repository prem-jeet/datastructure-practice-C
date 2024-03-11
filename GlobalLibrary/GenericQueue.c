#include "./GenericQueue.h"
#include <stdlib.h>

Queue createQueue() {

  Queue q = calloc(1, sizeof(struct queue));
  q->queue = createCDLL();
  return q;
}

void enqueue(Queue q, void *data) {
  if (q && q->queue) {
    insertRear(q->queue, data);
  }
}

void *dequeue(Queue q) {
  if (!(q && q->queue))
    return NULL;

  DLLNode *temp = createDLLNode(getFront(q->queue)->data);
  deleteFront(q->queue);
  return temp->data;
}

bool isEmpty(Queue q) {
  if (!(q && q->queue))
    return true;
  return q->queue->head == NULL;
}