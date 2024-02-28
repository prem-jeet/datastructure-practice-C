#include "DoublyCircularLinkedList.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

DLLNode *createDLLNode(void *data) {
  if (!data)
    return NULL;
  DLLNode *newNode = malloc(sizeof(DLLNode));
  if (!newNode)
    return NULL;
  newNode->next = newNode->prev = NULL;
  newNode->data = data;
  return newNode;
}
CDLL *createCDLL() {
  CDLL *cdll = malloc(sizeof(CDLL));
  if (!cdll)
    return NULL;
  cdll->head = cdll->rear = NULL;
  cdll->capacity = 0;
  return cdll;
}

bool insertFront(CDLL *cdll, void *data) {
  if (!(cdll && data))
    return false;
  DLLNode *newNode = createDLLNode(data);
  if (!newNode)
    return false;
  cdll->capacity++;
  if (!cdll->head)
    cdll->head = cdll->rear = newNode;

  newNode->next = cdll->head;
  newNode->prev = cdll->rear;
  cdll->rear->next = newNode;
  cdll->head->prev = newNode;
  cdll->head = newNode;

  return true;
}
bool insertRear(CDLL *cdll, void *data) {
  if (!(cdll && data))
    return false;
  if (!cdll->head)
    return insertFront(cdll, data);
  DLLNode *newNode = createDLLNode(data);
  if (!newNode)
    return false;
  cdll->capacity++;
  newNode->next = cdll->head;
  newNode->prev = cdll->rear;
  cdll->rear->next = newNode;
  cdll->head->prev = newNode;
  cdll->rear = newNode;
  return true;
}
bool insertAfter(CDLL *cdll, void *data, DLLNode *target) {
  if (!(cdll && data && target))
    return false;
  if (target == cdll->rear) {
    insertFront(cdll, data);
    return true;
  }
  DLLNode *newNode = createDLLNode(data);
  if (!newNode)
    return false;
  cdll->capacity++;
  newNode->next = target->next;
  newNode->prev = target;
  target->next->prev = newNode;
  target->next = newNode;
  return true;
}
bool insertAt(CDLL *cdll, void *data, int index) {
  if (!(cdll && cdll->head && data && index > -1 && index < cdll->capacity))
    return NULL;
  if (index == 0)
    return insertFront(cdll, data);
  if (index == cdll->capacity - 1)
    return insertRear(cdll, data);
  DLLNode *n = cdll->head;
  int count = 1;
  while (count++ != index)
    n = n->next;
  return insertAfter(cdll, data, n);
}

DLLNode *getFront(CDLL *cdll) {
  if (!(cdll && cdll->head))
    return NULL;
  return cdll->head;
}
DLLNode *getRear(CDLL *cdll) {
  if (!(cdll && cdll->rear))
    return NULL;
  return cdll->rear;
}
DLLNode *getFrom(CDLL *cdll, int index) {
  if (!(cdll && cdll->head && index > -1 && index < cdll->capacity))
    return NULL;
  if (index == 0)
    return getFront(cdll);
  if (index == cdll->capacity - 1)
    return getRear(cdll);
  int count = 0;
  DLLNode *n = cdll->head;
  while (count++ != index)
    n = n->next;
  return n;
}

bool deleteFront(CDLL *cdll) {
  if (!(cdll && cdll->head))
    return false;
  cdll->capacity--;
  if (cdll->head == cdll->rear) {
    free(cdll->head);
    cdll->head = cdll->rear = NULL;
    return true;
  }

  cdll->rear->next = cdll->head->next;
  cdll->head->next->prev = cdll->rear;
  free(cdll->head);
  cdll->head = cdll->rear->next;
  return true;
}
bool deleteRear(CDLL *cdll) {
  if (!(cdll && cdll->head))
    return false;
  if (cdll->head == cdll->rear)
    return deleteFront(cdll);
  cdll->capacity--;
  cdll->head->prev = cdll->rear->prev;
  cdll->rear->prev->next = cdll->head;
  free(cdll->rear);
  cdll->rear = cdll->head->prev;
  return true;
}
bool deleteAfter(CDLL *cdll, DLLNode *target) {
  if (!(cdll && cdll->head && target))
    return false;
  if (target->next == cdll->rear)
    return deleteRear(cdll);
  if (target == cdll->rear)
    return deleteFront(cdll);
  cdll->capacity--;
  DLLNode *n = target->next;
  target->next = n->next;
  n->next->prev = target;
  free(n);
  return true;
}
bool deleteFrom(CDLL *cdll, int index) {
  if (!(cdll && cdll->head && index > -1 && index < cdll->capacity))
    return false;
  if (index == 0)
    return deleteFront(cdll);
  if (index == cdll->capacity - 1)
    return deleteRear(cdll);
  return deleteAfter(cdll, getFrom(cdll, index - 1));
}

DLLNode *find(CDLL *cdll, void *data, bool (*compare)(void *, void *)) {
  if (!(cdll && cdll->head && data && compare))
    return NULL;
  DLLNode *n = cdll->head;
  do {
    if (compare(n->data, data))
      return n;
    n = n->next;
  } while (n != cdll->head);
  return NULL;
}
bool compareInt(void *a, void *b) { return *(int *)a == *(int *)b; }
bool compareFloat(void *a, void *b) { return *(float *)a == *(float *)b; }
bool compareChar(void *a, void *b) { return *(char *)a == *(char *)b; }
bool compareStr(void *a, void *b) { return strcmp((char *)a, (char *)b); }

void printCDLL(CDLL *cdll, void (*print)(void *)) {
  if (!(cdll && print))
    return;
  if (!cdll->head) {
    printf("\nList is empty");
    return;
  }
  DLLNode *n = cdll->head;

  do {
    printf(n == cdll->head ? " <- " : " <-> ");
    print(n->data);
    printf(n == cdll->rear ? " -> " : "");
    n = n->next;
  } while (n != cdll->head);

  printf("\n");
}
void printInt(void *data) { printf("%d", *(int *)data); }
void printFloat(void *data) { printf("%0.2f", *(float *)data); }
void printChar(void *data) { printf("%c", *(char *)data); }
void printStr(void *data) { printf("%s", (char *)data); }