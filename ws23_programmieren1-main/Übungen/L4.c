#include <stdio.h>

int main()

{
    int i;
    int a;
     
    for ( i = 1; i < 11; i++)
    {
        for (a = 1; a < i; a++)
        {
            printf("%d ",a);
        }
        printf("\n");
    }
    
    for ( i = 1; i < 11; i++)
    {
        for (a = 1; a < i; a++)
        {
            printf("* ");
        }
        printf("\n");
    }
    
}