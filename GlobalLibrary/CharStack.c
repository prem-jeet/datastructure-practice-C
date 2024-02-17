#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "CharStack.h"

#define STACK_FALLTHROUGH '?' // Define a sentinel value

Stack *createStack(int size)
{
    Stack *s = malloc(1 * sizeof(Stack));
    s->top = -1;
    s->size = size;
    s->stack = calloc(size, sizeof(char));
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

char push(Stack *s, char item){
    if(isStackFull(s)) return STACK_FALLTHROUGH;
    s->stack[++(s->top)] = item;
    return item; 
}

char pop(Stack *s){
    if(isStackEmpty(s)) return STACK_FALLTHROUGH;
    return s->stack[s->top--];

}
char peek(Stack *s){
    if(isStackEmpty(s)) return STACK_FALLTHROUGH;
    return s->stack[s->top];

}

void printStack(Stack *s){
    printf("\n");
    for(int i=0;i <s->size;i++){
        if(i<=s->top) printf("%c |", s->stack[i]);
        else printf(" |");
    }
    printf("\n");
}