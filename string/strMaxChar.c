#include <stdio.h>
#include <string.h>

char countMaxChar(char *str) {
    int counter[128] = {0};
    int len = strlen(str);

    for(int i = 0; i < len; i++) {
        counter[str[i]]++;
    } 

    char maxChar = str[0];
    int maxCount = counter[maxChar];
    for(int i = 1; i < len; i++) {
        if(counter[str[i]] > maxCount) {
            maxChar = str[i];
            maxCount = counter[maxChar];
        }
    }
    return maxChar;
}

int main() {
    char str[] = "hello world";
    char maxChar = countMaxChar(str);
    printf("The max char is: %c\n", maxChar);
}