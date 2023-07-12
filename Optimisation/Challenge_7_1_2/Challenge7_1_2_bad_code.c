#include <stdio.h>

int factorial(int n) {
    // Bad Choice 1: Not handling negative numbers
    if (n < 0) {
        printf("Factorial is not defined for negative numbers.\n");
        return -1;
    }

    // Bad Choice 2: Unoptimized handling of factorial 0 and 1
    if (n == 0 || n == 1) {
        return 1;
    }

    int result = 1;
    int temp = 0;

    // Bad Choice 3: Nested loops with unnecessary if statement
    for (int i = 2; i <= n; i++) {
        // Bad Choice 4: Unoptimized multiplication
        result = result * i;
        // Bad Choice 5: Dead code (unnecessary printf)
        printf("Intermediate result: %d\n", result);
        // Bad Choice 6: Unnecessary variable
        temp = temp + i;
    }

    // Bad Choice 7: Redundant variable
    int final_result = calculate_result(result, temp);

    return final_result;
}

// Bad Choice 8: Unnecessary function call
int calculate_result(int a, int b) {
    // Bad Choice 9: Unoptimized addition
    return a + b;
}

int main() {
    int n = 10;
    int result = factorial(n);
    printf("The factorial of %d is %d.\n", n, result);
    return 0;
}

