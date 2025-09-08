#include <stdio.h>
#include <limits.h>

#define MAX 100

int main() {
    int A[] = {3, 1, 2};
    int n = sizeof(A)/sizeof(A[0]);
    int S[MAX], top = -1;
    int B[MAX], bIndex = 0;

    int expected = 1; // smallest expected element

    for(int i = 0; i < n; i++) {
        // push into stack
        while(top != -1 && S[top] == expected) {
            B[bIndex++] = S[top--];
            expected++;
        }

        if(A[i] == expected) {
            B[bIndex++] = A[i];
            expected++;
        } else {
            S[++top] = A[i];
        }
    }

    while(top != -1 && S[top] == expected) {
        B[bIndex++] = S[top--];
        expected++;
    }

    int sorted = 1;
    for(int i = 0; i < n; i++) {
        if(B[i] != i+1) {
            sorted = 0;
            break;
        }
    }

    if(sorted) printf("Yes, possible to sort using stack\n");
    else printf("No, not possible\n");

    return 0;
}
