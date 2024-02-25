#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct ListNode
{
    void *data;
    struct ListNode *next;
} ListNode;
typedef struct CLL
{
    ListNode *head;
    ListNode *rear;

    int capacity;
} CLL;

CLL *createCLL();
ListNode *createNode(void *);

bool insertFront(CLL *, void *);
bool insertRear(CLL *, void *);
bool insertAfter(CLL *, void *);
bool insertAt(CLL *, void *, int);

ListNode *find(CLL *, void *, bool (*)(void *, void *));
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
    for (int i = 0; i < 5; i++)
    {
        int *data = malloc(sizeof(int));
        *data = i;
        i % 2 ? insertRear(cll, data) : insertFront(cll, data);
    }
    printCLL(cll, printInt);
    int *data = malloc(sizeof(int));
    *data = 200;
    insertAt(cll, data, 3);
    printCLL(cll, printInt);
    data = malloc(sizeof(int));
    *data = 200;
    insertAt(cll, data, 0);
    printCLL(cll, printInt);

    return 1;
}

CLL *createCLL()
{
    CLL *cll = malloc(sizeof(CLL));
    cll->rear = cll->head = NULL;
    cll->capacity = 0;
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
    if (cll && data)
    {

        ListNode *newNode = createNode(data);
        if (!newNode)
            return false;
        cll->capacity++;
        if (!cll->head)
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
bool insertRear(CLL *cll, void *data)
{
    if (cll && data)
    {
        ListNode *newNode = createNode(data);
        if (!newNode)
            return false;
        cll->capacity++;
        if (!cll->head)
        {
            cll->rear = cll->head = newNode;
            return true;
        }
        newNode->next = cll->rear->next;
        cll->rear->next = newNode;
        cll->rear = newNode;
        return true;
    }
    return false;
}
bool insertAt(CLL *cll, void *data, int index)
{
    if (index > -1 && index < cll->capacity - 1 && cll && data)
    {
        if (index == 0)
            return insertFront(cll, data);
        int count = 0;
        ListNode *t = cll->head;
        while (++count != index)
            t = t->next;
        ListNode *newNode = createNode(data);
        if (!newNode)
            return false;
        newNode->next = t->next;
        t->next = newNode;
        cll->capacity++;
        return true;
    }
    return false;
}

ListNode *find(CLL *cll, void *data, bool (*compare)(void *, void *))
{
    if (cll && cll->head && data && compare)
    {
        if (cll->head == cll->rear && compare(data, cll->head->data))
            return cll->head;
        ListNode *l = cll->head;
        do
        {
            if (compare(l->data, data))
            {
                return l;
            }
            l = l->next;
        } while (l != cll->head);
    }
    return NULL;
}
bool compareInt(void *a, void *b)
{
    return *(int *)a == *(int *)b;
}
bool compareFloat(void *a, void *b)
{
    return *(float *)a == *(float *)b;
}
bool compareChar(void *a, void *b)
{
    return *(char *)a == *(char *)b;
}
bool compareStr(void *a, void *b)
{
    return strcmp((char *)a, (char *)b);
}

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