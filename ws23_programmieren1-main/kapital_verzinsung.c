#include <stdio.h>

int main()
{
    printf("StartKapital: ");
    float startkapital;
    scanf("%f", &startkapital);

    printf("Zielkapital: ");
    float zielkapital;
    scanf("%f", &zielkapital);

    printf("Zinssatz in %%: ");
    float zinssatz;
    scanf("%f", &zinssatz);
    zinssatz /= 100;    

    printf("Ok. Ich berechne jetzt wie lange es dauert "
        "dein Startkapital in Höhe von %f EUR so lange mit dem "
        "Zinssatz von %f zu verzinsen, bis dein Zielkapital "
        "in Höhe von %f EUR erreicht ist.\n",
       startkapital, zinssatz, zielkapital);

    float a;
    int b;
    a = startkapital;
    b = 0;
    while (a<zielkapital)
    {
        a = a + a * zinssatz;
        b = b + 1;
        printf("Jahr: %d --> %f\n", b, a);
    }
    
    
    return 0;

}