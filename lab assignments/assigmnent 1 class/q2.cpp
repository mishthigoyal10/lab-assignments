#include <stdio.h>

// Function to remove duplicates
void removeDuplicates(int arr[], int *n) {
    int i, j, k;
    for (i = 0; i < *n; i++) {
        for (j = i + 1; j < *n;) {
            if (arr[i] == arr[j]) {
                for (k = j; k < *n - 1; k++)
                    arr[k] = arr[k + 1];
                (*n)--;  // reduce size
            } else {
                j++;
            }
        }
    }
}

int main() {
    int arr[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    removeDuplicates(arr, &n);

    printf("Array after removing duplicates: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
