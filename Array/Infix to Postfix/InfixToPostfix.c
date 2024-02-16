#include <stdio.h>
#include <stdlib.h>

int main() {
    char *str = NULL; // Pointer to char, initialized to NULL
    size_t size = 0; // Initial size is 0, getline will allocate memory as needed
    printf("Infix to Postfix convertor, use alphabets, + - * / ^ and only this brackets ()");
    printf("Enter infix experssion : ");
    int charRead = getline(&str, &size, stdin);


    return 0;
}
