#include <stdio.h>

int main() {
    //Get size of array and initialize it.
    printf("How big is the array?");
    int SIZE = 0;
    scanf("%d", &SIZE);
    int array[SIZE];

    //Get input for elements in the array.
    printf("Enter %d integers: ", SIZE);
    for(int i = 0; i < SIZE; i++) {
        scanf("%d", &array[i]);
    }

    //Find max strictly increasing run of integers in array
    int runSizeMax = 1;
    int tempRunSize = runSizeMax;
    for(int i = 0; i < SIZE - 1; i++) {
        if(array[i] < array[i + 1]) {
            tempRunSize++;
        } else {
            //Check current run size with max
            if(tempRunSize > runSizeMax) {
                runSizeMax = tempRunSize;
            }
            tempRunSize = 1;
        }
    }

    //Check last run size with max
    if(tempRunSize > runSizeMax) {
        runSizeMax = tempRunSize;
    }

    printf("%d", runSizeMax);
}
