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
bool insertAfter(CLL *, void *, ListNode *);
bool insertAt(CLL *, void *, int);

ListNode *getFront(CLL *);
ListNode *getRear(CLL *);
ListNode *getFrom(CLL *, int);

bool deleteFront(CLL *);
bool deleteRear(CLL *);
bool deleteAfter(CLL *, ListNode *);
bool deleteAt(CLL *, int);

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
        printf("Capacity :%d\n", cll->capacity);
    }
    printCLL(cll, printInt);
    printf("Capacity :%d\n", cll->capacity);

    int *data = malloc(sizeof(int));
    *data = 200;
    insertAt(cll, data, 3);
    printCLL(cll, printInt);
    printf("Capacity :%d\n", cll->capacity);

    data = malloc(sizeof(int));
    *data = 200;
    insertAt(cll, data, 0);
    printCLL(cll, printInt);
    printf("Capacity :%d\n", cll->capacity);

    data = malloc(sizeof(int));
    *data = 0;
    ListNode *a = find(cll, data, compareInt);
    int *newNode = malloc(sizeof(int));
    *newNode = 101;
    insertAfter(cll, newNode, a);
    printCLL(cll, printInt);
    printf("Capacity :%d\n", cll->capacity);
    data = malloc(sizeof(int));
    *data = 3;
    ListNode *b = find(cll, data, compareInt);
    newNode = malloc(sizeof(int));
    *newNode = 103;
    insertAfter(cll, newNode, b);
    printCLL(cll, printInt);
    printf("Capacity :%d\n", cll->capacity);

    ListNode *l = getFrom(cll, 4);
    printInt(l->data);
    printf("\n Starting delete operation");
    for (int i = 0; i < 10; i++)
    {
        printf("\nDelete : ");
        i%2 ? deleteFront(cll) : deleteRear(cll);
        printCLL(cll, printInt);
    }

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
bool insertAfter(CLL *cll, void *data, ListNode *target)
{
    if (cll && cll->head && data && target)
    {
        if (target == cll->rear)
            return insertRear(cll, data);
        ListNode *newNode = createNode(data);
        if (!newNode)
            return false;
        newNode->next = target->next;
        target->next = newNode;
        cll->capacity++;
        return true;
    }
    return false;
}

bool deleteFront(CLL *cll)
{
    if (cll && cll->head)
    {
        ListNode *l = cll->head;
        cll->capacity--;
        if (l == cll->rear)
        {
            cll->head = cll->rear = NULL;
        }
        else
        {
            cll->head = l->next;
            cll->rear->next = cll->head;
        }
        free(l);
        return true;
    }
    return false;
}
bool deleteRear(CLL *cll)
{
    if (cll && cll->head)
    {
        cll->capacity--;
        if (cll->head == cll->rear)
        {
            cll->head = cll->rear = NULL;
            return true;
        }
        ListNode *l = cll->head;
        while (l->next != cll->rear)
            l = l->next;
        l->next = cll->rear->next;
        free(cll->rear);
        cll->rear = l;
        return true;
    }
    return false;
}
bool deleteAfter(CLL *, ListNode *);
bool deleteAt(CLL *, int);

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

ListNode *getFront(CLL *cll)
{
    if (cll && cll->head)
    {
        return cll->head;
    }
    return NULL;
}
ListNode *getRear(CLL *cll)
{
    if (cll && cll->rear)
    {
        return cll->rear;
    }
    return NULL;
}
ListNode *getFrom(CLL *cll, int index)
{
    if (cll && cll->head && index > -1 && index < cll->capacity)
    {
        int count = 0;
        ListNode *l = cll->head;

        while (true)
        {
            if (count > index)
                return NULL;
            if (count == index)
                return l;
            count++;
            l = l->next;
        }
    }
    return NULL;
}

void printCLL(CLL *cll, void (*print)(void *))
{
    if (cll && print)
    {
        ListNode *n = cll->head;
        if (!n)
        {
            printf("\nList is Empty");
            return;
        }
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