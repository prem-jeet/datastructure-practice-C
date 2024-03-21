#include "../Linked list/Doubly Circular Linked List/DoublyCircularLinkedList.h"
#include<stdbool.h>

struct queue{
    CDLL *queue;
    int size;
};
typedef struct queue* Queue;

Queue createQueue();
void enqueue(Queue, void *);
void *dequeue(Queue);
bool isEmpty(Queue);

