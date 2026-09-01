#include <stdio.h>

int main() {
    printf("Enter three integers: ");
    int input[3];
    scanf("%d %d %d", &input[0], &input[1], &input[2]);

    //Bubble sort
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(input[i] < input[j]) {
                int temp = input[i];
                input[i] = input[j];
                input[j] = temp;
            }
        }
    }

    //Print the middle number 
    printf("%d", input[1]);
    
    return 0;
}