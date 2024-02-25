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

    int size;
} CLL;

CLL *createCLL();
ListNode *createNode(void *);

bool insertFront(CLL *, void *);
bool insertRare(CLL *, void *);
bool insertAfter(CLL *, void *);
bool insertAt(CLL *, void *, int);

bool find(CLL *, void *, bool (*)(void *, void *));
bool compareInt(void *, void *);
bool compareFloat(void *, void *);
bool compareChar(void *, void *);
bool compareStr(void *, void *);

void printCLL(CLL *, void (*)(void *));
void printInt(void *);
void printFront(void *);
void printChar(void *);
void printStr(void *);
int main()
{
    CLL *cll = createCLL();
    for (int i = 0; i < 3; i++)
    {
        int *data = malloc(sizeof(int));
        *data = i;
        insertFront(cll, data);
    }
    printCLL(cll, printInt);
    return 1;
}

CLL *createCLL()
{
    CLL *cll = malloc(sizeof(CLL));
    cll->rear = cll->head = NULL;
    cll->size = 0;
    return cll;
}
ListNode *createNode(void *data)
{
    ListNode *l = malloc(sizeof(ListNode));
    if (!l)
    {
        printf("\nUnabel to assign memory");
        return NULL;
    }
    l->next = NULL;
    l->data = data;
    return l;
}

bool insertFront(CLL *cll, void *data)
{
    if (cll)
    {
        ListNode *head = cll->head;
        ListNode *newNode = createNode(data);
        if (!head)
        {
            cll->rear = cll->head = newNode;
            return true;
        }
        cll->rear->next = newNode;
        newNode->next = cll->head;
        cll->head = newNode;
        return true;
    }
    return false;
}
bool insertRare(CLL *, void *);

void printCLL(CLL *cll, void (*print)(void *))
{
    if (cll && print)
    {
        ListNode *n = cll->head;
        while (true)
        {
            print(n->data);
            n = n->next;
            if (n == cll->head)
                break;
        }
        printf("\n");
    }
}

void printInt(void *data)
{
    printf("%d->", *(int *)data);
}
void printFront(void *data)
{
    printf("%0.2f->", *(float *)data);
}
void printChar(void *data)
{
    printf("%c->", *(char *)data);
}
void printStr(void *data)
{
    printf("%s->", (char *)data);
}