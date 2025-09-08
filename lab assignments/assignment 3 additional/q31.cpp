#include <stdio.h>
#define MAX 100

void nearestSmaller(int arr[], int n) {
    int stack[MAX], top = -1;

    for(int i = 0; i < n; i++) {
        while(top != -1 && stack[top] >= arr[i])
            top--; // pop until smaller
        if(top == -1)
            printf("-1 ");
        else
            printf("%d ", stack[top]);
        stack[++top] = arr[i]; // push current
    }
    printf("\n");
}

int main() {
    int arr[] = {4, 5, 2, 10, 8};
    int n = sizeof(arr)/sizeof(arr[0]);

    nearestSmaller(arr, n);

    return 0;
}
