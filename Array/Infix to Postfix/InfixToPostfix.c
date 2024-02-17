#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../../GlobalLibrary/CharStack.h"

bool shouldPop(char, char);
int findPrecedence(char);
int main()
{
    // To take user input as string
    char *str = NULL; // Pointer to char, initialized to NULL
    size_t size = 0;  // Initial size is 0, getline will allocate memory as needed
    printf("Infix to Postfix convertor, use alphabets, + - * / ^ and only this brackets ()\n");
    printf("Enter infix experssion : ");
    getline(&str, &size, stdin);

    Stack *operatorStack = createStack(strlen(str));
    char *t = str;
    char postfix[strlen(str)];
    int postfixIndex = 0;

    while (*t || !isStackEmpty(operatorStack))
    {   
        // printStack(operatorStack);
        // for(int i = 0;i<strlen(str);i++){
        //     printf("%c",postfix[i]);
        // }
        // printf("\n");
        
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

    return 0;
}

bool shouldPop(char top, char curr)
{   if(top == '?') return false;
    int precedenceTop = findPrecedence(top);
    int precedenceCurr = findPrecedence(curr);
    return precedenceTop < precedenceCurr ? false : precedenceTop > precedenceCurr ? true : curr != '^';
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