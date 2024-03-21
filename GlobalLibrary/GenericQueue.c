#include "./GenericQueue.h"
#include <stdlib.h>

Queue createQueue() {

  Queue q = calloc(1, sizeof(struct queue));
  q->queue = createCDLL();
  q->size = 0;
  return q;
}

void enqueue(Queue q, void *data) {
  if (q && q->queue) {
    q->size++;
    insertRear(q->queue, data);
  }
}

void *dequeue(Queue q) {
  if (!(q && q->queue))
    return NULL;

  DLLNode *temp = createDLLNode(getFront(q->queue)->data);
  deleteFront(q->queue);
  q->size--;
  return temp->data;
}

bool isEmpty(Queue q) {
  if (!(q && q->queue))
    return true;
  return q->queue->head == NULL;
}