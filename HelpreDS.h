#ifndef Helper_DS
#define Helper_DS
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
#endif