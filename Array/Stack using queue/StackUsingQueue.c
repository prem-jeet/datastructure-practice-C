#include<stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include "../Queue.h"

int main(){

    Queue* q  = createQueue(10);
    printQueue(q);

    return 1;
}