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
bool insertAfter(CDLL *, void *, DLLNode *);
bool insertAt(CDLL *, void *, int);

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