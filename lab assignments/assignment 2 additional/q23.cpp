#include <stdio.h>
#include <string.h>

int isAnagram(char str1[], char str2[]) {
    int freq[256] = {0};
    int n1 = strlen(str1), n2 = strlen(str2);
    if(n1 != n2) return 0;

    for(int i = 0; i < n1; i++) {
        freq[str1[i]]++;
        freq[str2[i]]--;
    }
    for(int i = 0; i < 256; i++) {
        if(freq[i] != 0) return 0;
    }
    return 1;
}

int main() {
    char str1[100], str2[100];
    printf("Enter two strings: ");
    scanf("%s %s", str1, str2);

    if(isAnagram(str1, str2))
        printf("Strings are anagrams\n");
    else
        printf("Strings are not anagrams\n");

    return 0;
}
