#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Structs.h"
#include "Board.h"
#include "GameMechanics.h"

int main() {
    PLAYER jugador;
    PLAYER cpu;

    char opcion, opcion2;
    int size;
    printf("A. Modificar dimension del tablero\n");
    printf("B. Seleccionar modo de juego\n\ta. Didactico\n\tb. Facil\n");
    printf("C. Iniciar juego\n");
    printf("D. Salir\n");
    scanf("%c ", &opcion);

    switch(opcion){
        case 'A':
            printf("\nIngrese la dimension de la que desea su tablero: ");
            scanf("%d", &size);
            break;
        case 'B':
            printf("\n\ta. Didactico\n\tb. Facil\n");
            scanf("%c ", &opcion2);
            switch(opcion2){
                case 'a':break;
                case 'b':break;
                default:
                    printf("Opcion invalida\n");
                    break;
            }
            break;
        case 'C':break;
        case 'D':break;
    }

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

