#include <stdio.h>

int main() {
    // Get operator from user
    printf("Enter operation: ");
    char operation;
    scanf("%s", &operation);

    // Get first operand from user
    printf("Enter first operand: ");
    int operand1;
    scanf("%d", &operand1);

    // Get second operand from user if needed
    int operand2;
    if(!(operation == 's' || operation == 'c')) {
        printf("Enter second operand: ");

        scanf("%d", &operand2);
    }

    // Process the operation
    int result;
    switch(operation) {
        case 's':
            result = operand1 * operand1;
            break;
        case 'c':
            result = operand1 * operand1 * operand1;
            break;
        case '+':
            result = operand1 + operand2; 
            break;
        case '-':
            result = operand1 - operand2;
            break;
        case '*':
            result = operand1 * operand2;
            break; 
        case '/':
            if(operand2 == 0) {
                printf("Error: Division by zero");
                return 1;
            }
            result = operand1 / operand2;
            break;
    }
    printf("%d", result);
    return 0;
}
