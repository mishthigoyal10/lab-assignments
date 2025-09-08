#include <stdio.h>

int main() {
    int arr[] = {1, 2, 2, 3, 4, 1, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int i, j, distinct = 0, found;

    for (i = 0; i < n; i++) {
        found = 0;
        for (j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                found = 1;
                break;
            }
        }
        if (!found)
            distinct++;
    }

    printf("Total distinct elements = %d\n", distinct);
    return 0;
}
