#include "../../GlobalLibrary/FloatStack.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isOperator(char);
float performOperation(float, float, char);
float evaluatePostfix(char *);
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
  FloatStack *operandStack = createFloatStack(strlen(postfixExpression));
  while (*t)
  {
    printf("\nOperand stack");
    printStack(operandStack);
    if (!isOperator(*t))
    {
      push(operandStack, *t - '0');
      t++;
      continue;
    }
    printf("Operator : %c\n", *t);
    float secondOperand = pop(operandStack);
    float firstOperand = pop(operandStack);
    push(operandStack, performOperation(firstOperand, secondOperand, *t));
    t++;
  }
  printf("\nOperand stack");
  printStack(operandStack);
  return pop(operandStack);
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