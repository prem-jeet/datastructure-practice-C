#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX_SIZE 11

typedef struct {
    int stack[MAX_SIZE];
    int top1;
    int top2;
}Stack;

bool isFull(Stack *);
void printStack(Stack *);
int displayOptions();
void pushIn1(Stack *,int);
void pushIn2(Stack *,int);
void _PSUDO_PUSH(Stack *, int,int);
int popFrom1(Stack *);
int popFrom2(Stack *);

int main(){
    Stack *s = (Stack *)calloc(1,sizeof(Stack));
    s->top1 = -1;
    s->top2= MAX_SIZE;
    int item,option,terminate=0;

    while(true){
        if(terminate) break;
        printStack(s);
        option = displayOptions();
        switch(option){
            default:
            printf("Invalid option \n");
            terminate = 1;
            break;
            case 1:
            printf("Enter the item to be inserted : ");
            scanf("%d", &item);
            pushIn1(s,item);
            break;
            case 2:
            printf("Enter the item to be inserted : ");
            scanf("%d", &item);
            pushIn2(s,item);
            break;
            case 3:
            item = popFrom1(s);
            if(item > -1){
                printf("Popped %d from Left stack\n", item);
                
            }
            break;
            case 4:
            item = popFrom2(s);
            if(item > -1){
                printf("Popped %d from Right stack\n", item);
                
            }
            break;
            case 5:
            terminate = 1;
            break;
        }
    }
    return 1;
}


int popFrom1(Stack *s){
    if(s->top1==-1){
        printf("Underflow \n");
        return -1;
    }
    int item = s->stack[s->top1];
    s->top1--;
    return item;
}
int popFrom2(Stack *s){
    if(s->top2 == MAX_SIZE){
        printf("Underflow \n");
        return -1;
    }
    int item = s->stack[s->top2];
    s->top2++;
    return item;
}

void _PSUDO_PUSH(Stack *s, int item, int stackId){
    if(isFull(s)){
         printf("Stack is full \n");       
         return;}
    if(stackId){
        s->top2--;
        s->stack[s->top2] = item;
    }else{
        s->top1++;
        s->stack[s->top1] = item;

    }
}


void pushIn1(Stack *s,int item){
    _PSUDO_PUSH(s,item,0);
}
void pushIn2(Stack *s,int item){
    _PSUDO_PUSH(s,item,1);
}

bool isFull(Stack *s){
    return s->top1+1 == s->top2;
}

void printStack(Stack *s){
    printf("\n");
    for(int i=0;i<MAX_SIZE;i++){
        if(i<=s->top1 || i>=s->top2){
            printf("%d |",s->stack[i]);
        }else{
            printf("  |");
        }
    }
    printf("\n");
    printf("\n");
}

int displayOptions(){
  printf("*******************************\n");
    printf("*   Stack Operations:       *\n");
    printf("*   1. PUSH in Stack1       *\n");
    printf("*   2. PUSH in Stack2       *\n");
    printf("*   3. POP from Stack1      *\n");
    printf("*   4. POP from Stack2      *\n");
    printf("*   5. END                  *\n");
    printf("*****************************\n");
    int option;
    scanf("%d", &option);
    return option;
}