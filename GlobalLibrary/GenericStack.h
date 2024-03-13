#include "../Linked list/Doubly Circular Linked List/DoublyCircularLinkedList.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  CDLL *stack;
} Stack;

bool isStackEmpty(Stack *);
bool push(Stack *, void *);
void *pop(Stack *);
void *peek(Stack *);
Stack *createStack();
