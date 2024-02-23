#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct ListNode
{
    void *data;
    struct ListNode *next;
} ListNode;

ListNode *createNode(void *);
bool insertAtEnd(ListNode **, void *);
bool insertAtStart(ListNode **, void *);
bool insertAfter(ListNode *, void *);

ListNode *removeFromEnd(ListNode **);
ListNode *removeFromStart(ListNode **);

void printIntegerList(ListNode **);

ListNode *find(ListNode **, void *, bool (*)(void *, void *));
bool compareInt(void *, void *);
bool compareFloat(void *, void *);
bool compareString(void *, void *);
bool compareChar(void *, void *);

int main()
{
    ListNode *head = NULL;
    for (int i = 0; i < 5; i++)
    {
        int *data = malloc(sizeof(int));
        *data = i;
        i % 2 ? insertAtEnd(&head, data) : insertAtStart(&head, data);
    }
    printIntegerList(&head);
    int *key = malloc(sizeof(int));
    *key = 2;
    ListNode *n = find(&head, key, compareInt);
    if (n)
    {
        *key = 12;
        insertAfter(n, key);
    }
    printIntegerList(&head);
    key = malloc(sizeof(int));
    *key = 3;
    n = find(&head, key, compareInt);
    if (n)
    {
        *key = 13;
        insertAfter(n, key);
    }
    printIntegerList(&head);

    return 1;
}

ListNode *createNode(void *data)
{
    ListNode *n = malloc(sizeof(ListNode));
    if (!n)
        return NULL;
    n->next = NULL;
    n->data = data;
    return n;
}

bool insertAtEnd(ListNode **head, void *data)
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

bool insertAtStart(ListNode **head, void *data)
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

void printIntegerList(ListNode **head)
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
        printf("%d->", *(int *)l->data);
        l = l->next;
    }
    printf("NULL");
}

ListNode *removeFromEnd(ListNode **head)
{
    ListNode *l = *head;
    if (!l)
    {
        return NULL;
    }

    if (!l->next)
    {
        *head = NULL;
        return l;
    }
    else
    {
        while (l->next->next)
            l = l->next;

        ListNode *t = l->next;
        l->next = NULL;
        return t;
    }
}
ListNode *removeFromStart(ListNode **head)
{
    ListNode *l = *head;
    if (!l)
    {
        return NULL;
    }

    if (!l->next)
    {
        *head = NULL;
        return l;
    }
    else
    {
        *head = l->next;
        return l;
    }
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