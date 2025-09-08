#include <stdio.h>
#include <string.h>

#define MAX 256

int main() {
    char str[MAX];
    int freq[256] = {0};
    char queue[MAX];
    int front = 0, rear = -1;

    printf("Enter string: ");
    scanf("%s", str);

    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        freq[c]++;
        queue[++rear] = c;

        while (front <= rear && freq[queue[front]] > 1)
            front++;

        if (front > rear)
            printf("-1 ");
        else
            printf("%c ", queue[front]);
    }
    printf("\n");

    return 0;
}
