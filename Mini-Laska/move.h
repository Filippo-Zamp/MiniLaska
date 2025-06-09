/**
* @file move.h
* @author Filippo, Aresù e Dumitru
* @brief Libreria per far muovere le pedine
*
*/

#ifndef PROGETTO_MINILASKA_MOVE_H
#define PROGETTO_MINILASKA_MOVE_H
#include "struct.h"

/**
 * Permette di far muovere le pedine all'interno della scacchiera ed è integrata la mangiata di pedine
 *
 *
 * @param x coordinate iniziali (di partenza)
 * @param y coordinate iniziali (di partenza)
 * @param end_x coordinate finali (di destinazione)
 * @param end_y coordinate finali (di destinazione)
 * @param pieces pedina
 */
void move(int x, int y, int end_x, int end_y, piece_t *pieces);

#endif /*PROGETTO_MINILASKA_MOVE_H*/
