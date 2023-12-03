#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "params.h"
#include "snake_hilfsfunktionen.h"

// main.c -> Präprozessor -> Compiler -> Linker -> Programm

char spielfeld[HOEHE][BREITE];
int snakex = BREITE/2;
int snakey = HOEHE/2;

//Länge ohne Kopf
int snakelaenge = START_SCHLANGE_LAENGE;

int sstueckx[MAX_SCHLANGE_LAENGE];
int sstuecky[MAX_SCHLANGE_LAENGE];

int old_snakey;
int old_snakex;

char richtung;

void quit_game(){
    printf("\nSpiel beendet!\n");
    exit(0);
}

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

void startbereich_freimachen(){
    //Safe Space um die Schlange
    for (int i = HOEHE/2-START_AREA; i < HOEHE/2+START_AREA; i++)
    {
        for (int j = BREITE/2-START_AREA; j < BREITE/2+START_AREA; j++)
        {
            spielfeld[i][j] = LEER;
        }
        
    }
}


void spielfeld_initialisieren(){

    waende_einfuegen();
    hindernisswaende_einfuegen(ANZAHL_VERTIKALE_WAENDE,0,1);
    hindernisswaende_einfuegen(ANZAHL_HORIZONTALE_WAENDE,1,0);
    hindernisswaende_einfuegen(ANZAHL_DIAGONALE_WAENDE,1,1);
    futter_einfuegen();
    startbereich_freimachen();
    spielfeld[snakey][snakex] = SCHLANGEN_KOPF;
    

}

void wand_check()
{
    if (spielfeld[snakey][snakex] == HINDERNIS || spielfeld[snakey][snakex] == RAND)
    {   
        printf("\nDu hast die Schlange in die Wand gefahren!\n");
        quit_game();
    }

    if (spielfeld[snakey][snakex] == FUTTER)
    {
        snakelaenge++;
    }
}

void schlange_initialisieren(){
    spielfeld[snakey][snakex] = SCHLANGEN_KOPF;

    for (int stueck = 0; stueck < snakelaenge; stueck++)
    {
        int kx = sstueckx[stueck];
        int ky = sstuecky[stueck];
        spielfeld[ky][kx] = SCHLANGEN_STUECK;
    }

}

void bewege_schlange_im_spielfeld(int old_snakex, int old_snakey)
{   
    //Lösche aus dem SPielfeld das letzte Schlangenstückchen
    int kx = sstueckx[snakelaenge-1];
    int ky = sstuecky[snakelaenge-1];
    spielfeld[ky][kx] = ' ';



    //Alle weiteren Schlangenstücke rücken eins auf
    for(int stueck=snakelaenge-1; stueck>=1;stueck--)
    {
        sstueckx[stueck] = sstueckx[stueck-1];
        sstuecky[stueck] = sstuecky[stueck-1];
    }   
    
    // Setze das 1.Stück auf die alte Schlangenkopfposition
    sstueckx[0] = old_snakex;
    sstuecky[0] = old_snakey;

    schlange_initialisieren();

}



int main() {

    srand(time(NULL));
   
    for (int stueck=0; stueck<START_SCHLANGE_LAENGE; stueck++)
    {
        sstueckx[stueck] = snakex-stueck-1;
        sstuecky[stueck] = snakey;
    }

    spielfeld_initialisieren();
    schlange_initialisieren();

    //Spielschleife
    int counter = 0;
    char richtung = 'w';

    while(1)
        {
        clear();
        spielfeld_ausgeben();
        counter++;
        printf("Länge: %d, Update: %d",snakelaenge,counter);
        printf("\ntop left:%c\n",spielfeld[0][0]);
        

        printf("sx=%d, sy=%d\n", snakex,snakey);
        for (int stueck=0; stueck<snakelaenge; stueck++)
        {
            printf("stueck #%d: x=%d, y=%d\n", stueck, sstueckx[stueck], sstuecky[stueck]);
        }
        
        if (kbhit())
            {
            char taste = getchar();
            richtung = taste;
            if (taste=='q')
            {
              quit_game();
            }
            
            }
        
        old_snakex = snakex;
        old_snakey = snakey;

        switch (richtung)
            {
            case 'w':
                snakey = snakey - 1;
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
            };

        wand_check();
        //Schlange an neue Stelle erzeugen
        bewege_schlange_im_spielfeld(old_snakex, old_snakey);
        mssleep(120);
        
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