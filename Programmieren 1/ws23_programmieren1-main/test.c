#include <stdio.h>


int main(){
    int number;
    float b;


    printf("Please insert a number: ");

    if (scanf("%f", &b) == 1){

    printf("You entered: %.3f\n", b);
    } 

    else {
        printf("Invalid input. Please enter a valid integer.\n");
        }

    return 0;
}