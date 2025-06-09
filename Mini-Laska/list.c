/**
* @file list.c
* @author Filippo, Aresù e Dumitru
* @brief Funzioni per implementare le liste
*
*/

#include "list.h"
#include <stdio.h>
#include <stdlib.h>


/**
 * Crea lista vuota
 *
 * @return ritorna la lista vuota
 */
list crea_lista_vuota(){ /*crea lista vuota*/
    return NULL;
}

/**
 * Crea lista con un intero
 *
 * @param x elemento (intero) della lista
 * @return ritorna la lista
 */
list crea_lista(int x){ /*crea lista passandogli un dato*/
    list a = (list) malloc (sizeof (struct node));
    a->data=x;
    a->next=NULL;
    return a;
}

/**
 * Stampa la lista
 *
 * @param l lista
 */
void stampa(list l) {
    if(l==NULL)
        return;

    printf("%d-", l->data/7);
    printf("%d\n", l->data%7);

    stampa(l->next);
}

/**
 * Aggiunge in coda elemento alla lista
 *
 * @param l lista
 * @param x elemento da aggiungere
 *
 * @return ritorna la lista
 */
struct node* push_back(struct node *l, int x) {
    struct node *n = l;
    /* empty list */
    if (n==NULL)
        return crea_lista(x);

    /* get to the last element */
    while (n->next!=NULL)
        n = n->next;
    n->next = crea_lista(x);
    return l;
}

/**
 * Cerca all'interno della lista un intero
 *
 * @param l lista
 * @param x intero da trovare
 *
 * @return ritorna 1 se viene trovato l'elemento, altrimenti 0
 */
int schrodinger_list(list l, int x){

    while(l != NULL){
        if(l->data == x){
            return 1;
        }
        l = l->next;
    }

    return 0;
}

/**
 * Elimina la lista
 *
 * @param l lista da eliminare
 */
void free_lista(list l) { /*dealloca lista*/
    while (l!=NULL) {
        list next = l->next;
        free(l);
        l = next;
    }
}