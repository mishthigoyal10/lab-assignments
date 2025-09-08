#include <stdio.h>
#define MAX 10

int main() {
    int A[MAX][MAX], B[MAX][MAX], r, c, i, j;

    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);

    printf("Enter elements of matrix:\n");
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            scanf("%d", &A[i][j]);

    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            B[j][i] = A[i][j];

    printf("Transpose of matrix:\n");
    for (i = 0; i < c; i++) {
        for (j = 0; j < r; j++)
            printf("%d ", B[i][j]);
        printf("\n");
    }
    return 0;
}
