#include "../../GlobalLibrary/GenericStack.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isOperator(char);
float performOperation(float, float, char);
float evaluatePostfix(char *);
void printStack(Stack *);
char * postfixToInfix(char *);

int main()
{
  // Expression input code - begin
  printf("Enter Postfix Expression : ");
  char *postfixExpression = NULL;
  size_t size = 0;
  getline(&postfixExpression, &size, stdin);
  int expressionLen = strlen(postfixExpression);
  postfixExpression[expressionLen - 1] = '\0';
  // Expression input code - end

  printf("\nExpression output : %0.2f\n", evaluatePostfix(postfixExpression));
  return 1;
}

float evaluatePostfix(char *postfixExpression)
{
  char *t = postfixExpression;
  printf("\ninput : %s", postfixExpression);
  Stack *operandStack = createStack(strlen(postfixExpression));
  while (*t)
  {
    printf("\nOperand stack");
    printStack(operandStack);
    if (!isOperator(*t))
    {
      float *f = malloc(sizeof(float));
      *f = *t - '0';
      push(operandStack, f);
      t++;
      continue;
    }
    printf("Operator : %c\n", *t);
    float *secondOperand = pop(operandStack);
    float *firstOperand = pop(operandStack);
    float *result = malloc(sizeof(float));
    *result = performOperation(*firstOperand, *secondOperand, *t);
    push(operandStack, result);
    t++;
  }
  printf("\nOperand stack");
  printStack(operandStack);
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

void printStack(Stack *s)
{
  printf("\n");
  for (int i = 0; i < s->size; i++)
  {
    if (i <= s->top)
      printf("%0.2f |", *(float *)(s->stack[i]));
    else
      printf(" |");
  }
  printf("\n");
}

char * postfixToInfix(char *postfixExpression){

}