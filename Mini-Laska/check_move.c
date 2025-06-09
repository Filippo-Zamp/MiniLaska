/**
* @file check_move.c
* @author Filippo, Aresù e Dumitru
* @brief Funzioni che controllano se le pedine sono selezionabili, se hanno mangiate obbligatorie e se si possono muovere in determinate caselle
*
*/


#include <stdlib.h>
#include <stdio.h>
#include "check_move.h"
#include "const.h"
#include "move.h"
#include "list.h"

/**
 * Promozione pedine quando una torre raggiunge l'estremità opposta della tavola, da quel momento la pedina può muoversi sia avanti che indietro
 *
 * @param end_x coordinate della cella d'arrivo
 * @param end_y coordinate della cella d'arrivo
 * @param turn turno del giocatore
 * @param pieces pedine
 */
void promotion( int end_x, int end_y, int turn, piece_t *pieces){
    int end_coordinates;

    end_coordinates = end_x * ROWS + end_y;

    if(turn == PLAYER1){
        if(end_coordinates < 7){
            pieces[end_coordinates].go_back[0] = 1;
        }
    }else{
        if(end_coordinates> 41){
            pieces[end_coordinates].go_back[0] = 1;
        }
    }
}

/**
 * Funzione principale che controlla se le pedine sono selezionabili, se hanno mangiate obbligatorie e se si possono muovere in determinate caselle (chiamando le altre funzioni)
 *
 * @param x coordinate della cella
 * @param y coordinate della cella
 * @param turn turno del giocatore
 * @param man_move mangiata obbligatoria
 * @param pieces pedine
 */
int check_selection(int x, int y, int turn, int* man_move, piece_t *pieces){
    int coordinates;
    int status;

    /*Controllo se le coordinate x, y sono minori di 7*/
    if(x < 7 && y <7 && x >= 0 && y >= 0) {
        coordinates = x * ROWS + y;

        /*Controllo se cerco di spostarmi verso una cella non valida*/
        if (pieces[coordinates].color[0] == 'N') {
            printf("Non puoi selezionare questa casella!\n");
            return 1;
        }

        /*Controllo se sto selezionando una cella vuota*/
        if (pieces[coordinates].color[0] == 'E') {
            printf("Non c'e nessuna pedina in questa cella!\n");
            return 1;
        }

        /*Controllo se sto selezionando una pedina del mio colore se e' il mio turno*/
        if ((turn == PLAYER1 && (pieces[coordinates].color[0] == 'W')) ||  (turn == PLAYER2 && (pieces[coordinates].color[0] == 'B'))) {
            /*Controllo della pedina selezionata:
              -Mangiata obbligatoria? SI/NO
              -Pedina ha mosse disponibili? SI/NO*/

            /*Chiamata funzione*/

            status = mandatory_selectable(turn, coordinates, man_move, pieces);

            if(status == 0){
                return 0;
            }
            else {
                if (status == 1) {
                    printf("Ci sono mangiate obbligatorie!\n");
                    return 1;
                }
                else {
                    printf("La pedina che hai selezionato non ha mosse disponibili!\n");
                    return 1;
                }
            }

        } else {
            printf("Non puoi selezionare questa pedina! Seleziona la pedina del tuo colore!\n");
            return 1;
        }
    }
    else{
        printf("Le coordinate inserite non sono valide!\n");
        return 1;
    }
}

/**
 * Controllo se la pedina è selezionabile e se il giocatore ha delle mangiate obbligatorie da eseguire
 *
 * @param coordinates coordinate della cella
 * @param turn turno del giocatore
 * @param man_move mangiata obbligatoria
 * @param pieces pedine
 */
