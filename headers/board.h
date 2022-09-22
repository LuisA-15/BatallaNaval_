#ifndef BOARD_H
#define BOARD_H

#include "structs.h"

void createBoard(PLAYER *jugador, int size);
void initBoard(CELDA *board, int size);
char checkSpace(int orientation, int posx, int posy, int size, int nave, CELDA *board);
void fillSpace(int orientation, int posx, int posy, int size, int nave, int id, PLAYER *jugador);
void printBoard(PLAYER *jugador, int size);

#endif
