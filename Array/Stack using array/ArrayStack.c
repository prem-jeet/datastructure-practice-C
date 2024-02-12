#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

#define MAX_SIZE 10

typedef struct {
    int stack[MAX_SIZE];
    int top;
}Stack;


bool isEmpty(Stack *);
bool isFull(Stack *);
int pop(Stack *);
int peek(Stack *);
void push(Stack *, int);
int printOptions();
void printStack(Stack *, int);

int main(){
    Stack *s = (Stack *)malloc(1*sizeof(Stack));
    s->top =-1;

    int option, terminate=0, item;
    while(true){
        printf("\n \n");
       if(terminate) break;

        printStack(s, MAX_SIZE);
        int option = printOptions();
        
        switch(option){
            default: 
                printf("Invalid option \n");
                getchar();
                break;
            case 1:
                scanf("%d", &item);
                push(s, item);
                break;
            case 2:
                item = pop(s);
                if (item !=-1) printf("\n Removed %d", item);
                getchar();
                break;
            case 3:
                item = peek(s);
                if (item !=-1) printf("\n TOP of the stack contains %d", item);
                getchar();
                break;
            case 4:
                terminate = 1;
                break;
        }
    }
    return 1;
}

bool isEmpty(Stack *s){
    return s->top==-1;
}
bool isFull(Stack *s){
    return s->top==MAX_SIZE-1;
}
void push(Stack *s, int item){
    if(isFull(s)){
        printf("Overflow");
        getchar();
        return;
    }
    s->top++;
    s->stack[s->top] = item;
}

int _PSUDO_POP(Stack *s, bool delete){
    if(isEmpty(s)){
        printf("Underflow");
        return -1;
    }
    int item = s->stack[s->top];
    if(delete){
        s->top--;
    }
    return item;
}

int pop(Stack *s){
    return _PSUDO_POP(s,true);
}
int peek(Stack *s){
    return _PSUDO_POP(s, false);
}

int printOptions() {
    printf("*********************\n");
    printf("*   Stack Operations: *\n");
    printf("*   1. PUSH           *\n");
    printf("*   2. POP            *\n");
    printf("*   3. PEEK           *\n");
    printf("*   4. END            *\n");
    printf("*********************\n");
    int option;
    scanf("%d", &option);
    return option;
}

void printStack(Stack *s,int size){
    printf("\n");
    for(int i = 0; i< size;i++){
        if(s->top>=i){
            printf("%d |", s->stack[i]);
            continue;
        }
        printf("  |");
    }
    printf("\n");
    printf("\n");
}