#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../Queue.h"


typedef struct
{
    Queue *q1;
    Queue *q2;
} Stack;

int printOptions();
bool isStackEmpty(Stack *s);
bool isStackFull(Stack *s);
void printStack(Stack *);
Stack *createStack(int);
int push(Stack *, int);
int pop(Stack *);

int main()
{

    Stack *s = createStack(5);

    int option, item, terminate = 0;

    while (true)
    {
        if (terminate)
            break;
        printStack(s);
        option = printOptions();

        switch (option)
        {
        default:
            printf("Invalid option \n");
            terminate = 1;
            break;
        case 1:
            printf("Enter the item : ");
            scanf("%d", &item);
            if(push(s, item) == -1){
                printf("\nStack is Full\n");
            }
            break;
            case 2:
            item = pop(s);
            if(item == -1){
                printf("\n Stack is empty\n");
                break;
            }
            printf("Popped %d from stack\n", item);
            break;
            case 3:
            terminate = 1;
        }
    }
    return 1;
}

int push(Stack *s, int item)
{
    if (isStackFull(s))
    {
        return -1;
    }
    enqueue(s->q1, item);
    return item;
}

int pop(Stack *s){
    if(isStackEmpty(s)){
        return -1;
    }
    while(s->q1->front != s->q1->rare){
        int item = dequeue(s->q1);
        enqueue(s->q2, item);
    }
    int returnValue = dequeue(s->q1);
    Queue *temp = s->q1;
    s->q1=s->q2;
    s->q2=temp;
    return returnValue; 
}

bool isStackEmpty(Stack *s)
{
    return isQueueEmpty(s->q1);
}

bool isStackFull(Stack *s)
{
    return isQueueFull(s->q1);
}

Stack *createStack(int size)
{
    Stack *s = malloc(1 * sizeof(Stack));
    s->q1 = createQueue(size);
    s->q2 = createQueue(size);
    return s;
}

void printStack(Stack *s)
{
    printQueue(s->q1);
    printf("\n");
    
}

int printOptions()
{
    printf("\n*********************\n");
    printf("*   Stack Operations: *\n");
    printf("*   1. Push           *\n");
    printf("*   2. Pop            *\n");
    printf("*   3. END            *\n");
    printf("*********************\n");
    int option;
    printf("Enter choice : ");
    scanf("%d", &option);
    return option;
}