#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DLLNode {
  void *data;
  struct DLLNode *next;
  struct DLLNode *prev;
} DLLNode;

typedef struct {
  DLLNode *head;
  DLLNode *rear;
  int capacity;
} CDLL;

DLLNode *createDLLNode(void *);
CDLL *createCDLL();

bool insertFront(CDLL *, void *);
bool insertRear(CDLL *, void *);
bool insertAfter(CDLL *, void *, DLLNode *);
bool insertAt(CDLL *, void *, int);

DLLNode *find(CDLL *, void *, bool (*)(void *, void *));
bool compareInt(void *, void *);
bool compareFloat(void *, void *);
bool compareChar(void *, void *);
bool compareStr(void *, void *);

bool deleteFront(CDLL *);
bool deleteRear(CDLL *);
bool deleteAfter(CDLL *, DLLNode *);
bool deleteFrom(CDLL *, int);

DLLNode *getFront(CDLL *);
DLLNode *getRear(CDLL *);
DLLNode *getFrom(CDLL *, int);

void printCDLL(CDLL *, void (*)(void *));
void printInt(void *);
void printFloat(void *);
void printChar(void *);
void printStr(void *);

int main() {
  CDLL *cdll = createCDLL();
  for (int i = 0; i < 5; i++) {
    int *data = malloc(sizeof(int));
    *data = i;
    i % 2 ? insertFront(cdll, data) : insertRear(cdll, data);
  }
  printCDLL(cdll, printInt);
  deleteFront(cdll);
  printCDLL(cdll, printInt);
  deleteRear(cdll);
  printCDLL(cdll, printInt);
  // DLLNode *n = getFrom(cdll, 3);
  // int *a = malloc(sizeof(int));
  // *a = 909;
  // insertAfter(cdll, a, n);
  // printCDLL(cdll, printInt);

  // a = malloc(sizeof(int));
  // *a = 787;
  // insertAt(cdll, a, 4);
  // printCDLL(cdll, printInt);

  return 1;
}

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
bool deleteAfter(CDLL *cdll, DLLNode *target);
bool deleteFrom(CDLL *cdll, int index);

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