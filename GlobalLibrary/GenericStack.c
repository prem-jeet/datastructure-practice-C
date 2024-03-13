#include "GenericStack.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool isStackEmpty(Stack *s) { return s->stack->head == NULL; }

bool push(Stack *s, void *data) {
  if (s && data && s->stack) {
    insertFront(s->stack, data);
    return true;
  }
  return false;
}

void *pop(Stack *s) {
  if (isStackEmpty(s)) {
    printf("\nStack is empty\n");
    return NULL;
  }
  DLLNode *temp = createDLLNode(getFront(s->stack)->data);
  deleteFront(s->stack);
  return temp->data;
}

void *peek(Stack *s) {
  if (isStackEmpty(s)) {
    printf("\nStack is empty\n");
    return NULL;
  }
  return getRear(s->stack)->data;
}

Stack *createStack() {
  Stack *s = malloc(1 * sizeof(Stack));
  s->stack = createCDLL();
  if (!s || !s->stack) {
    printf("\nMemory allocation fail\n");
    return NULL;
  }
  return s;
}