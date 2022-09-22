#ifndef MECHANICS_H
#define MECHANICS_H

#include "board.h"

void Gameplay(PLAYER *jugador, PLAYER *cpu, int size, int gameMode);
void CheckForWin(PLAYER *p, char *gameFlag, char cpuFlag);
void PlayerAttack(PLAYER *cpu, int size);
void CPUAttack(PLAYER *jugador, int size);
void CheckNaveState(PLAYER *jugador, CELDA *pos, int size);
void sinkShip(NAVE *nave, CELDA *pos, int size);
int convertCoordinates(int y, int size);
void PrintWin(int p);

#endif