#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define BREITE 50
#define HOEHE 20

#define RAND '#'
#define LEER ' '

char spielfeld[HOEHE][BREITE];

void init_board()
{
    for (int i=0; i<HOEHE; i++)
    {
        for (int j = 0; j<BREITE; j++)
        {
            if((i==0) || (i==HOEHE-1) || (j==0) || (j==BREITE-1))
            {
                spielfeld[i][j] = RAND;
            }
            else
            {
                spielfeld[i][j] = LEER;
            }
        }
    }  
}

void show_game_board()
{
     for (int i=0; i<HOEHE; i++)
    {
        for (int j = 0; j<BREITE; j++)
        {
            printf("%c",spielfeld[i][j]);
        }
        printf("\n");
    }   
}

void add_single_block()
{
    int blocklength;
    int x = rand() % BREITE-1;
    int y = rand() % HOEHE-1;

    int zufallszahl = rand() % 4;
    switch (zufallszahl)
    {
    case 0:
        blocklength = 3;
        break;
    case 1:
        blocklength = 4;
        break;
    case 2:
        blocklength = 5;
        break;
    case 3:
        blocklength = 6;
        break;
    default:
        break;
    }

    for (int i = y; i < y+blocklength; i++)
    {
        for (int j = x; j < x+blocklength; j++)
        {
            spielfeld[i][j] = RAND;
        }
    }
}

int main()
{
    srand(time(NULL));

    init_board();
    for (int i = 0; i < 20; i++)
    {
        add_single_block();
    }
    
    show_game_board();

    return 0;
}