#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main() {
    int q[MAX], n, i;
    printf("Enter number of elements (even): ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &q[i]);

    int first = 0, second = n / 2;

    printf("Interleaved Queue: ");
    while (second < n) {
        printf("%d %d ", q[first], q[second]);
        first++;
        second++;
    }
    printf("\n");

    return 0;
}
