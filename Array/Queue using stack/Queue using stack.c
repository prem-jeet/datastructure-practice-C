#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

#define MAX_SIZE 10

typedef struct {
    int *stack;
    int top;
    int size;
}Stack;

typedef struct{
    Stack *s1;
    Stack *s2;
    int size;
}Queue;

bool isStackEmpty(Stack *);
bool isStackFull(Stack *);
int pop(Stack *);
int push(Stack *, int);
int printOptions();
void printStack(Stack *);
Queue* intitalizeQueue(){
Queue *q = (Queue *)malloc(1*sizeof(Queue));
    q->s1 = malloc(1*sizeof(Stack)); 
    q->s2 = malloc(1*sizeof(Stack)); 

    q->s1->size = (MAX_SIZE+1)/2;
    q->s2->size = (MAX_SIZE)/2;
    q->s1->stack = malloc((q->s1->size) * sizeof(int));
    q->s2->stack = malloc((q->s2->size) * sizeof(int));
    q->s1->top = -1;
    q->s2->top = -1;
    
    q->size = MAX_SIZE;

    return q;
}

bool isQueueEmpty(Queue *);
bool isQueueFull(Queue *);
int enqueue(Queue *, int);

int main(){
    Queue *q = intitalizeQueue();
    
    int option, terminate=0, item;
    while(true){
       if(terminate) break;

        printStack(q->s1);
        printStack(q->s2);
        int option = printOptions();
        switch(option){
            default: 
                printf("\nInvalid option \n");
                break;
            case 1:
                printf("\nEnter the item : ");
                scanf("%d", &item);
                enqueue(q, item);
                break;
            case 2:
                break;
            case 3:
                terminate = 1;
                break;
        }
    }
    return 1;
}


int enqueue(Queue *q, int item){
    if(isQueueFull(q)){
        printf("\nQueue is full\n");
        return -1;
    }
    if(isStackFull(q->s1) && isStackEmpty(q->s2)){
        while(!isStackEmpty(q->s1)){
            int item = pop(q->s1);
            if(item > -1)
            push(q->s2,item);
        }
    }
    push(q->s1, item);
    return 1;
}


bool isQueueEmpty(Queue *q){
    return isStackEmpty(q->s1) && isStackEmpty(q->s2);
}
bool isQueueFull(Queue *q){
    return isStackFull(q->s1) && !isStackEmpty(q->s2);
}

bool isStackEmpty(Stack *s){
    return s->top==-1;
}
bool isStackFull(Stack *s){
    return s->top == s->size-1;
}
int push(Stack *s, int item){
    if(isStackFull(s)){
        return -1;
    }
    s->top++;
    s->stack[s->top] = item;
    return 1;
}

int pop(Stack *s){
    if(isStackEmpty(s)){
        return -1;
    }
    int item = s->stack[s->top];
    s->top--;
    return item;
}



int printOptions() {
    printf("*********************\n");
    printf("*   Stack Operations: *\n");
    printf("*   1. Enqueue        *\n");
    printf("*   2. Dequeue        *\n");
    printf("*   3. END            *\n");
    printf("*********************\n");
    int option;
    printf("Enter choice : ");
    scanf("%d", &option);
    return option;
}

void printStack(Stack *s){
    printf("\n");
    for(int i = 0; i< s->size;i++){
        if(s->top>=i){
            printf("%d |", s->stack[i]);
            continue;
        }
        printf("  |");
    }
    printf("\n");
    printf("\n");
}