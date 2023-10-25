#include <stdio.h>

int main()
{
int i;
int a;

printf("Output for the first for-loop:\n");

for ( i = 75; i >= 15; i--)
    {
    if (i % 5 == 0)  //use == for comparison, = for assignment
        {
        printf("%d ",i);
        }
    }   

printf("\nOutput for the second for-loop:\n");

for (a = 1; a <= 50; a++)
    {
    if (a % 3 != 0 && a % 7 != 0)   //%% = and; || = or
        {
        printf("%d ",a);            // continue also possible
        }
    
    }


return 0;
}                                 

/*
#include <stdio.h> // for the printf(), scanf() command
#include <conio.h> // for the _getch() command

int main()
{
   printf("\nOutput for first for-loop:\n");
   for (int i = 75; i >= 15; i = i - 5)
   {
      printf("%d ", i);
   }

   printf("\n\nOutput for second for-loop:\n");
   for (int i = 0; i<50; i++)
   {
      if ((i%3==0) || (i%7==0))
         continue;
      printf("%d ", i);
   }
   
   
   printf("\n\nGood bye!\n");
   printf("Press any key to exit this program.");
   _getch();
}
*/