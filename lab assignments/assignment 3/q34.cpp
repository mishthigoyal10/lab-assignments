#include <stdio.h>
#include <ctype.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) { stack[++top] = c; }
char pop() { return stack[top--]; }
char peek() { return stack[top]; }
int isEmpty() { return top == -1; }

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

void infixToPostfix(char* exp) {
    char result[MAX];
    int i, k = 0;

    for (i = 0; exp[i] != '\0'; i++) {
        char c = exp[i];
        if (isalnum(c))
            result[k++] = c;
        else if (c == '(')
            push(c);
        else if (c == ')') {
            while (!isEmpty() && peek() != '(')
                result[k++] = pop();
            pop();
        } else {
            while (!isEmpty() && precedence(peek()) >= precedence(c))
                result[k++] = pop();
            push(c);
        }
    }
    while (!isEmpty())
        result[k++] = pop();
    result[k] = '\0';

    printf("Postfix: %s\n", result);
}

int main() {
    char exp[MAX];
    printf("Enter infix expression: ");
    gets(exp);

    infixToPostfix(exp);
    return 0;
}
