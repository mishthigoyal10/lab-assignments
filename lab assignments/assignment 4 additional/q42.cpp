#include <stdio.h>
#define MAX 100

void sortQueue(int q[], int n) {
    for(int i = 0; i < n; i++) {
        int min_idx = 0;
        for(int j = 0; j < n-i; j++)
            if(q[j] < q[min_idx]) min_idx = j;
        int min_val = q[min_idx];
        for(int k = min_idx; k < n-1; k++) q[k] = q[k+1];
        q[n-i-1] = min_val;  /
    }
}

int main() {
    int q[] = {11, 5, 4, 21};
    int n = sizeof(q)/sizeof(q[0]);

    sortQueue(q, n);

    printf("Sorted queue: ");
    for(int i = 0; i < n; i++) printf("%d ", q[i]);
    printf("\n");
    return 0;
}
