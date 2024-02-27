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