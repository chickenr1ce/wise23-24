#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{   
    srand(time(NULL));

    char syllable1[10] = "bruh";
    char syllable2[10] = "nah";
    char syllable3[10] = "hel";
    char syllable4[10] = "ju";
    char syllable5[10] = "ko";
    char syllable6[10] = "do";

    /*printf("Enter syllable #1: ");
    scanf("%9s", syllable1);

    printf("Enter syllable #2: ");
    scanf("%9s", syllable2);

    printf("Enter syllable #3: ");
    scanf("%9s", syllable3);

    printf("Enter syllable #4: ");
    scanf("%9s", syllable4);

    printf("Enter syllable #5: ");
    scanf("%9s", syllable5);

    printf("Enter syllable #6: ");
    scanf("%9s", syllable6);

    printf("Syllables stored: %s %s %s %s %s %s\n", syllable1,syllable2,syllable3,syllable4,syllable5,syllable6);
    */

    char generatedword[99];

    for (int i = 0; i < 10; i++)
    {   
        memset(generatedword, '\0', sizeof(generatedword));

        int numberofsyllables = 2 + rand() % 4;

        printf("number of syllables: %d\n",numberofsyllables);

        for (int j = 0; j < numberofsyllables; j++)
        {
            int syllablechosen = 1 + rand() % 6;
            switch (syllablechosen)
            {
            case 1:
                strcat(generatedword, syllable1);
                break;
            case 2:
                strcat(generatedword, syllable2);
                break;
            case 3:
                strcat(generatedword, syllable3);
                break;
            case 4:
                strcat(generatedword, syllable4);
                break;
            case 5:
                strcat(generatedword, syllable5);
                break;
            case 6:
                strcat(generatedword, syllable6);
                break;
            default:
                break;
            }
        }
        
        int length = strlen(generatedword);
        printf("Generated word #%d has %d letters: %s\n",i+1,length,generatedword);

    }

}