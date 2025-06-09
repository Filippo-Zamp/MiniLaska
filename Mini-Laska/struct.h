/**
* @file struct.h
* @author Filippo, Aresù e Dumitru
* @brief Struct delle pedine
*
*/

#ifndef PROGETTO_MINILASKA_STRUCT_H
#define PROGETTO_MINILASKA_STRUCT_H

typedef struct piece{
    char color[3]; /*EMPTY, WHITE, BLACK, NULL(celle illegali)*/
    int height;
    int go_back[3];
} piece_t;

#endif /*PROGETTO_MINILASKA_STRUCT_H*/
