#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "DoublyLinkedList.h"


DLLNode *createDLLNode(void *data)
{
    DLLNode *n = malloc(sizeof(DLLNode));
    if (!n)
        return NULL;
    n->next = n->prev = NULL;
    n->data = data;
    return n;
}
DLL *createDLL()
{
    DLL *dll = malloc(sizeof(DLL));
    if (!dll)
        return NULL;
    dll->head = dll->rear = NULL;
    dll->capacity = 0;
    return dll;
}

bool insertFront(DLL *dll, void *data)
{
    if (!(dll && data))
        return false;
    DLLNode *newNode = createDLLNode(data);
    if (!newNode)
        return false;
    dll->capacity++;
    if (!dll->head)
    {
        dll->head = dll->rear = newNode;
        return true;
    }

    newNode->next = dll->head;
    dll->head->prev = newNode;
    dll->head = newNode;
    return true;
}
bool insertRear(DLL *dll, void *data)
{
    if (!(dll && data))
        return false;
    DLLNode *newNode = createDLLNode(data);
    if (!newNode)
        return false;
    dll->capacity++;
    if (!dll->head)
    {
        dll->head = dll->rear = newNode;
        return true;
    }
    newNode->prev = dll->rear;
    dll->rear->next = newNode;
    dll->rear = newNode;
    return true;
}
bool insertAfter(DLL *dll, void *data, DLLNode *target)
{
    if (!(dll && data && target))
        return false;
    if (target == dll->rear)
        return insertRear(dll, data);
    dll->capacity++;
    DLLNode *newNode = createDLLNode(data);
    if (!newNode)
        return false;

    newNode->next = target->next;
    newNode->prev = target;
    newNode->next->prev = newNode;
    target->next = newNode;
    return true;
}
bool insertAt(DLL *dll, void *data, int index)
{
    if (!(dll && data && index > -1 && index < dll->capacity))
        return false;
    if (index == 0)
        return insertFront(dll, data);
    if (index == dll->capacity - 1)
        return insertRear(dll, data);
    if (!data)
        return false;
    dll->capacity++;
    DLLNode *n = dll->head;
    int count = 1;
    while (count++ != index)
        n = n->next;
    return insertAfter(dll, data, n);
}

DLLNode *getFront(DLL *dll)
{
    if (!(dll && dll->head))
        return NULL;
    return dll->head;
}
DLLNode *getRear(DLL *dll)
{
    if (!(dll && dll->head))
        return NULL;
    return dll->rear;
}
DLLNode *getFrom(DLL *dll, int index)
{
    if (!(dll && dll->head && index > -1 && index < dll->capacity))
        return NULL;
    int count = 0;
    DLLNode *n = dll->head;
    while (count++ != index)
        n = n->next;
    return n;
}

bool deleteFront(DLL *dll)
{
    if (!(dll && dll->head))
        return false;
    dll->capacity--;

    DLLNode *n = dll->head;
    dll->head = n->next;
    free(n);
    if (!dll->head)
    {
        dll->head = dll->rear = NULL;
    }
    else
    {
        dll->head->prev = NULL;
    }
    return true;
}
bool deleteRear(DLL *dll)
{
    if (!(dll && dll->head))
        return false;
    DLLNode *n = dll->rear;
    dll->rear = n->prev;
    free(n);
    dll->capacity--;
    if (!dll->rear)
    {
        dll->head = dll->rear = NULL;
    }
    else
    {
        dll->rear->next = NULL;
    }
    return true;
}
bool deleteAfter(DLL *dll, DLLNode *target)
{
    if (!(dll && dll->head && target))
        return false;
    if (target == dll->rear)
        return false;
    if (target->next == dll->rear)
        return deleteRear(dll);
    dll->capacity--;
    DLLNode *n = target->next;
    target->next = n->next;
    n->next->prev = target;
    free(n);
    return true;
}
bool deleteFrom(DLL *dll, int index)
{
    if (!(dll && dll->head && index > -1 && index < dll->capacity))
        return false;
    if (index == 0)
        return deleteFront(dll);
    if (index == dll->capacity - 1)
        return deleteRear(dll);
    DLLNode *n = dll->head;
    int count = 1;
    while (count++ != index)
        n = n->next;
    return deleteAfter(dll, n);
}

DLLNode *find(DLL *dll, void *data, bool (*compare)(void *, void *))
{
    if (!(dll && dll->head && data && compare))
        return NULL;
    DLLNode *n = dll->head;
    while (true)
    {
        if (!n)
            return NULL;
        bool isEqual = compare(n->data, data);
        if (isEqual)
            return n;
        n = n->next;
    }
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

void printDLL(DLL *dll, void (*print)(void *))
{
    if (!(dll && print))
        return;
    if (!dll->head)
    {
        printf("\nList is empty");
        return;
    }
    DLLNode *n = dll->head;

    while (n)
    {
        printf(n == dll->head ? " <- " : " <-> ");
        print(n->data);
        printf(n == dll->rear ? " -> " : "");
        n = n->next;
    }
    printf("\n");
}
void printInt(void *data)
{
    printf("%d", *(int *)data);
}
void printFloat(void *data)
{
    printf("%0.2f", *(float *)data);
}
void printChar(void *data)
{
    printf("%c", *(char *)data);
}
void printStr(void *data)
{
    printf("%s", (char *)data);
}