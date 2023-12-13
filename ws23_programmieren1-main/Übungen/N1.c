#include <stdio.h>

int main()
{
    char syllable1[10];
    char syllable2[10];
    char syllable3[10];



    printf("Enter syllable #1: ");
    scanf("%9s", syllable1);

    printf("Enter syllable #2: ");
    scanf("%9s", syllable2);

    printf("Enter syllable #3: ");
    scanf("%9s", syllable3);

    printf("%s%s\n",syllable1,syllable1);
    printf("%s%s\n",syllable1,syllable2);
    printf("%s%s\n",syllable1,syllable3);
    printf("%s%s\n",syllable2,syllable1);
    printf("%s%s\n",syllable2,syllable2);
    printf("%s%s\n",syllable2,syllable3);
    printf("%s%s\n",syllable3,syllable1);
    printf("%s%s\n",syllable3,syllable2);
    printf("%s%s\n",syllable3,syllable3);
}