int mandatory_selectable(int turn, int coordinates, int* man_move, piece_t *pieces){
    int i; /*Contatore che scorre le struct*/
    char a, b;
    list list_mandatory;
    list list_selectable;

    i = 0;

    if(turn == PLAYER1){
        a = 'W';
        b = 'B';
    }
    else if( turn == PLAYER2){
        a = 'B';
        b = 'W';
    }

    /*controlla se ci sono MOSSE OBBLIGATORIE e compila in una lista le pedine ce devono svolgere queste mosse*/
    list_mandatory = crea_lista_vuota();

    while(i<49){

        if (pieces[i].color[0] == a) {

            if ((a == 'B')||(a == 'W' && pieces[i].go_back[0] == 1)) {

                if (((i + 1) % 7 != 1)&&((i + 1) % 7 != 2)) {
                    if ((i + 2 * 6) <= 49 && pieces[i + 6].color[0] == b && pieces[i + 2 * 6].color[0] == 'E') {
                        list_mandatory = push_back(list_mandatory, i);
                    }
                }

                if (((i + 1) % 7 != 0)&&((i + 1) % 7 != 6)) {
                    if ((i + 2 * 8) <= 49 && pieces[i + 8].color[0] == b && pieces[i + 2 * 8].color[0] == 'E') {
                        list_mandatory = push_back(list_mandatory, i);
                    }
                }

            }

            if ((a == 'W')||(a == 'B' && pieces[i].go_back[0] == 1)){
                if (((i + 1) % 7 != 0)&&((i + 1) % 7 != 6)) {
                    if ((i - 2 * 6) >= 0 && pieces[i - 6].color[0] == b && pieces[i - 2 * 6].color[0] == 'E') {
                        list_mandatory = push_back(list_mandatory, i);
                    }
                }

                if (((i + 1) % 7 != 1)&&((i + 1) % 7 != 2)) {
                    if ((i - 2 * 8) >= 0 && pieces[i - 8].color[0] == b && pieces[i - 2 * 8].color[0] == 'E') {
                        list_mandatory = push_back(list_mandatory, i);
                    }
                }
            }
        }

        i++;
    }

    /* se la lista ha coordinate stampa la lista delle mandatory movereturn 1;
     * dopo sarebbe bene mettere un controllo per essere sicuri che effettivamente solgono la mandatory move
     * se la lista è vuota svolgere il seguente while
     */



    if(list_mandatory == NULL) {

        i = 0;
        list_selectable = crea_lista_vuota();

        while (i < 49) {

            if (pieces[i].color[0] == a) {

                if ((a == 'B') || (a == 'W' && pieces[i].go_back[0] == 1)) {

                    if ((i + 1) % 7 != 1) {
                        if ((i + 6) <= 49 && pieces[i + 6].color[0] == 'E') {
                            list_selectable = push_back(list_selectable, i);
                        }
                    }

                    if ((i + 1) % 7 != 0) {
                        if ((i + 8) <= 49 && pieces[i + 8].color[0] == 'E') {
                            list_selectable = push_back(list_selectable, i);
                        }
                    }

                }
                if ((a == 'W') || (a == 'B' && pieces[i].go_back[0] == 1)) {
                    if ((i+1) % 7 != 0) {
                        if ((i - 6) >= 0 && pieces[i - 6].color[0] == 'E') {
                            list_selectable = push_back(list_selectable, i);
                        }
                    }

                    if ((i+1) % 7 != 1) {
                        if ((i - 8) >= 0 && pieces[i - 8].color[0] == 'E') {
                            list_selectable = push_back(list_selectable, i);
                        }
                    }
                }
            }

            i++;
        }

        if(list_selectable == NULL){
            return 4;
        }

        /* Scorrere la lista e controllare che le coordinate "coordinates" sono presenti all'interno di essa
         * Caso in cui non ci sono mangiate obbligatorie
         */

        if(schrodinger_list(list_selectable, coordinates)){
            free_lista(list_selectable);
            return 0;
        }
        else{
            free_lista(list_selectable);
            return 2;
        }

    }
    else {

        /*Caso in cui c'e' una mangiata obbligatoria
        Scorrere la lista e controllare se le coordinate coordinates sono presenti all'interno di essa*/
        *man_move = 1;

        if(schrodinger_list(list_mandatory, coordinates)){
            free_lista(list_mandatory);
            return 0;
        }
        else{
            free_lista(list_mandatory);
            return 1;
        }

    }

    /*
     * 0 = Tutto ok
     * 1 = Mangiata obbligatoria. Pedina selezionata e' errata
     * 2 = Pedina selezionata non ha mosse disponibili
    */

}

