#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../../GlobalLibrary/CharStack.h"

bool shouldPop(char, char);
int findPrecedence(char);
char* strReverse(char *);
char* infixToPostfix(char *);
int main()
{
    // To take user input as string
    char *infixExpression = NULL; // Pointer to char, initialized to NULL
    size_t size = 0;              // Initial size is 0, getline will allocate memory as needed
    printf("Infix to Postfix convertor, use alphabets, + - * / ^ and only this brackets ()\n");
    printf("Enter infix experssion : ");
    getline(&infixExpression, &size, stdin);
    infixExpression[strlen(infixExpression) - 1] = '\0';

    char *postfixExpression = infixToPostfix(infixExpression);

    printf("Postfix expression is : %s\n", postfixExpression);

    return 0;
}

bool shouldPop(char top, char curr)
{
    if (top == '?' || top == '(')
        return false;
    int precedenceTop = findPrecedence(top);
    int precedenceCurr = findPrecedence(curr);
    return precedenceTop < precedenceCurr ? false : precedenceTop > precedenceCurr ? true
                                                                                   : curr != '^';
}

int findPrecedence(char c)
{
    if (c == '+' || c == '-')
        return 1;
    if (c == '/' || c == '*')
        return 2;
    if (c == '^')
        return 3;
}

char* strReverse(char* c){
    int len = strlen(c);
    
    char *revC = calloc(len, sizeof(char));
    int cIndex = len-2, revCIndex=0;
    
    while(cIndex>=0){
        char curr =  c[cIndex--];
        if(curr == '(') curr=')';
        else if(curr == ')') curr='(';
        revC[revCIndex++] = curr;    
    }
    return revC;
}

char *infixToPostfix(char *infixExpression){
    Stack *operatorStack = createStack(strlen(infixExpression));
    char *t = infixExpression;
    char *postfix = calloc(strlen(infixExpression) + 1, sizeof(char));
    int postfixIndex = 0;

    while (*t)
    {

        char curr = *t;
        bool isOperator = curr == '+' || curr == '-' || curr == '/' || curr == '*' || curr == '^' || curr == '(' || curr == ')';

        if (!isOperator)
        {
            postfix[postfixIndex++] = curr;
            t++;
            continue;
        }

        if (curr == '(')
        {
            push(operatorStack, curr);
            t++;
            continue;
        }

        if (curr == ')')
        {
            while (true)
            {

                char temp = pop(operatorStack);
                if (temp == '(')
                    break;
                postfix[postfixIndex++] = temp;
            }
            t++;
            continue;
        }

        while (shouldPop(peek(operatorStack), curr))
        {
            char temp = pop(operatorStack);
            postfix[postfixIndex++] = temp;
        }
        push(operatorStack, curr);
        t++;
    }
    while (!isStackEmpty(operatorStack))
    {
        postfix[postfixIndex++] = pop(operatorStack);
    }
    return postfix;
}