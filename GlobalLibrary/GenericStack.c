#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "GenericStack.h"

bool isStackEmpty(Stack *s)
{
    return s->top == -1;
}

bool isStackFull(Stack *s)
{
    return s->top == s->size - 1;
}

bool push(Stack *s, void *d)
{
    if (isStackFull(s))
    {
        printf("\nStack is full\n");
        return false;
    }
    s->stack[++s->top] = d;
    return true;
}

void *pop(Stack *s)
{
    if (isStackEmpty(s))
    {
        printf("\nStack is empty\n");
        return NULL;
    }
    return s->stack[s->top--];
}

void *peek(Stack *s)
{
    if (isStackEmpty(s))
    {
        printf("\nStack is empty\n");
        return NULL;
    }
    return s->stack[s->top];
}

Stack *createStack(int size)
{
    Stack *s = malloc(1 * sizeof(Stack));
    s->stack = calloc(size, sizeof(void *));
    if (!s || !s->stack)
    {
        printf("\nMemory allocation fail\n");
        return NULL;
    }
    s->top = -1;
    s->size = size;
    return s;
}