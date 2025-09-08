#include <stdio.h>
#include <stdlib.h>

int countPairs(int arr[], int n, int k) {
    int count = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(abs(arr[i] - arr[j]) == k)
                count++;
        }
    }
    return count;
}

int main() {
    int arr[] = {1, 5, 3, 4, 2};
    int k = 2;
    int n = sizeof(arr)/sizeof(arr[0]);

    int result = countPairs(arr, n, k);
    printf("Number of pairs with difference %d = %d\n", k, result);
    return 0;
}
