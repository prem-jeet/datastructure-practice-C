#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "../../GlobalLibrary/GenericStack.h"

bool isOperator(char);
float performOperation(float, float, char);
float evaluatePrefix(char *);
void printFloatStack(Stack *);
int main()
{
    char *prefixExpression = NULL;
    size_t size = 0;
    printf("Enter preffix Expression : ");
    getline(&prefixExpression, &size, stdin);
    int len = strlen(prefixExpression);
    prefixExpression[len - 1] = '\0';

    Stack *operandStack = createStack(len);
    float result = evaluatePrefix(prefixExpression);
    printf("\nThe Prefix Expression evaluates to : %0.2f", result);
    return 1;
}

float evaluatePrefix(char *prefixExpression)
{
    int index = strlen(prefixExpression);
    Stack *operandStack = createStack(index);
    while (--index > -1)
    {
        char curr = prefixExpression[index];
        float *f = malloc(sizeof(float));
        printf("\nOperand Stack:");
        printFloatStack(operandStack);
        if (isOperator(prefixExpression[index]))
        {
            printf("Operator : %c", curr);
            float *firstOperand = pop(operandStack);
            float *secondOperand = pop(operandStack);

            *f = performOperation(*firstOperand, *secondOperand, curr);
        }
        else
        {
            *f = curr - '0';
        }

        push(operandStack, f);
    }
    return *(float *)pop(operandStack);
}

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '/' || c == '*' || c == '^';
}

float performOperation(float firstOperand, float secondOperand, char operator)
{
    switch (operator)
    {
    case '+':
        return firstOperand + secondOperand;
    case '-':
        return firstOperand - secondOperand;
    case '*':
        return firstOperand * secondOperand;
    case '/':
        return firstOperand / secondOperand;
    case '^':
        return pow(firstOperand, secondOperand);
    }
}

void printFloatStack(Stack *s)
{
    printf("\n");
    for (int i = 0; i < s->size; i++)
    {
        if (i <= s->top)
        {
            printf("%0.2f  | ", *(float *)s->stack[i]);
            continue;
        }
        printf("  | ");
    }
    printf("\n");
}