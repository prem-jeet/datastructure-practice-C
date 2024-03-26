#ifndef Helper_DS
#define Helper_DS
#include <stdbool.h>
struct DoublyLinkedListNode {
  void *data;
  struct DoublyLinkedListNode *next;
  struct DoublyLinkedListNode *prev;
};
typedef struct DoublyLinkedListNode *DLLNode;
struct CircularDoublyLinkedList {
  DLLNode head;
  DLLNode rear;
  int length;
};
typedef struct CircularDoublyLinkedList *CDLL;

struct _Stack {
  CDLL stack;
  int length;
};
typedef struct _Stack *Stack;
struct _Queue {
  CDLL queue;
  int length;
};
typedef struct _Queue *Queue;

struct _Deque {
  CDLL deque;
  int length;
};
typedef struct _Deque *Deque;

DLLNode createDLLNode(void *data);
CDLL createCircularDoublyLinkedList();
void cdllInsertFront(CDLL cdll, void *data);
void cdllInsertRear(CDLL cdll, void *data);
void cdllInsertAt(CDLL cdll, void *data, int index);
void *cdllGetFromIndex(CDLL cdll, int index);
void *cdllGetFront(CDLL cdll);
void *cdllGetRear(CDLL cdll);
void cdllDeleteFromIndex(CDLL cdll, int index);
void cdllDeleteFront(CDLL cdll);
void cdllDeleteRear(CDLL cdll);
void cdllPrint(CDLL cdll);

Stack createStack();
bool isStackEmpty(Stack s);
void stackPush(Stack s, void *data);
void *stackPop(Stack s);
void *stackTop(Stack s);

Queue createQueue();
bool isQueueEmpty(Queue q);
void enqueue(Queue q, void *data);
void *dequeue(Queue q);
void *queueFront(Queue q);

Deque createDoubleEndedQueue();
void dequeAppend(Deque deque, void *data);
void dequeAppendLeft(Deque deque, void *data);
void *dequePop(Deque deque);
void *dequePopLeft(Deque deque);
void dequeInsertAt(Deque deque, void *data, int index);
#endif