/**
* @file turno.c
* @author Filippo, Aresù e Dumitru
* @brief Funzione che permette di cambiare turno
*
*/

#include "turno.h"
#include "const.h"

/**
 * Permette di far cambiare turno derante la partita
 *
 *
 * @param turno turno del giocatore
 */
int prossimo_turno (int turno) {
    if (turno == PLAYER1)
        return PLAYER2;
    else /*se è il turno del PLAYER2*/
        return PLAYER1;
}




