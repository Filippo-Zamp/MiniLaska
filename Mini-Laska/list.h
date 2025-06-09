/**
* @file list.h
* @author Filippo, Aresù e Dumitru
* @brief Una piccola libreria per le liste
*
*/

#ifndef CHECK_MOVE_C_LIST_H
#define CHECK_MOVE_C_LIST_H

typedef struct node{ /*struct lista*/
    int data;
    struct node* next;
} node_t;

typedef node_t* list;

/**
 * Crea lista vuota
 *
 * @return ritorna la lista vuota
 */
list crea_lista_vuota();

/**
 * Crea lista con un intero
 *
 * @param x elemento (intero) della lista
 * @return ritorna la lista
 */
list crea_lista(int x);

/**
 * Stampa la lista
 *
 * @param l lista
 */
void stampa(list l);

/**
 * Aggiunge in coda elemento alla lista
 *
 * @param l lista
 * @param x elemento da aggiungere
 *
 * @return ritorna la lista
 */
struct node* push_back(struct node *l, int x);

/**
 * Cerca all'interno della lista un intero
 *
 * @param l lista
 * @param x intero da trovare
 *
 * @return ritorna 1 se viene trovato l'elemento, altrimenti 0
 */
int schrodinger_list(list l, int x);

/**
 * Elimina la lista
 *
 * @param l lista da eliminare
 */
void free_lista(list l);

#endif /*CHECK_MOVE_C_LIST_H*/
