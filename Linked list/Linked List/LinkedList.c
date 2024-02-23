#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ListNode
{
    void *data;
    struct ListNode *next;
} ListNode;

ListNode *createNode(void *);
bool insertAtEnd(ListNode **, void *);
bool insertAtStart(ListNode **, void *);
ListNode *removeFromEnd(ListNode **);
ListNode *removeFromStart(ListNode **);

void printIntegerList(ListNode **);

int main()
{
    ListNode *head = NULL;
    for (int i = 0; i < 3; i++)
    {
        int *data = malloc(sizeof(int));
        *data = i;
        i % 2 ? insertAtEnd(&head, data) : insertAtStart(&head, data);
    }
    printIntegerList(&head);
    for (int i = 0; i < 4; i++)
    {

        i % 2 ? removeFromStart(&head) : removeFromEnd(&head);
        printIntegerList(&head);
    }

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