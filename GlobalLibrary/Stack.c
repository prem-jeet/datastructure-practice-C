#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Stack.h"

Stack *createStack(int size)
{
    Stack *s = malloc(1 * sizeof(Stack));
    s->top = -1;
    s->size = size;
    s->stack = calloc(size, sizeof(int));
    return s;
}

bool isStackFull(Stack *s)
{
    return s->top == s->size - 1;
}
bool isStackEmpty(Stack *s)
{
    return s->top == -1;
}

int push(Stack *s, int item){
    if(isStackFull(s)) return -1;
    s->stack[++(s->top)] = item;
    return item; 
}

int pop(Stack *s){
    if(isStackEmpty(s)) return -1;
    return s->stack[s->top--];

}

void printStack(Stack *s){
    printf("\n");
    for(int i=0;i <s->size;i++){
        if(i<=s->top) printf("%d |", s->stack[i]);
        else printf(" |");
    }
    printf("\n");
}