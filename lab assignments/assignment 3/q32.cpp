#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

int main() {
    char str[MAX];
    printf("Enter a string: ");
    gets(str);

    int i, n = strlen(str);

    for (i = 0; i < n; i++)
        push(str[i]);

    printf("Reversed string: ");
    for (i = 0; i < n; i++)
        printf("%c", pop());
    printf("\n");

    return 0;
}
