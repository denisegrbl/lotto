/**********************************************************************\
* Kurzbeschreibung: Uebung: 5.5.1; Punkte: 0
*
* Datum:       Autor:           Grund der Aenderung:
* 30.03.2021   Denise Griebel   Neuerstellung
\**********************************************************************/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void ziehe_zufaellige_zahlen();
/*--- Funktionsdefinitionen ------------------------------------------*/
int main( void )
{
    char c;
    int  menge = -1, kugeln = -1, k;

    printf("Lottozahlen-Simulation\n");
    printf("======================\n");

    printf("Wie viele Kugeln sollen zur Verfuegung stehen(min. 1 und max. 100):");
    scanf("%d", &menge);
    while(menge < 1 || menge > 100)
    {
        while ((c = getchar()) != '\n' && c != EOF)
        {
        }
        printf("\nVersuchen Sie es nochmal.\n\n"
               "Wie viele Kugeln sollen zur Verfügung stehen.(min. 1 und max. 100):\n");
        scanf("%d", &menge);
    }

    printf("\nWie viele werden davon gezogen (min. 1 und max. %d):", menge);
    scanf("%d", &kugeln);
    while(kugeln < 1 || kugeln > menge)
    {
        while ((c = getchar()) != '\n' && c != EOF)
        {
        }
        printf("\nVersuchen Sie es nochmal.\n\n"
               "Wie viele werden davon gezogen (min. 1 und max. %d):", menge);
        scanf("%d", &kugeln);
    }

    int gezogen [kugeln];
    ziehe_zufaellige_zahlen (gezogen, menge, kugeln);

    printf("\n\n---- %d aus %d ----\n", kugeln, menge);
    for(k = 0; k < kugeln; k++)
    {
        printf("\t%d", gezogen[0+k]);
        if(k == 9 && k != 0)
        {
            printf("\n");
            k=0;
        }
    }

    return 0;
}

void ziehe_zufaellige_zahlen(int * gezogen, int gezogenemenge, int gezogenekugeln)
{
    int doppelt = 0, i = 0, j;

    srand(time(NULL));
    do
    {
        gezogen[i] = (rand() % ( gezogenemenge -1 + 1) +1 );
         for(j = 0; j < gezogenekugeln && !doppelt; j++)
         {
               if(gezogen[j] == gezogen[i] && j != i)
               {
                    doppelt = 1;
               }
        }
        if(doppelt)
        {
            doppelt = 0;
        }else
        {
            i++;
        }

    }while(i < gezogenekugeln);
}
