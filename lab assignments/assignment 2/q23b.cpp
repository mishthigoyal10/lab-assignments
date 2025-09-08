#include <stdio.h>

int findMissingBinary(int arr[], int n) {
    int low = 0, high = n - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] != mid + 1) {
            if (mid == 0 || arr[mid - 1] == mid)
                return mid + 1;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int missing = findMissingBinary(arr, n);
    printf("Missing number (Binary) = %d\n", missing);
    return 0;
}
