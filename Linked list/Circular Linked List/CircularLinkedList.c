#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "CircularLinkedList.h"

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
bool deleteAfter(CLL *cll, ListNode *target)
{
    if (cll && cll->head && target)
    {
        if (target == cll->rear)
            return deleteFront(cll);
        cll->capacity--;
        if (target == cll->rear && cll->rear == cll->head)
        {
            free(cll->head);
            cll->head = cll->rear = NULL;
            return true;
        }
        ListNode *l = target->next;
        target->next = l->next;
        if (l == cll->rear)
            cll->rear = target;
        free(l);
        return true;
    }
    return true;
}
bool deleteAt(CLL *cll, int index)
{
    if (cll && cll->head && index > -1 && index < cll->capacity)
    {
        if (index == 0)
            return deleteFront(cll);
        if (index == cll->capacity - 1)
            return deleteRear(cll);
        ListNode *l = cll->head;
        int count = 1;
        while (count++ != index)
            l = l->next;
        return deleteAfter(cll, l);
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