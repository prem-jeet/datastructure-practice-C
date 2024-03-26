#include "HelpreDS.h"
#include <stdio.h>
#include <stdlib.h>
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

int main() {
  CDLL cdll = createCircularDoublyLinkedList();
  for (int i = 1; i < 4; i++) {
    int *temp = malloc(1 * sizeof(int));
    *temp = i;
    if (i % 2)
      cdllInsertFront(cdll, temp);
    else
      cdllInsertRear(cdll, temp);
  }
  int a = 11;
  cdllInsertAt(cdll, &a, 0);
  int b = 12;
  cdllInsertAt(cdll, &b, cdll->length);
  int c = 13;
  cdllInsertAt(cdll, &c, 1);
  int d = 14;
  cdllInsertAt(cdll, &d, 3);
  int e = 15;
  cdllInsertAt(cdll, &e, 6);
  int f = 99;
  cdllInsertAt(cdll, &f, 100);

  cdllPrint(cdll);

  // while (cdll->length) {

  cdllDeleteFront(cdll);

  cdllPrint(cdll);
  cdllDeleteRear(cdll);
  cdllPrint(cdll);
  // }

  return 0;
}