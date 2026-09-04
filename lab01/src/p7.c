#include <stdio.h>

int main() {
    printf("Enter integer: ");
    int temp = 0;
    scanf("%d", &temp);

    int *temp_ptr = &temp;

    //Print the value of temp
    printf("%d,\n", temp);

    //Print the value of 'temp' using the dereference of 'temp_ptr'
    printf("%d,\n", *temp_ptr);

    //Print the value of 'temp' using the reference of 'temp'
    printf("%p,\n", &temp);


    //Print the address of 'temp' using 'temp_ptr'
    printf("%p", temp_ptr);


}