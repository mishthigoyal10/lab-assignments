#include <stdio.h>

#define MAX 100

typedef struct {
    int row, col, val;
} Triplet;

void transpose(Triplet a[], Triplet b[]) {
    int i, j, k = 1;
    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].val = a[0].val;

    for (i = 0; i < a[0].col; i++) {
        for (j = 1; j <= a[0].val; j++) {
            if (a[j].col == i) {
                b[k].row = a[j].col;
                b[k].col = a[j].row;
                b[k].val = a[j].val;
                k++;
            }
        }
    }
}

int main() {
    Triplet a[MAX], b[MAX];
    int i;

    a[0].row = 3; a[0].col = 3; a[0].val = 3;
    a[1].row = 0; a[1].col = 0; a[1].val = 5;
    a[2].row = 1; a[2].col = 2; a[2].val = 8;
    a[3].row = 2; a[3].col = 1; a[3].val = 3;

    transpose(a, b);

    printf("Transpose triplet:\n");
    for (i = 0; i <= b[0].val; i++)
        printf("%d %d %d\n", b[i].row, b[i].col, b[i].val);

    return 0;
}
