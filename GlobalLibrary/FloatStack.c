#include <stdio.h>
#include <stdlib.h>
#include "FloatStack.h"

bool isStackFull(FloatStack *s)
{
    return s->size - 1 == s->top;
}

bool isStackEmpty(FloatStack *s)
{
    return s->top == -1;
}

float peek(FloatStack *s)
{
    if (isStackEmpty(s))
        return -1;
    return s->stack[s->top];
}
float pop(FloatStack *s)
{
    if (isStackEmpty(s))
        return -1;
    return s->stack[s->top--];
}

float push(FloatStack *s, float item)
{
    if (isStackFull(s))
        return -1;

    return s->stack[++s->top] = item;
}

FloatStack *createFloatStack(int size)
{
    FloatStack *f = calloc(size, sizeof(float));
    f->top = -1;
    f->size = size;
    return f;
}