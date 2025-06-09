
/**
* @file main.c
* @author Filippo, Aresù e Dumitru
* @brief MAIN
* @section intro_sec Introduzione
*
* Abbiamo chiamato mini-Laska una variante del gioco originale http://www.lasca.org/.
* Rispetto al gioco originale miniLaska prevede le seguenti limitazioni:
* • si può mangiare/conquistare una sola volta per mossa
* • le torri possono essere alte al massimo 3 pedine, superato questo limite, la pedina più in basso viene rimossa
* dalla scacchiera
* Tutti i dettagli del gioco sono disponibli qui: http://www.lasca.org/
*
*/



#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "const.h"
#include "init.h"
#include "menu.h"
#include "print.h"
#include "check_move.h"
#include "turno.h"


/**
 * Funzione main del progetto Minilaska
 *
 *
 */
int main() {

    int coord_x, coord_y; /*Coordinate x e y della pedina che si seleziona*/
    int end_coord_x, end_coord_y; /*Coordinate "finali" dove si vuole spostare la pedina*/
    int turn = PLAYER1; /*turno*/
    int man_move = 0;
    int status;
    int end_game = 1;
    char end;
    piece_t *pieces = (piece_t*)malloc(49 * sizeof(piece_t));

    title();
    menu(&status);
    init_piece(pieces);

    /*FUNZIONE MOSSE*/
    if(status == 0){
        return 0;
    }
    if(status == 1) {
        while (end_game) {

            /*FUNZIONE PRINT BOARD*/
            print_board(pieces, 3);

            if(mandatory_selectable(turn ,0, &man_move, pieces) == 4){ /*se list_selectable è uguale a 4 significa che la lista è vuota(ovvero che non ho mosse disponibili)*/
                end_game = 0;
                if(turn == PLAYER1){
                    do{
                        printf("Il secondo giocatore ha vinto\n");
                        printf("Premi invio per chiudere il programma.\n");
                       scanf("%c", &end);
                    }while(!getchar());
                }
                else {
                    do{
                        printf("Il primo giocatore ha vinto\n");
                        printf("Premi invio per chiudere il programma.\n");
                        scanf("%c", &end);
                    }while(!getchar());
                }

            }
            else {
                if(turn == PLAYER1){
                    printf("[Turno delle pedine bianche (W)]\n");
                }
                else {
                    printf("[Turno delle pedine nere (B)]\n");
                }
                do {
                    printf("Quale pedina vuoi selezionare?\n");
                    scanf("%d-%d", &coord_x, &coord_y);

                    if(coord_x == 9){ /*per terminare gioco durante la partita premere 9*/
                        printf("Grazie per aver giocato!\n");
                        free(pieces);/*memoria deallocata*/
                        return 0;
                    }

                } while (check_selection(coord_x, coord_y, turn, &man_move, pieces));

                /*Se check_selection e' vero allora esce dal ciclo, altrimenti stampa l'errore e richiede l'input*/
                do {
                    printf("Dove vuoi spostare la pedina?\n");
                    scanf("%d-%d", &end_coord_x, &end_coord_y);

                    if(end_coord_x == 9) { /*per terminare gioco durante la partita premere 9*/
                        printf("Grazie per aver giocato!\n");
                        free(pieces);/*memoria deallocata*/
                        return 0;
                    }

                } while (check_move(coord_x, coord_y, end_coord_x, end_coord_y, turn, &man_move, pieces));

                turn = prossimo_turno(turn);
                man_move = 0;
            }
        }
    }
    free(pieces);/*memoria deallocata*/
    return 0;
}
