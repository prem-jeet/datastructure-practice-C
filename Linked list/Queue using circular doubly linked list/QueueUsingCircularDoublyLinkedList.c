#include "../Doubly Circular Linked List/DoublyCircularLinkedList.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct queue {
  CDLL *queue;
};
typedef struct queue *Queue;

bool enqueue(Queue q, int data) {
  if (!q)
    return false;
  int *d = malloc(sizeof(int));
  *d = data;
  return insertRear(q->queue, d);
}
int dequeue(Queue q) {

  DLLNode *n = getFront(q->queue);
  if (!n)
    return -1;
  int returnValue = *(int *)n->data;
  deleteFront(q->queue);
  return returnValue;
}
void printQueue(Queue q) {
  if (q) {
    printCDLL(q->queue, printInt);
  }
}
Queue createQueue() {
  Queue q = malloc(sizeof(struct queue));
  if (!q)
    return NULL;
  q->queue = createCDLL();
  if (!q->queue)
    return NULL;
  return q;
}

int main() {
  Queue q = createQueue();
  for (int i = 0; i < 5; i++) {
    enqueue(q, i);
  }
  printQueue(q);
  for (int i = 0; i < 2; i++) {
    printf("removed %d\n", dequeue(q));
    printf("remain : ");
    printQueue(q);
  }
  return 1;
}