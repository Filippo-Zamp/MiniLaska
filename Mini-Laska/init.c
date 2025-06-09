/**
* @file init.c
* @author Filippo, Aresù e Dumitru
* @brief Funzione che inizializza pedine
*
*/


#include "struct.h"
#include "init.h"

/**
 * Inizializza la scacchiera (le pedine, le celle vuote, le celle "proibite")
 *
 * @param pieces pedine
 */
void init_piece (piece_t *pieces){
    int count, count_1;

    /*Inizializzazione height e promozione*/
    for(count = 0; count < 49; count++){
        for(count_1 = 0; count_1 < 3; count_1++) {
            pieces[count].go_back[count_1] = 0;
        }
        if (count % 2 == 0) {
            pieces[count].height = 1;
        }
        else{
            pieces[count].height = 0;
        }
    }

    /*Inizializzazione celle NULL*/
    for(count = 0; count < 49; count++) {
        if (count % 2 != 0) {
            for(count_1 = 0; count_1 < 3; count_1++) {
                if (count_1 == 0) {
                    pieces[count].color[count_1] = 'N';/* N (=NULL)*/
                } else {
                    pieces[count].color[count_1] = ' ';
                }
            }
        }
    }

    /*Inizializzazione pedine nere (BLACK)*/
    for(count = 0; count < 21; count++){
        if (count % 2 == 0) {
            /*Inizializzazione colori*/
            for(count_1 = 0; count_1 < 3; count_1++) {
                if (count_1 == 0) {
                    /*Posizione 0 = colore pedina/torre*/
                    pieces[count].color[count_1] = 'B';
                } else {
                    pieces[count].color[count_1] = ' ';
                }
            }
        }
    }

    /*Inizializzazione pedine bianche (WHITE)*/
    for(count = 28; count < 49; count++){
        if(count % 2 == 0){
            /*Inizializzazione colori*/
            for(count_1 = 0; count_1 < 3; count_1++) {
                if (count_1 == 0) {
                    pieces[count].color[count_1] = 'W';
                } else {
                    pieces[count].color[count_1] = ' ';
                }
            }
        }
    }

    /*Inizializzazione celle vuote (EMPTY)*/
    for(count = 22; count < 27; count++){
        if(count %2 == 0){
            for(count_1 = 0; count_1 < 3; count_1++) {
                if (count_1 == 0) {
                    pieces[count].color[count_1] = 'E';
                } else {
                    pieces[count].color[count_1] = ' ';
                }
            }
        }
    }

}

