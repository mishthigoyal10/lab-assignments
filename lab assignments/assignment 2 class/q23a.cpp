#include <stdio.h>

int findMissingLinear(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] != i + 1)
            return i + 1;
    }
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int missing = findMissingLinear(arr, n);
    printf("Missing number (Linear) = %d\n", missing);
    return 0;
}
