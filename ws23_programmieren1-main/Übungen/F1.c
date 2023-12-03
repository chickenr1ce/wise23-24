#include <stdio.h>
#include <stdlib.h>

int n1;
int n2;
int n3;
int *sum;
float *avg;                                                                     

void statistics(int x, int y, int z, int *sum, float *avg)
{
    *sum = x+y+z;
    *avg = (x+y+z)/3.0;
}


int main()
{

    for (n1 = 1; n1 < 6; n1++)
    {
        for (n2 = 1; n2 < 6; n2++)
        {
            for (n3 = 1; n3 < 6; n3++)
            {
                int sum;
                float avg;
                statistics(n1,n2,n3,&sum,&avg);
                printf("n1=%d, n2=%d, n3=%d ----> sum=%d, avg=%f\n",n1,n2,n3, sum, avg);
            }
        }
    }
    
}