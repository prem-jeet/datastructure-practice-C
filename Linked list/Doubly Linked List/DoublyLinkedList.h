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
    int capacity;
} DLL;

DLLNode *createDLLNode(void *);
DLL *createDLL();

bool insertFront(DLL *, void *);
bool insertRear(DLL *, void *);
bool insertAfter(DLL *, void *, DLLNode *);
bool insertAt(DLL *, void *, int);

DLLNode *find(DLL *, void *, bool (*)(void *, void *));
bool compareInt(void *, void *);
bool compareFloat(void *, void *);
bool compareChar(void *, void *);
bool compareStr(void *, void *);

bool deleteFront(DLL *);
bool deleteRear(DLL *);
bool deleteAfter(DLL *, DLLNode *);
bool deleteFrom(DLL *, int);

DLLNode *getFront(DLL *);
DLLNode *getRear(DLL *);
DLLNode *getFrom(DLL *, int);

void printDLL(DLL *, void (*)(void *));
void printInt(void *);
void printFloat(void *);
void printChar(void *);
void printStr(void *);
