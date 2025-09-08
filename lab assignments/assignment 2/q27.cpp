#include <stdio.h>

int countInversions(int arr[], int n) {
    int i, j, count = 0;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] > arr[j])
                count++;
        }
    }
    return count;
}

int main() {
    int arr[] = {2, 4, 1, 3, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int inv = countInversions(arr, n);
    printf("Number of inversions = %d\n", inv);
    return 0;
}
