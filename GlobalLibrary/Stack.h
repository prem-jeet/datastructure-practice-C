#include<stdbool.h>

typedef struct{
    int (*stack)[];
    int size;int top;
}Stack;

int push(Stack *, int);
int pop(Stack *);
bool isStackFull(Stack *);
bool isStackEmpty(Stack *);
void printStack(Stack *);
Stack* createStack(int);