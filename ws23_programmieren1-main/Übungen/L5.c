#include <stdio.h>

int main(){

int i; 

printf("1. With a for-loop:\n");

for ( i = 17; i < 30; i = i +3)
{
    printf("%d ",i);
}

printf("\n");

printf("2. With a while-loop:\n");

i = 17;
while (i < 30)
{
    printf("%d ",i);
    i = i + 3;
}

printf("\n");

printf("3. With a do-while-loop:\n");

i = 17;

do
{
    printf("%d ",i);
    i = i + 3;
} while (i < 30);

return 0;

}
