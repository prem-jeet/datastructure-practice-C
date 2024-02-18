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
    FloatStack *f = calloc(1, sizeof(FloatStack));
    f->stack = calloc(size, sizeof(float));
    f->top = -1;
    f->size = size;
    return f;
}

void printStack(FloatStack *s)
{
    printf("\n");
    for (int i = 0; i < s->size; i++)
    {
        if (i <= s->top)
            printf("%0.2f |", s->stack[i]);
        else
            printf(" |");
    }
    printf("\n");
}