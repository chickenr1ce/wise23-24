#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "params.h"
#include "snake_hilfsfunktionen.h"

// main.c -> Präprozessor -> Compiler -> Linker -> Programm

char spielfeld[HOEHE][BREITE];
int snakex = BREITE/2;
int snakey = HOEHE/2;

void waende_einfuegen()
{
    for ( int i = 0; i < HOEHE; i++)
    {
        
        for (int j = 0; j < BREITE; j++)
        {
            if (i == 0 || i == (HOEHE-1) || j == 0 || j == (BREITE-1))
            {
            spielfeld[i][j] = RAND;
            }  
            else
            spielfeld[i][j] = LEER;
        }
            
    }
}

void spielfeld_ausgeben()
{

    for (int i = 0; i < HOEHE; i++)
        {
            for (int j = 0; j < BREITE; j++)
            {
                printf("%c", spielfeld[i][j]);
            }
            printf("\n");
        }   
}

void futter_einfuegen(){

    int zufallszahl1 = rand();
    for ( int i = 0; i < ANZAHL_FUTTER; i++)
        {
        int zufallshoehe = rand() % (HOEHE-2) + 1;
        int zufallsbreite = rand() % (BREITE-2) + 1;
        spielfeld[zufallshoehe][zufallsbreite] = FUTTER;
        }
}

void hindernisswaende_einfuegen(int anz_waende, int lx, int ly)
{
    int zufallszahl2 = rand();
    for (int i=0; i < anz_waende; i++)
    {
        int zufallshoehe = rand() % (HOEHE-2) + 1;
        int zufallsbreite = rand() % (BREITE-2) + 1;
        
        for (int wandstueck = 0; wandstueck < WAND_LAENGE ; wandstueck++)
        {
            int zx = zufallsbreite + lx*wandstueck;
            int zy = zufallshoehe + ly*wandstueck;

            if ((zx>=0) && (zx<BREITE-1) && (zy>=0) && (zy<=HOEHE-1))
            spielfeld[zy][zx] = HINDERNIS;
        }
        
        /*
        spielfeld[zufallshoehe][zufallsbreite] = HINDERNIS;
        spielfeld[zufallshoehe-1][zufallsbreite] = HINDERNIS;
        spielfeld[zufallshoehe-2][zufallsbreite] = HINDERNIS;
        spielfeld[zufallshoehe-3][zufallsbreite] = HINDERNIS;  
        */
    }
}


void spielfeld_initialisieren(){

    waende_einfuegen();
    hindernisswaende_einfuegen(ANZAHL_VERTIKALE_WAENDE,0,1);
    hindernisswaende_einfuegen(ANZAHL_HORIZONTALE_WAENDE,1,0);
    hindernisswaende_einfuegen(ANZAHL_DIAGONALE_WAENDE,1,1);
    futter_einfuegen();
    
    spielfeld[snakey][snakex] = SCHLANGE;
    

}

void schlange_initialisieren(){
    spielfeld[snakey][snakex] = SCHLANGE;
}

int main() {

    srand(time(NULL));
    spielfeld_initialisieren();

    //Spielschleife
    int counter = 0;
    char richtung = ' ';

    while(1)
        {
        clear();
        spielfeld_ausgeben();
        counter++;
        printf("%d",counter);
        //Schlange von alter Position löschen
        spielfeld[snakey][snakex] = LEER;
        
        if (kbhit())
            {
            char taste = getchar();
            richtung = taste;
            }
        
        switch (richtung)
            {
            case 'w':
                snakey = snakey - 1;
                printf("going up!");
                break;

            case 's':
                snakey = snakey + 1;
                break;

            case 'a':
                snakex = snakex - 1;
                break;

            case 'd':
                snakex = snakex + 1;
                break;

            default:
                break;
            }
        
        if (snakex == 0)
            snakex = 1;
        
        if (snakex == BREITE-1)
            snakex = BREITE-2;
        
        if (snakey == 0)
            snakey = 1;
        
        if (snakey == HOEHE-1)
            snakey = HOEHE-2;

        //Schlange an neue Stelle erzeugen
        schlange_initialisieren();
        
        mssleep(100);
        }

    return 0;
}


/* Beispiel 2d array

int main(){

float umsaetze[4][7];

float tagesumsatz = 1;
for (int woche=0; woche<=3; woche++)
{
    for (int tag=0; tag<=6; tag++)
    {
        umsaetze[woche][tag] = tagesumsatz;
        tagesumsatz++;
    }
}

for (int woche=0; woche <=3; woche++)
{
    for (int tag=0; tag<=6; tag++)
    {
        printf("Woche %d, Tag %d : %.0f\n", woche, tag, umsaetze[woche][tag]);
    }   

}
}
*/