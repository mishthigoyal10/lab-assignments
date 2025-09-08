#include <stdio.h>

int countStudents(int students[], int sandwiches[], int n) {
    int front = 0, end = n-1;
    int count = 0;

    int s_counts[2] = {0,0}, st_counts[2] = {0,0};

    for(int i = 0; i < n; i++) {
        st_counts[students[i]]++;
        s_counts[sandwiches[i]]++;
    }

    for(int i = 0; i < 2; i++)
        if(st_counts[i] < s_counts[i]) count += s_counts[i] - st_counts[i];

    return count;
}

int main() {
    int students[] = {1,1,0,0};
    int sandwiches[] = {0,1,0,1};
    int n = sizeof(students)/sizeof(students[0]);

    int unable = countStudents(students, sandwiches, n);
    printf("Students unable to eat: %d\n", unable);
    return 0;
}
