#include <stdio.h>

int main() {
    printf("Enter integer: ");
    int input;
    scanf("%d", &input);

    //Convert input integer to binary
    int answer[8] = {0};
    for (int i = 0; input > 0 && i < 8; i++) {
        answer[i] = input % 2;
        input >>= 1;
    }

    //Print array in reverse order for binary and counts set bits
    int setBits = 0;
    for (int j = 7; j >= 0; j--) {
        printf("%d", answer[j]);
        if(answer[j] & 1) {
            setBits++;
        }
    }

    printf("\nSet bits: %d", setBits);


    return 0;
}