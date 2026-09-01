#include <stdio.h>

int main() {
    int array[10] = {500, 1, 255, 7, -12, 40, 42, 999, 50, 227};

    printf("Enter m, n, or b: ");
    char input;
    scanf("%c", &input);

    //Loop through array to find max and min
    int max = array[0];
    int min = array[0];
    for(int i = 1; i < 10; i++) {
        if(array[i] > max) {
            max = array[i];
        } else if(array[i] < min) {
            min = array[i];
        }
    }

    //Print requested value based on user input
    switch(input) {
        case 'm':
            printf("%d", max);
            break; 
        case 'n':
            printf("%d", min);
            break;
        case 'b':
            printf("%d %d", max, min);
            break; 
    }
}