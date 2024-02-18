#include<stdbool.h>

typedef struct {
    float *stack;
    int size;
    int top;
}FloatStack;

FloatStack* clerFloatStack(int);
bool isStackFull(FloatStack *);
bool isStackEmpty(FloatStack *);
float peek(FloatStack *);
float push(FloatStack *, float);
float pop(FloatStack *);

