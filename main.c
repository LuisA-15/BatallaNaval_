#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Structs.h"
#include "Board.h"

int main() {
    PLAYER jugador;
    PLAYER cpu;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j <10; j++) {
            jugador.board[i][j].id = 0;
        }
    }
    createBoard(jugador.board, 10);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d\t", jugador.board[i][j].id);
        }
        printf("\n");
    }
    return 0;
}