/**
 * Controllo delle coordinate selezionate dal giocatore, se non sono valide potranno essere reinserite subito dopo
 *
 * @param x coordinate della cella di partenza
 * @param y coordinate della cella di partenza
 * @param end_x coordinate della cella d'arrivo
 * @param end_y coordinate della cella d'arrivo
 * @param turn turno del giocatore
 * @param man_move mangiata obbligatoria
 * @param pieces pedine
 */
int check_move(int x, int y, int end_x, int end_y, int turn, int* man_move, piece_t *pieces){
    int coordinates;
    int end_coordinates;

    /*Controllo se le coordinate inserite rientrano nella board*/
    if(end_x < 7 && end_y <7 && end_x >= 0 && end_y >= 0) {
        coordinates = x * ROWS + y;
        end_coordinates = end_x * ROWS + end_y;

        /*Controllo se lo spostamento (in valore assoluto) e' <= 2. Non posso spostarmi piu di due caselle*/
        if(((abs(end_x-x) <= 2) && (abs(end_y-y) <= 2))){

            /*Controllo se la pedina viene spostata all'indietro*/
            if((((end_x > x && turn == PLAYER2) || (end_x < x && turn == PLAYER1)) && pieces[coordinates].go_back[0] == 0)||(pieces[coordinates].go_back[0] == 1)) {
                /*Controllo se mi sto spostando sulla stessa cella*/
                if (end_x == x && end_y == y) {
                    printf("Non puoi spostarti sulla cella di partenza!\n");
                    return 1;
                }

                /*Controllo se mi sto spostando su una cella nulla*/
                if (pieces[end_coordinates].color[0] == 'N') {
                    printf("Non puoi spostarti in questa casella! Casella non valida\n");
                    return 1;
                }

                /*Controllo se mi sto spostando su una cella gia occupata*/
                if ((pieces[end_coordinates].color[0] == 'W') || (pieces[end_coordinates].color[0] == 'B')) {
                    printf("Non puoi spostarti in questa casella! E' gia occupata!\n");
                    return 1;
                }

                /*Controllo se mi sto spostando lateralmente o verticalmente di 2 celle (spostamento 2 - 0 / 0 - 2)*/
                if ((((abs(end_x - x)) == 2) && (abs(end_y - y) == 0)) ||
                    (((abs(end_x - x)) == 0) && (abs(end_y - y) == 2))) {
                    printf("Non puoi spostarti in questa casella!\n");
                    return 1;
                }

                /*Controllo se mi sposto di una cella*/
                if (((abs(end_x - x)) == 1 && (abs(end_y - y) == 1)) && *man_move == 0 ) {
                    move(x, y, end_x, end_y, pieces);
                    promotion(end_x, end_y, turn, pieces);
                    return 0;
                }
                else if(((abs(end_x - x)) == 1 && (abs(end_y - y) == 1)) && *man_move == 1){
                    printf("Non puoi spostarti in questa casella! C'e la mangiata obbligatoria da fare!\n");
                    return 1;
                }


                /*Controllo se mi sposto di due celle*/
                if ((abs(end_x - x)) == 2 && (abs(end_y - y) == 2)) {
                    if(((pieces[(end_x + x)/2 * ROWS + (end_y + y)/2].color[0] == 'W') && turn == PLAYER2) ||
                       ((pieces[(end_x + x)/2 * ROWS + (end_y + y)/2].color[0] == 'B') && turn == PLAYER1)){
                        move(x, y, end_x, end_y, pieces);
                        promotion(end_x, end_y, turn, pieces);
                        return 0;
                    }
                    else{
                        printf("Non puoi saltare una pedina dello stesso colore!\n");
                        return 1;
                    }
                }
            }
            else{
                printf("Non puoi tornare indietro con questa pedina!\n");
                return 1;
            }
        }
        else{
            printf("Non puoi spostarti piu di due caselle!\n");
            return 1;
        }

    }
    else{
        printf("Le coordinate inserite non sono valide!\n");
        return 1;
    }
    return 0;
}
