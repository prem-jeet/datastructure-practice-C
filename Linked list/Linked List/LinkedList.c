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
void printIntegerList(ListNode **);

bool insertFront(ListNode **, void *);
bool insertEnd(ListNode **, void *);
bool insertAfter(ListNode *, void *);

bool removeFront(ListNode **);
bool removeEnd(ListNode **);
bool removeAt(ListNode **, ListNode *);

ListNode *getFront(ListNode **head);
ListNode *getEnd(ListNode **head);
ListNode *getFront(ListNode **head);

ListNode *find(ListNode **, void *, bool (*)(void *, void *));
bool compareInt(void *, void *);
bool compareFloat(void *, void *);
bool compareString(void *, void *);
bool compareChar(void *, void *);

int main()
{
    ListNode *head = NULL;
    for (int i = 0; i < 10; i++)
    {
        int *data = malloc(sizeof(int));
        *data = i;
        i % 2 ? insertAtEnd(&head, data) : insertAtStart(&head, data);
    }
    printIntegerList(&head);
    int item = 0;
    ListNode *target = find(&head, &item, compareInt);
    removeAt(&head, target);
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