#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ListNode
{
    void *data;
    struct ListNode *next;
} ListNode;
typedef struct CLL
{
    ListNode *head;
    ListNode *rear;
    ListNode *front;
    int size;
} CLL;

CLL *createCLL();
bool insertFront(CLL *);
bool insertRare(CLL *);
bool insertAfter(CLL *, ListNode *);
bool insertAt(CLL *, int);

bool find(CLL *, void *, bool (*)(void *, void *));
bool compareInt(void *, void *);
bool compareFloat(void *, void *);
bool compareChar(void *, void *);
bool compareStr(void *, void *);

void printCLL(CLL *, void(*)(void *));
void printInt(void *);
void printFront(void *);
void printChar(void *);
void printStr(void *);
int main()
{
    CLL *cll = createCLL();
    return 1;
}

CLL *createCLL()
{
    CLL *cll = malloc(sizeof(CLL));
    cll->front = cll->rear = cll->head = NULL;
    cll->size = 0;
    return cll;
}