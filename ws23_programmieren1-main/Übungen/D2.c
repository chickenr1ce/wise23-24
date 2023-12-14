#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAP_2D_TO_1D_INDEX(dimX,x,y) (y*dimX+x)

int main()
{
    int notecount = 0;
    int input;

    const char **notebook = (const char **)malloc(notecount * sizeof(const char *));

    while (1)
    {
        printf("Simple notebook for storing notes.\n");
        printf("Menu:\n");
        printf("1) Enter a new note\n");
        printf("2) Show all notes taken so far\n");
        printf("3) Exit program\n");
        scanf("%d",&input);
        printf("\n\n\n");
        

        if (input==1)
        {
            notecount++;
            notebook = (const char **)realloc(notebook, notecount * sizeof(const char *));
            char buffer[100];

            printf("Note #%d: ",notecount);
            scanf("%s", buffer);

            //Duplicate string
            notebook[notecount-1] = strdup(buffer);
            printf("\n\n\n");
            
        }

        if (input==2)
        {   
            printf("Notes stored so far:\n");


            for (int i = 0; i < notecount; i++)
            {
                printf("Note #%d: %s\n",i+1,notebook[i]);
            }

            printf("Press ENTER to return to menu\n");
            getchar();
            getchar();
            printf("\n\n");

            
        }

        if (input==3)
        {
            free(notebook);
            exit(1);
        }

    }

}