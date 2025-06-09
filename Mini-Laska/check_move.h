/**
* @file check_move.h
* @author Filippo, Aresù e Dumitru
* @brief Libreria che controlla se le pedine sono selezionabili, se hanno mangiate obbligatorie e se si possono muovere in determinate caselle
*
*/

#ifndef PROGETTO_MINILASKA_CHECK_MOVE_H
#define PROGETTO_MINILASKA_CHECK_MOVE_H
#include "struct.h"

/**
 * Promozione pedine quando una torre raggiunge l'estremità opposta della tavola, da quel momento la pedina può muoversi sia avanti che indietro
 *
 * @param end_x coordinate della cella d'arrivo
 * @param end_y coordinate della cella d'arrivo
 * @param turn turno del giocatore
 * @param pieces pedine
 */
void promotion( int end_x, int end_y, int turn, piece_t *pieces);

/**
 * Funzione principale che controlla se le pedine sono selezionabili, se hanno mangiate obbligatorie e se si possono muovere in determinate caselle (chiamando le altre funzioni)
 *
 * @param x coordinate della cella
 * @param y coordinate della cella
 * @param turn turno del giocatore
 * @param man_move mangiata obbligatoria
 * @param pieces pedine
 */
int check_selection(int x, int y, int turn, int* man_move, piece_t *pieces);

/**
 * Controllo se la pedina è selezionabile e se il giocatore ha delle mangiate obbligatorie da eseguire
 *
 * @param coordinates coordinate della cella
 * @param turn turno del giocatore
 * @param man_move mangiata obbligatoria
 * @param pieces pedine
 */
int mandatory_selectable(int turn, int coordinates, int* man_move, piece_t *pieces);

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
int check_move(int x, int y, int end_x, int end_y, int turn, int* man_move, piece_t *pieces);

#endif /*PROGETTO_MINILASKA_CHECK_MOVE_H*/
