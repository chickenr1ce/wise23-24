#include <stdio.h>

// Function to calculate the sum of natural numbers up to n
int sum(int n) {
    // Base case: sum of 0 is 0
    if (n == 0) {
        return 0;
    } else {
        // Recursive case: sum(n) = n + sum of (n-1)
        return n + sum(n - 1);
    }
}

int main() {
    int num;

    // Taking input from the user
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    // Checking if the input is positive
    if (num <= 0) {
        printf("Please enter a positive integer.\n");
    } else {
        // Calling the sum function and printing the result
        printf("Sum of natural numbers up to %d = %d\n", num, sum(num));
    }

    return 0;
}
