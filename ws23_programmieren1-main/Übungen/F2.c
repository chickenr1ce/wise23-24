#include <stdio.h>

const int startn1 = 0;
const int startn2 = 1;
int currentn1 = startn1;
int currentn2 = startn2;
int counter;

int fibonacci_iterative(int n)
{
    int number1 = startn1;
    int number2 = startn2;

    for (int i = 0; i < n; i++)
    {
        int temp;
        temp = number2;
        number2 = number1 + temp;
        number1 = temp;
    }

    printf("F(%d) is according to fibonacci_iterative() %d\n",n,number1);

}

int fibonacci_recursive(int n)
{   
    if (n<=1)
    return n;

    return fibonacci_recursive(n-1) + fibonacci_recursive(n-2);
    
}

int main()
{   
    int n = 6;
    fibonacci_iterative(6);
    printf("F(%d) is according to fibonacci_recursive() %d\n", n, fibonacci_recursive(n));
    
}