#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct {
    void **stack;
    int top;
    int size;
}Stack;

bool isStackEmpty(Stack *);
bool isStackFull(Stack *);
bool push(Stack *, void *);
void* pop(Stack *);
void* peek(Stack *);
Stack *createStack(int);


