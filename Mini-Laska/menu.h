/**
* @file menu.h
* @author Filippo, Aresù e Dumitru
* @brief Libreria per il menu del gioco
*
*/

#ifndef MAIN_C_MENU_H
#define MAIN_C_MENU_H

/**
 * Stampa a schermo il titolo "MINILASKA"
 *
 *
 */
void title();

/**
 * Stampa a schermo le regole del gioco "Minilaska"
 *
 *
 */
void rules();

/**
 * Stampa a schermo e permette di scegliere le modalità di gioco
 *
 *
 */
int mode();

/**
 * Funzione principale del menù
 *
 * @param status stato che  permette di muoversi all'inteno del menù
 */
void menu(int *status);

#endif