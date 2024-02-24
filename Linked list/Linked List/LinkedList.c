#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "LisnkedList.h"


ListNode *createNode(void *data)
{
    ListNode *n = malloc(sizeof(ListNode));
    if (!n)
        return NULL;
    n->next = NULL;
    n->data = data;
    return n;
}

bool insertEnd(ListNode **head, void *data)
{
    ListNode *newNode = createNode(data);
    if (!newNode)
    {
        printf("\nUnable to assign memory");
        return false;
    }
    if (*head == NULL)
    {
        *head = newNode;
        return true;
    }
    ListNode *l = *head;
    while (l->next)
        l = l->next;
    l->next = newNode;
    return true;
}
bool insertFront(ListNode **head, void *data)
{
    ListNode *newNode = createNode(data);
    if (!newNode)
    {
        printf("\nUnable to assign memory");
        return false;
    }
    if (*head == NULL)
    {
        *head = newNode;
        return true;
    }
    newNode->next = *head;
    *head = newNode;
    return true;
}
bool insertAfter(ListNode *l, void *data)
{
    if (l)
    {
        ListNode *newNode = createNode(data);
        if (!newNode)
            return false;
        newNode->next = l->next;
        l->next = newNode;
        return true;
    }
    return false;
}

void printList(ListNode **head, void (*print)(void *))
{
    printf("\n");
    if (!*head)
    {
        printf("List is Empty");
        return;
    }
    ListNode *l = *head;
    while (l)
    {
        print(l->data);
        l = l->next;
    }
    printf("NULL");
}
void printInt(void *data)
{
    printf("%d->", *(int *)data);
}
void printFloat(void *data)
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

bool removeEnd(ListNode **head)
{
    ListNode *l = *head;
    if (!(l && l->next))
    {
        free(l);
        *head = NULL;
        return true;
    }

    else
    {
        while (l->next->next)
            l = l->next;

        ListNode *t = l->next;
        l->next = NULL;
        free(t);
        return true;
    }
}
bool removeFront(ListNode **head)
{
    ListNode *l = *head;
    if (!(l && l->next))
    {
        free(l);
        *head = NULL;
        return true;
    }

    ListNode *t = l;
    *head = l->next;
    free(t);
    return true;
}
bool removeAt(ListNode **head, ListNode *target)
{
    ListNode *h = *head;
    if (h == target)
    {
        free(h);
        *head = NULL;
        return true;
    }
    while (h->next != target)
        h = h->next;
    h->next = target->next;
    free(target);
    return true;
}

ListNode *getFront(ListNode **head)
{
    if (!head)
        return NULL;
    return *head;
}
ListNode *getEnd(ListNode **head)
{
    if (!head)
        return NULL;
    ListNode *h = *head;
    while (h->next)
        h = h->next;
    return h;
}
ListNode *get(ListNode **head, int index)
{
    if (!*head)
        return NULL;
    int i = index;
    ListNode *t = *head;
    while (i-- > 0)
    {
        t = t->next;
        if (!t)
        {
            printf("\nIndex out of bound");
            return NULL;
        }
    }
    return t;
}
ListNode *find(ListNode **head, void *target, bool (*compare)(void *, void *))
{
    if (!*head)
        return NULL;
    ListNode *l = *head;
    while (l)
    {
        if (compare(l->data, target))
        {
            return l;
        }
        l = l->next;
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
bool compareString(void *a, void *b)
{
    return strcmp((char *)a, (char *)b);
}
bool compareChar(void *a, void *b)
{
    return (char *)a == (char *)b;
}