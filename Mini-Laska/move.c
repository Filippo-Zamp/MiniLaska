/**
* @file move.c
* @author Filippo, Aresù e Dumitru
* @brief Funzione che permette di far muovere le pedine
*
*/



#include <stdlib.h>
#include "move.h"
#include "struct.h"
#include "const.h"
#include "pop_array.h"


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
void move(int x, int y, int end_x, int end_y, piece_t *pieces){
    int end_coordinates, coordinates;

    end_coordinates = end_x * ROWS + end_y;
    coordinates = x * ROWS + y;

    /*Caso 1: Pedina che si sposta ha altezza 1*/
    if(pieces[coordinates].height == 1) {

        /*Pedina si sposta di una cella - viene fatto un semplice swap*/
        if ((abs(end_x - x)) == 1 && (abs(end_y - y) == 1)) {
            pieces[end_coordinates].color[0] = pieces[coordinates].color[0];
            pieces[end_coordinates].height = pieces[coordinates].height;
            pieces[end_coordinates].go_back[0] = pieces[coordinates].go_back[0];

            pieces[coordinates].color[0] = 'E';
            pieces[coordinates].height = 0;
            pieces[coordinates].go_back[0] = 0;
        }

        /*Pedina si sposta di due celle*/
        if ((abs(end_x - x)) == 2 && (abs(end_y - y) == 2)) {

            /*Pedina mangiata ha altezza 1*/
            if (pieces[(end_x + x) / 2 * ROWS + (end_y + y) / 2].height == 1) {

                pieces[end_coordinates].color[0] = pieces[coordinates].color[0];
                pieces[end_coordinates].color[1] = pieces[(end_x + x) / 2 * ROWS + (end_y + y) / 2].color[0];
                pieces[end_coordinates].height = pieces[coordinates].height + 1;
                pieces[end_coordinates].go_back[0] = pieces[coordinates].go_back[0];
                pieces[end_coordinates].go_back[1] = pieces[(end_x + x) / 2 * ROWS + (end_y + y) / 2].go_back[0];

                pieces[(end_x + x) / 2 * ROWS + (end_y + y) / 2].color[0] = 'E';
                pieces[(end_x + x) / 2 * ROWS + (end_y + y) / 2].height = 0;
                pieces[(end_x + x) / 2 * ROWS + (end_y + y) / 2].go_back[0] = 0;

                pieces[coordinates].color[0] = 'E';
                pieces[coordinates].height = 0;
                pieces[coordinates].go_back[0] = 0;

            }

            /*Pedina mangiata ha altezza >= 2*/
            if (pieces[(end_x + x) / 2 * ROWS + (end_y + y) / 2].height >= 2) {

                pieces[end_coordinates].color[0] = pieces[coordinates].color[0];
                pieces[end_coordinates].color[1] = pieces[(end_x + x) / 2 * ROWS + (end_y + y) / 2].color[0];
                pieces[end_coordinates].height = pieces[coordinates].height + 1;
                pieces[end_coordinates].go_back[0] = pieces[coordinates].go_back[0];
                pieces[end_coordinates].go_back[1] = pieces[(end_x + x) / 2 * ROWS + (end_y + y) / 2].go_back[0];

                /*Deve essere implementato il pusback/pushfront*/
                pop_front(&pieces[(end_x + x) / 2 * ROWS + (end_y + y) / 2]);
                pieces[(end_x + x) / 2 * ROWS + (end_y + y) / 2].height --;

                pieces[coordinates].color[0] = 'E';
                pieces[coordinates].height = 0;
                pieces[coordinates].go_back[0] = 0;
            }
        }
    }

    /*Caso 2: Pedina che si sposta ha altezza = 2*/
    if (pieces[coordinates].height == 2) {

        /*Pedina si sposta di una cella - viene fatto un semplice swap*/
        if ((abs(end_x - x)) == 1 && (abs(end_y - y) == 1)) {
            pieces[end_coordinates].color[0] = pieces[coordinates].color[0];
            pieces[end_coordinates].color[1] = pieces[coordinates].color[1];
            pieces[end_coordinates].go_back[0] = pieces[coordinates].go_back[0];
            pieces[end_coordinates].go_back[1] = pieces[coordinates].go_back[1];
            pieces[end_coordinates].height = pieces[coordinates].height;


            pieces[coordinates].color[0] = 'E';
            pieces[coordinates].color[1] = ' ';
            pieces[coordinates].go_back[0] = 0;
            pieces[coordinates].go_back[1] = 0;
            pieces[coordinates].height = 0;

        }

        /*Pedina si sposta di due celle*/
        if ((abs(end_x - x)) == 2 && (abs(end_y - y) == 2)) {

            /*Pedina mangiata ha altezza 1*/
            if (pieces[(end_x + x) / 2 * ROWS + (end_y + y) / 2].height == 1) {

                    pieces[end_coordinates].color[0] = pieces[coordinates].color[0];
                    pieces[end_coordinates].color[1] = pieces[coordinates].color[1];
                    pieces[end_coordinates].color[2] = pieces[(end_x + x) / 2 * ROWS + (end_y + y) / 2].color[0];
                    pieces[end_coordinates].go_back[0] = pieces[coordinates].go_back[0];
                    pieces[end_coordinates].go_back[1] = pieces[coordinates].go_back[1];
                    pieces[end_coordinates].go_back[2] = pieces[(end_x + x) / 2 * ROWS + (end_y + y) / 2].go_back[0];
                    pieces[end_coordinates].height = pieces[coordinates].height + 1;


                    pieces[(end_x + x) / 2 * ROWS + (end_y + y) / 2].color[0] = 'E';
                    pieces[(end_x + x) / 2 * ROWS + (end_y + y) / 2].go_back[0] = 0;
                    pieces[(end_x + x) / 2 * ROWS + (end_y + y) / 2].height = 0;


                    pieces[coordinates].color[0] = 'E';
                    pieces[coordinates].color[1] = ' ';
                    pieces[coordinates].go_back[0] = 0;
                    pieces[coordinates].go_back[1] = 0;
                    pieces[coordinates].height = 0;

                }

            /*Pedina mangiata ha altezza >= 2*/
            if (pieces[(end_x + x) / 2 * ROWS + (end_y + y) / 2].height >= 2) {

                    pieces[end_coordinates].color[0] = pieces[coordinates].color[0];
                    pieces[end_coordinates].color[1] = pieces[coordinates].color[1];
                    pieces[end_coordinates].color[2] = pieces[(end_x + x) / 2 * ROWS + (end_y + y) / 2].color[0];
                    pieces[end_coordinates].go_back[0] = pieces[coordinates].go_back[0];
                    pieces[end_coordinates].go_back[1] = pieces[coordinates].go_back[1];
                    pieces[end_coordinates].go_back[2] = pieces[(end_x + x) / 2 * ROWS + (end_y + y) / 2].go_back[0];
                    pieces[end_coordinates].height = pieces[coordinates].height + 1;

                    /*Deve essere implementato il pusback/pushfront*/
                    pop_front(&pieces[(end_x + x) / 2 * ROWS + (end_y + y) / 2]);
                    pieces[(end_x + x) / 2 * ROWS + (end_y + y) / 2].height --;

                    pieces[coordinates].color[0] = 'E';
                    pieces[coordinates].color[1] = ' ';
                    pieces[coordinates].go_back[0] = 0;
                    pieces[coordinates].go_back[1] = 0;
                    pieces[coordinates].height = 0;
                }
        }
    }

    /*Caso 3: Pedina che si sposta ha altezza = 3*/
    if (pieces[coordinates].height == 3) {

        /*Pedina si sposta di una cella - viene fatto un semplice swap*/
        if ((abs(end_x - x)) == 1 && (abs(end_y - y) == 1)) {
            pieces[end_coordinates].color[0] = pieces[coordinates].color[0];
            pieces[end_coordinates].color[1] = pieces[coordinates].color[1];
            pieces[end_coordinates].color[2] = pieces[coordinates].color[2];
            pieces[end_coordinates].go_back[0] = pieces[coordinates].go_back[0];
            pieces[end_coordinates].go_back[1] = pieces[coordinates].go_back[1];
            pieces[end_coordinates].go_back[2] = pieces[coordinates].go_back[2];
            pieces[end_coordinates].height = pieces[coordinates].height;


            pieces[coordinates].color[0] = 'E';
            pieces[coordinates].color[1] = ' ';
            pieces[coordinates].color[2] = ' ';
            pieces[coordinates].go_back[0] = 0;
            pieces[coordinates].go_back[1] = 0;
            pieces[coordinates].go_back[2] = 0;
            pieces[coordinates].height = 0;

        }

        /*Pedina si sposta di due celle*/
        if ((abs(end_x - x)) == 2 && (abs(end_y - y) == 2)) {

            /*Pedina mangiata ha altezza 1*/
            if (pieces[(end_x + x) / 2 * ROWS + (end_y + y) / 2].height == 1) {

                pieces[end_coordinates].color[0] = pieces[coordinates].color[0];
                pieces[end_coordinates].color[1] = pieces[coordinates].color[1];
                pieces[end_coordinates].color[2] = pieces[coordinates].color[2];
                pieces[end_coordinates].go_back[0] = pieces[coordinates].go_back[0];
                pieces[end_coordinates].go_back[1] = pieces[coordinates].go_back[1];
                pieces[end_coordinates].go_back[2] = pieces[coordinates].go_back[2];
                pieces[end_coordinates].height = pieces[coordinates].height;


                pieces[(end_x + x) / 2 * ROWS + (end_y + y) / 2].color[0] = 'E';
                pieces[(end_x + x) / 2 * ROWS + (end_y + y) / 2].height = 0;
                pieces[(end_x + x) / 2 * ROWS + (end_y + y) / 2].go_back[0] = 0;

                pieces[coordinates].color[0] = 'E';
                pieces[coordinates].color[1] = ' ';
                pieces[coordinates].color[2] = ' ';
                pieces[coordinates].go_back[0] = 0;
                pieces[coordinates].go_back[1] = 0;
                pieces[coordinates].go_back[2] = 0;
                pieces[coordinates].height = 0;

            }

            /*Pedina mangiata ha altezza >= 2*/
            if (pieces[(end_x + x) / 2 * ROWS + (end_y + y) / 2].height >= 2) {

                pieces[end_coordinates].color[0] = pieces[coordinates].color[0];
                pieces[end_coordinates].color[1] = pieces[coordinates].color[1];
                pieces[end_coordinates].color[2] = pieces[coordinates].color[2];
                pieces[end_coordinates].go_back[0] = pieces[coordinates].go_back[0];
                pieces[end_coordinates].go_back[1] = pieces[coordinates].go_back[1];
                pieces[end_coordinates].go_back[2] = pieces[coordinates].go_back[2];
                pieces[end_coordinates].height = pieces[coordinates].height;

                pop_front(&pieces[(end_x + x) / 2 * ROWS + (end_y + y) / 2]);
                pieces[(end_x + x) / 2 * ROWS + (end_y + y) / 2].height --;

                pieces[coordinates].color[0] = 'E';
                pieces[coordinates].color[1] = ' ';
                pieces[coordinates].color[2] = ' ';
                pieces[coordinates].go_back[0] = 0;
                pieces[coordinates].go_back[1] = 0;
                pieces[coordinates].go_back[2] = 0;
                pieces[coordinates].height = 0;
            }
        }
    }
}