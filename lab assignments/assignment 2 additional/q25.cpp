#include <stdio.h>

void duplicateTwos(int arr[], int n) {
    int i = 0;
    int size = n;

    while(i < size) {
        if(arr[i] == 2) {
            for(int j = n-1; j > i; j--)
                arr[j] = arr[j-1];
            if(i+1 < n)
                arr[i+1] = 2;
            i += 2;
        } else {
            i++;
        }
    }
}

int main() {
    int arr[] = {1,2,3,2,4};
    int n = sizeof(arr)/sizeof(arr[0]);

    duplicateTwos(arr, n);

    printf("Array after duplicating 2s: ");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
