#include <stdio.h>
#define MAX 100

int canSortQueue(int q[], int n) {
    int stack[MAX], top = -1;
    int expected = 1;

    for(int i = 0; i < n; i++) {
        while(top != -1 && stack[top] == expected) {
            top--;
            expected++;
        }

        if(q[i] == expected) expected++;
        else stack[++top] = q[i];
    }

    while(top != -1 && stack[top] == expected) {
        top--;
        expected++;
    }

    return expected - 1 == n;
}

int main() {
    int q[] = {5, 1, 2, 3, 4};
    int n = sizeof(q)/sizeof(q[0]);

    if(canSortQueue(q, n))
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}
