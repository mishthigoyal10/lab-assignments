#include <stdio.h>
#define MAX 10

int main() {
    int arr[MAX][MAX], r, c, i, j;

    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);

    printf("Enter elements of matrix:\n");
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            scanf("%d", &arr[i][j]);

  
    for (i = 0; i < r; i++) {
        int sum = 0;
        for (j = 0; j < c; j++)
            sum += arr[i][j];
        printf("Sum of row %d = %d\n", i, sum);
    }


    for (j = 0; j < c; j++) {
        int sum = 0;
        for (i = 0; i < r; i++)
            sum += arr[i][j];
        printf("Sum of column %d = %d\n", j, sum);
    }

    return 0;
}
