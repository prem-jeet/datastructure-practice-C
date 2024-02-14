#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX_SIZE 5

typedef struct{
    int queue[MAX_SIZE];
    int rare;
    int front;
}Queue;

bool isFull(Queue *);
void enqueue(Queue *, int);
int dequeue(Queue *);
void printQueue(Queue *);
int printOptions();
int main(){
    Queue *q = (Queue *)malloc(1*sizeof(Queue));
    q->front = -1;
    q->rare = -1;

    int option,item;
    bool terminate = false;
    while(true){
        if(terminate)break;
        printQueue(q);
        option = printOptions();
        switch(option){
            default:
            printf("\nInvalid option\n");
            terminate = true;
            break;
            case 1:
            printf("\n Enter the item : ");
            scanf("%d", &item);
            enqueue(q,item);
            break;
            case 2:
            item = dequeue(q);
            if(item > -1)
            printf("\nRemoved %d\n",item);
            break;
            case 3:
            terminate = true;
        }
    }
    printQueue(q);
    return 1;
}


bool isFull(Queue *q){
    return (q->rare + 1)%MAX_SIZE == q->front;
}

void enqueue(Queue *q,int item){
    if(isFull(q)){
        printf("\nQueue is full\n");
        return;
    }
    if(q->rare==-1){
        q->rare=q->front=0;
    }
    else{
        q->rare = (q->rare + 1)%MAX_SIZE;
    }

    q->queue[q->rare]=item;
}

int dequeue(Queue *q){
    if(q->rare == -1){
        printf("\nQueue is empty\n");
        return -1;
    }
    int returnValue = q->queue[q->front];

    if(q->front == q->rare){
        q->front=q->rare=-1;
    }else{
        q->front = (q->front+1)% MAX_SIZE;
    }
    
    return returnValue;

}

void printQueue(Queue *q){
    printf("\n");
    bool isWrapped = q->front > q->rare;
    for(int i = 0; i<MAX_SIZE; i++){
        if(isWrapped && (i<=q->rare || i>=q->front)){
            printf("%d |", q->queue[i]);
            continue;
        }
        if(!isWrapped && (i<=q->rare && i>=q->front)){
            printf("%d |", q->queue[i]);
            continue;
        }
        printf("  |");
        
    }
    printf("\n");
    printf("\n");
}

 int printOptions() {
    printf("*********************\n");
    printf("*   Queue Operations: *\n");
    printf("*   1. Enqueue        *\n");
    printf("*   2. Dequeue        *\n");
    printf("*   3. END            *\n");
    printf("*********************\n");
    int option;
    printf("Enter your choice : ");
    scanf("%d", &option);
    return option;
}
