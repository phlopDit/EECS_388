#include <stdio.h>

int main() {
    printf("Enter string: ");
    char input[100];
    scanf("%s", input);

    //Loop through string until is get's to '\0' to count number of characters
    int count = 0;
    for(int i = 0; *(input + i) != '\0'; i++) {
        count++;
    }

    printf("%d", count);
}