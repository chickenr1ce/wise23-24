#include <stdio.h>
#include <stdlib.h>

int main()
{   
    int input;

    printf("Enter the size of the array: ");
    scanf("%d",&input);

    printf("\nGenerating your array...\n");

    float* generatedarray;

    generatedarray = (float*)malloc(input * sizeof(float));
    
    int half = input/2;

    printf("Initializing your array...\n");

    if(input % 2 == 0)
    {
        for (int i = 0; i < half; i++)
        {
        generatedarray[i] = 123.0;
        }
        for (int j = input-1; j >= half; j--)
        {
        generatedarray[j] = 456.0;
        }   
    }
    else
    {
        for (int i = 0; i < half; i++)
        {
        generatedarray[i] = 123.0;
        }
        for (int j = input-1; j > half; j--)
        {
        generatedarray[j] = 456.0;
        }
        generatedarray[half] = 999.0;
    }

    

    printf("Here are the values of your array...\n");

    for (int size = 0; size < input; size++)
    {
        printf("A[%d]=%f\n",size,generatedarray[size]);
    }
    
    printf("Deallocating the array...\n");

    free(generatedarray);

}