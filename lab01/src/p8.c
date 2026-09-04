#include <stdio.h>

int main() {
    printf("Enter integer: ");
    int input = 0;
    scanf("%d", &input);

    //Convert input integer to binary
    int binary[32] = {0};
    for (int i = 0; input > 0 && i < 32; i++) {
        binary[i] = input % 2;
        input >>= 1;
    }

    printf("Enter bit: ");
    int bitPosition = 0;
    scanf("%d", &bitPosition);

    //Check if bit in position given by user is set
    if( *(binary + bitPosition) == 1) {
        printf("True");
    } else {
        printf("False");
    }
}