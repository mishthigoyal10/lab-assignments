#include <stdio.h>
#define MAX 100

void dailyTemperatures(int temp[], int n) {
    int stack[MAX], top = -1;
    int answer[MAX] = {0};

    for(int i = n-1; i >=0; i--) {
        while(top != -1 && temp[i] >= temp[stack[top]])
            top--;
        if(top != -1)
            answer[i] = stack[top] - i;
        stack[++top] = i;
    }

    for(int i = 0; i < n; i++)
        printf("%d ", answer[i]);
    printf("\n");
}

int main() {
    int temp[] = {73, 74, 75, 71, 69, 72, 76, 73};
    int n = sizeof(temp)/sizeof(temp[0]);
    dailyTemperatures(temp, n);
    return 0;
}
