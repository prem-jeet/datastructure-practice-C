#include "HelpreDS.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
/* Circular Doubly linked list code Start */
DLLNode createDLLNode(void *data) {
  DLLNode n = malloc(1 * sizeof(struct DoublyLinkedListNode));
  if (!n)
    return NULL;
  n->data = data;
  n->next = NULL;
  n->prev = NULL;
  return n;
}
CDLL createCircularDoublyLinkedList() {
  CDLL cdll = malloc(1 * sizeof(struct CircularDoublyLinkedList));
  cdll->head = NULL;
  cdll->rear = NULL;
  cdll->length = 0;
  return cdll;
}
void cdllInsertFront(CDLL cdll, void *data) {
  if (!(cdll && data))
    return;
  DLLNode temp = createDLLNode(data);
  if (!temp)
    return;
  cdll->length += 1;
  if (!cdll->head) {
    cdll->head = cdll->rear = temp;
  }
  temp->next = cdll->head;
  temp->prev = cdll->rear;
  cdll->rear->next = temp;
  cdll->head->prev = temp;
  cdll->head = temp;
}
void cdllInsertRear(CDLL cdll, void *data) {
  if (!(cdll && data))
    return;
  DLLNode temp = createDLLNode(data);
  if (!temp)
    return;
  cdll->length += 1;
  if (!cdll->head) {
    cdll->head = cdll->rear = temp;
  }
  temp->next = cdll->head;
  temp->prev = cdll->rear;
  cdll->head->prev = temp;
  cdll->rear->next = temp;
  cdll->rear = temp;
}
void cdllInsertAt(CDLL cdll, void *data, int index) {
  if (!(cdll && data) || index < 0)
    return;
  if (!cdll->head || index == 0)
    return cdllInsertFront(cdll, data);
  if (index >= cdll->length)
    return cdllInsertRear(cdll, data);
  int counter = index;
  DLLNode temp = cdll->head;
  while (--counter) {
    temp = temp->next;
  }
  DLLNode newNode = createDLLNode(data);
  if (!newNode)
    return;
  cdll->length += 1;
  newNode->prev = temp;
  newNode->next = temp->next;
  temp->next->prev = newNode;
  temp->next = newNode;
}
void *cdllGetFromIndex(CDLL cdll, int index) {
  if (!(cdll && cdll->head))
    return NULL;
  int counter = index >= cdll->length ? cdll->length - 1 : index;
  DLLNode temp = cdll->head;
  while (counter--)
    temp = temp->next;
  return temp->data;
}
void *cdllGetFront(CDLL cdll) { return cdllGetFromIndex(cdll, 0); }
void *cdllGetRear(CDLL cdll) {
  return cdllGetFromIndex(cdll, cdll->length - 1);
}
void cdllDeleteFromIndex(CDLL cdll, int index) {
  if (!(cdll && cdll->head) || index < 0 || index >= cdll->length)
    return;
  cdll->length -= 1;
  int counter = index;
  DLLNode temp = cdll->head;
  if (cdll->head == cdll->rear) {
    cdll->head = cdll->rear = NULL;
    free(temp);
    return;
  }
  while (counter--)
    temp = temp->next;
  temp->prev->next = temp->next;
  temp->next->prev = temp->prev;

  if (temp == cdll->rear)
    cdll->rear = temp->prev;
  if (temp == cdll->head)
    cdll->head = temp->next;
  free(temp);
}
void cdllDeleteFront(CDLL cdll) { return cdllDeleteFromIndex(cdll, 0); }
void cdllDeleteRear(CDLL cdll) {
  return cdllDeleteFromIndex(cdll, cdll->length - 1);
}

void cdllPrint(CDLL cdll) {
  if (!(cdll && cdll->head)) {
    printf("empty list\n");
    return;
  }
  DLLNode n = cdll->head;
  do {
    printf("%d ", *(int *)n->data);
    n = n->next;
  } while (n != cdll->head);
  printf("\nsize is :%d\n", cdll->length);
}
/*Circular doubly linked list code end*/
<<<<<<<<< Temporary merge branch 1

