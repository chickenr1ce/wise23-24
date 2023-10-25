#include <stdio.h>

int main(){

    int a;
    int i;
    int b;

    a = 0;
    i = 1;

    printf("Counting from 1 to 10:\n");

    while (i<=15)

    {
     
      a++;
      printf("%d\n",a);
      i++; 
    }
    
    i = 1;
    printf("Counting from -5 to -15:\n");
    b=-4;

    while (i<12)
    {
      b--;
      printf("%d\n",b);
      i++;
    }
    
    return 0;
}