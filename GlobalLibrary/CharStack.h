#include <stdbool.h>

typedef struct
{
    char* stack;
    int size;
    int top;
} Stack;

char push(Stack *, char);
char pop(Stack *);
char peek(Stack *);
bool isStackFull(Stack *);
bool isStackEmpty(Stack *);
void printStack(Stack *);
Stack *createStack(int);