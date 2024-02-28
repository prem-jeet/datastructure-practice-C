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

void printDLL(CDLL *, void (*)(void *));
void printInt(void *);
void printFloat(void *);
void printChar(void *);
void printStr(void *);

int main() { return 1; }

DLLNode *createDLLNode(void *data) {
  if (!data)
    return NULL;
  DLLNode* newNode = malloc(sizeof(DLLNode));
  if(!newNode) return NULL;
  newNode->next = newNode->prev = NULL;
  newNode->data = data;
  return newNode;
}
CDLL *createDLL();
