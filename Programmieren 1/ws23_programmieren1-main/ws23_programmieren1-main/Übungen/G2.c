#include <stdio.h> 
    int main() { 
        float c, r; 
        
        printf("C:");
        scanf("%f", &c);
        
        printf("r:"); 
        scanf("%f", &r);

        int y = 0;
        do { c = c + c*(r / 100.0f);
        y = y + 1;
        printf("\ny=%d: c=%.1f", y, c); } 

        while (y<10); 
            printf("\nGood bye!\n");
        }
      