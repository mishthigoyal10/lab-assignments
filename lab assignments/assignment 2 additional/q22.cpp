#include <stdio.h>
#include <string.h>

int canSplit(char str[]) {
    int n = strlen(str);
    for(int len = 1; len <= n/2; len++) {
        for(int i = 0; i + len <= n; i++) {
            char sub[100];
            strncpy(sub, &str[i], len);
            sub[len] = '\0';
            if(strstr(str, sub) != NULL && strstr(strstr(str, sub)+len, sub) != NULL)
                return 1;
        }
    }
    return 0;
}

int main() {
    char str[100];
    printf("Enter string: ");
    scanf("%s", str);

    if(canSplit(str))
        printf("Yes, it can be split\n");
    else
        printf("No, it cannot be split\n");

    return 0;
}
