typedef struct ListNode
{
    void *data;
    struct ListNode *next;
} ListNode;

ListNode *createNode(void *);
void printList(ListNode **, void (*)(void *));
void printInt(void *);
void printFloat(void *);
void printChar(void *);
void printStr(void *);

bool insertFront(ListNode **, void *);
bool insertEnd(ListNode **, void *);
bool insertAfter(ListNode *, void *);

bool removeFront(ListNode **);
bool removeEnd(ListNode **);
bool removeAt(ListNode **, ListNode *);

ListNode *getFront(ListNode **head);
ListNode *getEnd(ListNode **head);
ListNode *get(ListNode **head, int);

ListNode *find(ListNode **, void *, bool (*)(void *, void *));
bool compareInt(void *, void *);
bool compareFloat(void *, void *);
bool compareString(void *, void *);
bool compareChar(void *, void *);