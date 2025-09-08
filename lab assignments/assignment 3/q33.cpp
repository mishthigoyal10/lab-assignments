#include <stdio.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) { stack[++top] = c; }
char pop() { return stack[top--]; }
int isEmpty() { return top == -1; }

int isMatchingPair(char left, char right) {
    return (left == '(' && right == ')') ||
           (left == '[' && right == ']') ||
           (left == '{' && right == '}');
}

int main() {
    char exp[MAX];
    printf("Enter expression: ");
    gets(exp);

    int i;
    for (i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
            push(exp[i]);
        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {
            if (isEmpty() || !isMatchingPair(pop(), exp[i])) {
                printf("Not Balanced\n");
                return 0;
            }
        }
    }

    if (isEmpty())
        printf("Balanced\n");
    else
        printf("Not Balanced\n");

    return 0;
}
