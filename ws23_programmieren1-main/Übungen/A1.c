#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ioctl.h>

#define STARTINGWIDTH 5
#define STARTINGHEIGHT 3
#define clear() printf("\033[H\033[J")
#define gotoxy(x,y) printf("\033[%d;%dH", (y), (x))

int getTerminalWidth() {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    return w.ws_col;
}

int getTerminalHeight() {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    return w.ws_row;
}


int main(){

int vertical;
int horizontal;
int width = STARTINGWIDTH;
int height = STARTINGHEIGHT;    
int startVertical = (getTerminalHeight() - height) / 2;
int startHorizontal = (getTerminalWidth() - width) / 2;
do
{
for (int height; height < 21; height++)
{
    clear();
    
    for (int vertical = 0; vertical <= height; vertical++)
    {
        gotoxy(startHorizontal,startVertical+vertical);
        if ((vertical == 0) || vertical == height)
        {
            for (int horizontal = 0; horizontal < width; horizontal++)
                printf("#");
        }
        else
        {
            for (horizontal = 0; horizontal < width; horizontal++)
            {
                if ((horizontal==0)||(horizontal == width-1))
                    printf("#");
                else
                    printf(" ");
            }   
        }
        
        printf("\n");
    }
    
    usleep(50000);
    height++;
    width++;

    printf("%d",startVertical);
}
} while(1);

}