#include <stdio.h>

int main(){

   int a;
   int b;
   int c;
   int sum;
   int product;
   int average;

   printf("Enter 3 numbers:\n");

   printf("1. Number: \n");
   scanf("%d", &a); 

   printf("2. Number: \n");
   scanf("%d", &b);
   
   printf("3. Number: \n");
   scanf("%d", &c);

   printf("%d, %d, %d\n", a, b, c);
   
   sum = a + b +c;
   product = a*b*c;
   average = (a + b + c)/3;

   printf("sum: %d\n"
          "product: %d\n"
          "average: %d\n", sum, product, average);

   return 0;
}