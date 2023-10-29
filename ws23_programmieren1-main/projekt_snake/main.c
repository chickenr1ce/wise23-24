#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "params.h"
#include "snake_hilfsfunktionen.h"

// main.c -> Präprozessor -> Compiler -> Linker -> Programm

char spielfeld[HOEHE][BREITE];
int snakex = BREITE/2;
int snakey = HOEHE/2;

void waende_einfuegen(){
    
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

void spielfeld_ausgeben(){

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
    srand(time(NULL));
    for ( int i = 0; i < ANZAHLFUTTER; i++)
        {
        int zufallshoehe = rand() % (HOEHE-2) + 1;
        int zufallsbreite = rand() % (BREITE-2) + 1;
        spielfeld[zufallshoehe][zufallsbreite] = FUTTER;
        }
}

void spielfeld_initialisieren(){

    waende_einfuegen();
    futter_einfuegen();
    spielfeld[snakey][snakex] = SCHLANGE;
    

}

void schlange_initialisieren(){
    spielfeld[snakey][snakex] = SCHLANGE;
}

int main() {

    spielfeld_initialisieren();

    //Spielschleife
    int counter = 0;

    while(1) {
        clear();
        spielfeld_ausgeben();
        counter++;
        printf("%d",counter);
        
        //Hat der Benutzer eine Taste gedrückt?
        if (kbhit()){
            //Schlange von alter Position löschen
            spielfeld[snakey][snakex] = LEER;
            char taste = getchar();
            if (taste=='w'){
                snakey = snakey-1;
            }
            if (taste=='s'){
                snakey = snakey+1;
            }
            if (taste=='a'){
                snakex = snakex-1;
            }
            if (taste=='d'){
                snakex = snakex+1;
            }
            if (snakex == 0){
                snakex = 1;
            }
            if (snakey == 0){
                snakey = -1;
            }

            //Schlange an neue Stelle erzeugen
            schlange_initialisieren();
        }
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