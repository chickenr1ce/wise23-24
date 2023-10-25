#include <stdio.h>
#include  <time.h>
#include <stdlib.h>

int main(){

int lower;
int upper;
time_t t;
int i;

srand(time(&t));
do
{
printf("Enter lower border: ");
scanf("%d",&lower);

printf("Enter upper border: ");
scanf("%d",&upper);

if (lower == upper)
{
    break;
}

printf("I will generate 10 random numbers between %d and %d:\n", lower, upper);

for ( i = 0; i < 10; i++)
{
     printf("%d ", rand() % (upper + 1 - lower) + lower); //rand() % (max_number + 1 - minimum_number) + minimum_number
}

printf("\n");

}

while(upper != lower);

}