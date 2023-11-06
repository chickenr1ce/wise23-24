#include <stdio.h>
#define BORDER '#'
#define SPACE ' '

int height;
int width;


int main(){

    printf("Height of rectangle? ");
    scanf("%d", &height);

    printf("Width of rectangle? ");
    scanf("%d", &width);

    char RECTANGLE[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == 0 || j == 0 || i == (height-1) || j == (width-1))
            {
                RECTANGLE[i][j] = BORDER;
            }
            else
            
            RECTANGLE[i][j] = SPACE;
            
        }
        
    }
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            printf("%c",RECTANGLE[i][j]);

        } 
        printf("\n"); 
    }  
}     
