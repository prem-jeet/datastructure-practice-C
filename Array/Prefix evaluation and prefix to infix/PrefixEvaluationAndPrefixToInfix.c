#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../../GlobalLibrary/GenericStack.h"

int main()
{
    char *prefixExpression = NULL;
    size_t size = 0;
    printf("Enter preffix Expression : ");
    getline(&prefixExpression, &size, stdin);
    int len = strlen(prefixExpression);
    prefixExpression[len - 1] = '\0';

    

    return 1;
}