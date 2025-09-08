#include <stdio.h>
#define MAX 100

void nextGreater(int arr[], int n) {
    int stack[MAX], top = -1, nge[MAX];

    for(int i = n-1; i >=0; i--) {
        while(top != -1 && stack[top] <= arr[i])
            top--;
        if(top == -1) nge[i] = -1;
        else nge[i] = stack[top];
        stack[++top] = arr[i];
    }

    for(int i = 0; i < n; i++)
        printf("%d ", nge[i]);
    printf("\n");
}

int main() {
    int arr[] = {4, 5, 2, 25};
    int n = sizeof(arr)/sizeof(arr[0]);
    nextGreater(arr, n);
    return 0;
}
