/**
* @file menu.c
* @author Filippo, Aresù e Dumitru
* @brief Funzioni per il menu del gioco
*
*/

#include <stdio.h>
#include "menu.h"

/**
 * Stampa a schermo il titolo "MINILASKA"
 *
 *
 */
void title(){
    printf(",--.   ,--.,--.,--.  ,--.,--.,--.     ,---.   ,---.  ,--. ,--.  ,---.   \n");
    printf("|   `.'   ||  ||  ,'.|  ||  ||  |    /  O  \\ '   .-' |  .'   / /  O  \\ \n");
    printf("|  |'.'|  ||  ||  |' '  ||  ||  |   |  .-.  |`.  `-. |  .   ' |  .-.  | \n");
    printf("|  |   |  ||  ||  | `   ||  ||  '--.|  | |  |.-'    ||  |\\  \\ |  | |  | \n");
    printf("`--'   `--'`--'`--'  `--'`--'`-----'`--' `--'`-----' `--' '--'`--' `--'\n");
    printf("by Zotea Dumitru, Sadeghi Gol Aresu', Zampiron Filippo\n");
    printf("\n");
}

/**
 * Stampa a schermo le regole del gioco "Minilaska"
 *
 *
 */
void rules(){
    char go_back;
    do {
        printf("--------------------------------------------------------------------------------\n");
        printf("|   MINILASKA                                                                  |\n"
               "|    Regole:                                                                   |\n"
               "|   -In gioco i pezzi si muovovno in avanti diagonalmente, una casella alla    |\n"
               "|    volta, catturano saltando oltre al  pezzo nemico e  atterrando in una     |\n");
        printf("|    casella vuota, un avversario catturato viene raccolto sotto               |\n"
               "|    l'attaccante come prigioniero.                                            |\n"
               "|                                                                              |\n"
               "|   -La torre prodotta a seguito di una cattura viene spostata come un pezzo   |\n"
               "|    unico appartenente al giocatore che l'ha mangiata.                        |\n"
               "|                                                                              |\n");
        printf("|   -Quando una torre viene attaccata, viene catturato solo il pezzo in cima   |\n"
               "|    ad essa, inoltre un pezzo non puo' attaccare lo stesso pezzo avversario   |\n"
               "|    due volte nel corso di una singola mossa.                                 |\n"
               "|                                                                              |\n");
        printf("|   -Se una torre nemica viene catturata e in quel momento la torre ha un      |\n"
               "|    prigioniero alleato, il prigioniero alleato viene liberato.               |\n"
               "|                                                                              |\n");
        printf("|   -Una volta che 3 pezzi sono impilati, nessun altro pezzo puo' essere       |\n"
               "|    impilato sotto di essi, invece il pezzo inferiore viene rimosso dalla     |\n"
               "|    tavola.                                                                   |\n"
               "|                                                                              |\n");
        printf("|   -Quando una torre raggiunge l'estremita' opposta della tavola(la prima     |\n"
               "|    linea dell'avversario) il pezzo viene promosso, il pezzo promosso puo'    |\n"
               "|    muoversi sia avanti che indietro.                                         |\n"
               "|                                                                              |\n");
        printf("|   -Se catturato, un pezzo promosso mantiene la sua promozione per l'uso se   |\n"
               "|    successivamente rilasciato.                                               |\n"
               "|                                                                              |\n");
        printf("|   -Sia per selezionare le cordinate della pedina che vuoi muovere e la       |\n"
               "|    casella dove la vuoi muovere invia NUMERO RIGA-NUMERO COLONNA, se stai    |\n"
               "|    mangiando una pedina basta che invii le coordinate finali.                |\n"
               "|                                                                              |\n"
               "|   Buon divertimento!                                                         |\n");
        printf("--------------------------------------------------------------------------------\n");
        printf("Premi invio per tornare al menu principale\n");
        scanf("%c", &go_back);
    }while(!getchar());

}

/**
 * Stampa a schermo e permette di scegliere le modalità di gioco
 *
 * @return ritorna la scelata fatta dal giocatore
 */
int mode(){

    int choice = 0;

    do {
        printf("--------------------------------------------------------------------------------\n");
        printf("| Scegli la modalita' di gioco:                                                |\n");
        printf("| 0. Torna indietro al menu principale                                         |\n");
        printf("| 1. Inizia una partita contro un tuo amico in locale                          |\n");
        printf("--------------------------------------------------------------------------------\n");
        scanf("%d", &choice);
    }while(choice != 0 && choice != 1);

    return choice;

}

/**
 * Funzione principale del menù
 *
 * @param status stato che  permette di muoversi all'inteno del menù
 */
void menu(int* status) {
    int choice;
    int menu_status;

    do
    {
        printf("--------------------------------------------------------------------------------\n");
        printf("| 1. Regole                                                                    |\n");
        printf("| 2. Modalita'                                                                 |\n");
        printf("| 3. Quit (ricorda che per uscire dal gioco durante la partita inserire '9')   |\n");
        printf("--------------------------------------------------------------------------------\n");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1: rules();
                break;
            case 2: /*Chiama la funzione per giocare con un tuo amico*/
                menu_status = mode();
                if (menu_status == 0){
                    menu(status);
                }
                else {
                    *status = menu_status;
                }
                break;
            case 3: printf("Arrivederci!\n");
                *status = choice;
                break;
            default: printf("Scelta invalida, riprova.\n");
                break;
        }


    } while (choice != 3 && choice !=2);

}