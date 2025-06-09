/**
* @file print.h
* @author Filippo, Aresù e Dumitru
* @brief Libreria per stampare la tavola da gioco con le pedine
*
*/

#ifndef PROGETTO_MINILASKA_PRINT_H
#define PROGETTO_MINILASKA_PRINT_H

/**
 * Genera riga in basso della scacchiera
 *
 *
 * @param dim larghezza linea
 */
void print_board_low_line (int dim);

/**
 * Genera linea in alto alla scacchiera
 *
 *
 * @param dim larghezza linea
 */
void print_board_up_line (const int dim);

/**
* Genera numeri in alto alla scacchiera per indicare le caselle
*
*/
void print_board_up_numbers ();

/**
 * Genera l'intera scacchiera
 *
 *
 * @param dim dimensione delle celle
 * @param pieces pedine
 */
void print_board(piece_t *pieces, const int dim) ;

#endif /*PROGETTO_MINILASKA_PRINT_H*/
