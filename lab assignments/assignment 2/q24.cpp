#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str1[100], str2[100], str3[200];
    int i, j;


    strcpy(str1, "Hello");
    strcpy(str2, "World");
    strcpy(str3, str1);
    strcat(str3, str2);
    printf("Concatenated string: %s\n", str3);

    strcpy(str1, "College");
    int len = strlen(str1);
    printf("Reversed: ");
    for (i = len - 1; i >= 0; i--)
        printf("%c", str1[i]);
    printf("\n");

    strcpy(str1, "Beautiful");
    j = 0;
    for (i = 0; str1[i] != '\0'; i++) {
        if (strchr("AEIOUaeiou", str1[i]) == NULL)
            str1[j++] = str1[i];
    }
    str1[j] = '\0';
    printf("Without vowels: %s\n", str1);


    char arr[5][20] = {"banana", "apple", "pear", "grape", "orange"};
    char temp[20];
    for (i = 0; i < 5; i++) {
        for (j = i + 1; j < 5; j++) {
            if (strcmp(arr[i], arr[j]) > 0) {
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }
    printf("Sorted strings: ");
    for (i = 0; i < 5; i++)
        printf("%s ", arr[i]);
    printf("\n");

    char ch = 'A';
    printf("Lowercase of %c is %c\n", ch, tolower(ch));

    return 0;
}
