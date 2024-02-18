#include "../../GlobalLibrary/Stack.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isOperator(char);
int performOperation(int, int, char);
int evaluatePostfix(char *);
int main() {
  // Expression input code - begin
  printf("Enter Postfix Expression : ");
  char *postfixExpression = NULL;
  size_t size = 0;
  getline(&postfixExpression, &size, stdin);
  int expressionLen = strlen(postfixExpression);
  postfixExpression[expressionLen - 1] = '\0';
  // Expression input code - end

  printf("\nExpression output : %d\n", evaluatePostfix(postfixExpression));
  return 1;
}

int evaluatePostfix(char *postfixExpression) {
  char *t = postfixExpression;
  printf("\ninput : %s", postfixExpression);
  Stack *operandStack = createStack(strlen(postfixExpression));
  while (*t) {
    printf("\nOperand stack");
    printStack(operandStack);
    if (!isOperator(*t)) {
      push(operandStack, *t - '0');
      t++;
      continue;
    }
    printf("Operator : %c\n", *t);
    int secondOperand = pop(operandStack);
    int firstOperand = pop(operandStack);
    push(operandStack, performOperation(firstOperand, secondOperand, *t));
    t++;
  }
  printf("\nOperand stack");
  printStack(operandStack);
  return pop(operandStack);
}

bool isOperator(char c) {
  return c == '+' || c == '-' || c == '/' || c == '*' || c == '^';
}
int performOperation(int firstOperand, int secondOperand, char operator) {
  switch (operator) {
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