/*Stack code start*/
Stack createStack() {
  Stack s = malloc(1 * sizeof(struct _Stack));
  if (!s)
    return NULL;
  s->stack = createCircularDoublyLinkedList();
  if (!s->stack)
    return NULL;
  s->length = 0;
  return s;
}
bool isStackEmpty(Stack s) {
  if (!(s && s->stack))
    return true;
  return !s->stack->head;
}
void stackPush(Stack s, void *data) {
  if (!(s && s->stack && data))
    return;
  cdllInsertRear(s->stack, data);
  s->length = s->stack->length;
}
void *stackPop(Stack s) {
  if (!(s && s->stack))
    return NULL;
  if (isStackEmpty(s))
    return NULL;
  DLLNode temp = createDLLNode(cdllGetRear(s->stack));
  if (!temp)
    return NULL;
  cdllDeleteRear(s->stack);
  s->length = s->stack->length;
  return temp->data;
}
void *stackTop(Stack s) {
  if (!(s && s->stack))
    return NULL;
  if (isStackEmpty(s))
    return NULL;
  return cdllGetRear(s->stack);
}
=========
>>>>>>>>> Temporary merge branch 2

/*Stack code start*/
Stack createStack() {
  Stack s = malloc(1 * sizeof(struct _Stack));
  if (!s)
    return NULL;
  s->stack = createCircularDoublyLinkedList();
  if (!s->stack)
    return NULL;
  s->length = 0;
  return s;
}
bool isStackEmpty(Stack s) {
  if (!(s && s->stack))
    return true;
  return !s->stack->head;
}
void stackPush(Stack s, void *data) {
  if (!(s && s->stack && data))
    return;
  cdllInsertRear(s->stack, data);
  s->length = s->stack->length;
}
void *stackPop(Stack s) {
  if (!(s && s->stack))
    return NULL;
  if (isStackEmpty(s))
    return NULL;
  DLLNode temp = createDLLNode(cdllGetRear(s->stack));
  if (!temp)
    return NULL;
  cdllDeleteRear(s->stack);
  s->length = s->stack->length;
  return temp->data;
}
void *stackTop(Stack s) {
  if (!(s && s->stack))
    return NULL;
  if (isStackEmpty(s))
    return NULL;
  return cdllGetRear(s->stack);
}
/*Stack code ends*/

/*Queue code start*/
Queue createQueue() {
  Queue q = malloc(sizeof(struct _Queue));
  if (!q)
    return NULL;
  q->queue = createCircularDoublyLinkedList();
  if (!q->queue)
    return NULL;
  q->length = 0;
  return q;
}
bool isQueueEmpty(Queue q) {
  if (!(q && q->queue))
    return true;
  return !q->queue->head;
}
void enqueue(Queue q, void *data) {
  if (!(q && q->queue && data))
    return;
  cdllInsertRear(q->queue, data);
  q->length = q->queue->length;
}
void *dequeue(Queue q) {
  if (!(q && q->queue))
    return NULL;
  DLLNode temp = createDLLNode(cdllGetFront(q->queue));
  if (temp == NULL)
    return NULL;
  cdllDeleteFront(q->queue);
  q->length = q->queue->length;
  return temp->data;
}
void *queueFront(Queue q) {
  if (!(q && q->queue))
    return NULL;
  if (isQueueEmpty(q))
    return NULL;
  return cdllGetFront(q->queue);
}
/*Queue code ends*/
int main() {
<<<<<<<<< Temporary merge branch 1
  Stack s = createStack();
  for (int i = 0; i < 4; i++) {
    int *a = malloc(sizeof(int));
    *a = i;
    stackPush(s, a);
  }
  cdllPrint(s->stack);
  printf("Top of the stack is %d\n", *(int *)stackTop(s));
=========
  Queue s = createQueue();
  for (int i = 0; i < 1; i++) {
    int *a = malloc(sizeof(int));
    *a = i;
    enqueue(s, a);
  }
  cdllPrint(s->queue);
  dequeue(s);
  if (queueFront(s) != NULL) {
    printf("Front of queue  is %d\n", *(int *)queueFront(s));
  }
>>>>>>>>> Temporary merge branch 2
  return 0;
}