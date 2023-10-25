#include <stdio.h>

int main(){

int a;
int b;
int c;
int i;

a = 1;
b = 1;

do{

    do
    {
       c = a * b;
       printf("%d x %d = %d  ", a, b, c);
      b++;
    } while (b<=10);
    printf("\n");
    b = 1;
    a++;

} while (a<=10);

printf("Goodbye!");
return 0;
}