/**
* @file pop_array.c
* @author Filippo, Aresù e Dumitru
* @brief Funzione che elimina pedina in cima di una torre
*
*/


#include "pop_array.h"
#include "struct.h"

/**
 * Elimina pedina in cima di una torre
 *
 *
 * @param piece pedina
 */
void pop_front (piece_t* piece){

    piece->color[0] = piece->color[1];
    piece->color[1] = piece->color[2];

    if(piece->height == 2)
        piece->color[1] = ' ';

    piece->color[2] = ' ';

    piece->go_back[0] = piece->go_back[1];
    piece->go_back[1] = piece->go_back[2];

    if(piece->height == 2)
        piece->go_back[1] = 0;

    piece->go_back[2] = 0;
}