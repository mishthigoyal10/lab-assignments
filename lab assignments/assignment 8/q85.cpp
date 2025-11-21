#include <stdio.h>

void heapify(int arr[], int n, int i, int ascending) {
    int extreme = i; 
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (ascending == 1) {
        if (left < n && arr[left] > arr[extreme])
            extreme = left;
        if (right < n && arr[right] > arr[extreme])
            extreme = right;
    } 
    else {
        if (left < n && arr[left] < arr[extreme])
            extreme = left;
        if (right < n && arr[right] < arr[extreme])
            extreme = right;
    }

    if (extreme != i) {
        int temp = arr[i];
        arr[i] = arr[extreme];
        arr[extreme] = temp;
        heapify(arr, n, extreme, ascending);
    }
}

void heapSort(int arr[], int n, int ascending) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, ascending);

    for (int i = n - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0, ascending);
    }
}

int main() {
    int n, choice;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("\n1. Increasing Order");
    printf("\n2. Decreasing Order");
    printf("\nChoose option: ");
    scanf("%d", &choice);

    int ascending = (choice == 1) ? 1 : 0;

    heapSort(arr, n, ascending);

    printf("\nSorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
