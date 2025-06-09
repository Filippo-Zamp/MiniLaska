/**
* @file print.c
* @author Filippo, Aresù e Dumitru
* @brief Funzioni che stampano la tavola da gioco con le pedine
*
*/

#include <stdio.h>
#include <string.h>
#include "struct.h"
#include "const.h"
#include "print.h"

/**
 * Genera riga in basso della scacchiera
 *
 *
 * @param dim larghezza linea
 */
void print_board_low_line (int dim){
    int rip_col;
    printf("   ");
    for (rip_col = 0; rip_col < dim; rip_col++) {
        printf("---");
    }
    printf("\n");
}


/**
 * Genera linea in alto alla scacchiera
 *
 *
 * @param dim larghezza linea
 */
void print_board_up_line (const int dim){
    int rip_col;
    printf("   ");
    for (rip_col = 0; rip_col < dim; rip_col++) {
        printf("---");
    }
    printf("\n");
}
/**
* Genera numeri in alto alla scacchiera per indicare le caselle
*
*/
void print_board_up_numbers (){
    int i;
    for(i=0; i<7; i++) {
        printf("       %d ", i);
    }
    printf("\n");
}

/**
 * Genera l'intera scacchiera
 *
 *
 * @param dim dimensione delle celle
 * @param pieces pedine
 */
void print_board(piece_t *pieces, const int dim) {
    int count_rows, count_cols;
    int rip_riga, rip_col;
    int coordinates;
    int i=0;

    print_board_up_numbers();
    print_board_up_line(21);

    /*RIGHE della scacchiera*/
    for (count_rows = 0; count_rows < 7; count_rows++) {

        for (rip_riga = 0; rip_riga < dim; rip_riga++) {/*UTILIZZO rip_riga PER CREARE CASELLE DI GRANDEZZA dim*/

            if(rip_riga==1)
                printf("%d ",i++); /*stampa numeri a sinistra della scacchiera*/

            else
                printf("  ");
            printf("|"); /* Linea a sinistra della scacchiera */

            /*COLONNE della scacchiera*/
            for (count_cols = 0; count_cols < 7; count_cols++) {

                for (rip_col = 0; rip_col < dim; rip_col++) {/*UTILIZZO rip_col PER CREARE CASELLE DI GRANDEZZA dim*/
                    coordinates = count_rows * ROWS + count_cols;

                    if (pieces[coordinates].color[0] == 'N') {
                        printf("###");
                    }

                    if (pieces[coordinates].color[0] == 'W') {

                        if (rip_riga==1 && rip_col==1) {
                                /*STAMPA PEDINE WHITE ALL'INTERNO DELLA CASELLA in base alle rispettive altezze*/
                                if (pieces[coordinates].height == 1){
                                        printf(" %c ", pieces[coordinates].color[0]);
                                }
                                if (pieces[coordinates].height == 2){
                                        printf(" %c%c",pieces[coordinates].color[0],pieces[coordinates].color[1]);
                                }
                                if (pieces[coordinates].height == 3){
                                        printf("%c%c%c", pieces[coordinates].color[0],pieces[coordinates].color[1],pieces[coordinates].color[2]);
                                }
                        }
                        else if(pieces[coordinates].go_back[0]==1 && (rip_riga==0 && rip_col==1)){
                            /*STAMPA "CAPPELLO" PROMOZIONE WHITE ALL'INTERNO DELLA CASELLA in base alle rispettive altezze*/
                            if (pieces[coordinates].height == 1){
                                printf(" _ ");
                            }
                            if (pieces[coordinates].height == 2){
                                printf(" __");
                            }
                            if (pieces[coordinates].height == 3){
                                printf("___");
                            }
                        }
                        else
                            /*SPAZIO VUOTO CASELLA*/
                            printf("   ");
                    }

                    if (pieces[coordinates].color[0] == 'B') {

                        if (rip_riga==1 && rip_col==1){
                            /*STAMPA PEDINE BLACK ALL'INTERNO DELLA CASELLA in base alle rispettive altezze*/
                            if (pieces[coordinates].height == 1){
                                    printf(" %c ", pieces[coordinates].color[0]);
                            }
                            if (pieces[coordinates].height == 2){
                                    printf(" %c%c",pieces[coordinates].color[0],pieces[coordinates].color[1]);
                            }
                            if (pieces[coordinates].height == 3){
                                    printf("%c%c%c", pieces[coordinates].color[0],pieces[coordinates].color[1],pieces[coordinates].color[2]);
                            }
                        }
                        else if(pieces[coordinates].go_back[0]==1 && (rip_riga==0 && rip_col==1)){
                            /*STAMPA "CAPPELLO" PROMOZIONE BLACK ALL'INTERNO DELLA CASELLA in base alle rispettive altezze*/
                            if (pieces[coordinates].height == 1){
                                printf(" _ ");
                            }
                            if (pieces[coordinates].height == 2){
                                printf(" __");
                            }
                            if (pieces[coordinates].height == 3){
                                printf("___");
                            }
                        }
                        else
                            /*STAMPA SPAZIO VUOTO CASELLA*/
                            printf("   ");
                    }

                    if (pieces[coordinates].color[0] == 'E') {
                        /*CASELLA VUOTA*/
                        printf("   ");

                    }

                }

            }
            printf("|"); /* Linea a destra della scacchiera */
            printf("\n");
        }
    }

    print_board_low_line(21);

}