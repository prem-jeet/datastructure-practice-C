#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct DLLNode
{
    void *data;
    struct DLLNode *next;
    struct DLLNode *prev;
} DLLNode;

typedef struct
{
    DLLNode *head;
    DLLNode *rear;
    int size;
} DLL;

DLLNode *createDLLNode(void *);
DLL *createDLL();

bool insertFront(DLL *, void *);
bool insertRear(DLL *, void *);
bool insertAfter(DLL *, void *, DLLNode *);
bool insertAt(DLL *, void *);

DLLNode *find(DLL *, void *, bool (*)(void *, void *));
bool compareInt(void *, void *);
bool compareFloat(void *, void *);
bool compareChar(void *, void *);
bool compareStr(void *, void *);

bool deleteFront(DLL *);
bool deleteRear(DLL *);
bool deleteAfter(DLL *, DLLNode *);
bool deleteFrom(DLL *);

DLLNode *getFront(DLL *);
DLLNode *getRear(DLL *);
DLLNode *getFrom(DLL *, int);

void printDLL(DLL *, void (*)(void *));
void printInt(void *);
void printFloat(void *);
void printChar(void *);
void printStr(void *);

int main()
{
    return 1;
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
        printf(n == dll->head ? "<-" : "<->");
        print(n->data);
        printf(n == dll->rear ? "->" : "<->");
    }
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