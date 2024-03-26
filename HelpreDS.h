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
#endif