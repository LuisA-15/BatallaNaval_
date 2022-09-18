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
    int size = 10;
    printf("A. Modificar dimension del tablero\n");
    printf("B. Seleccionar modo de juego\n\ta. Didactico\n\tb. Facil\n");
    printf("C. Iniciar juego\n");
    printf("D. Salir\n");
    scanf("%c", &opcion);

    switch(opcion){
        case 'a':
        case 'A':
            printf("\nIngrese la dimension de la que desea su tablero: ");
            scanf("%d", &size);
            break;
        case 'b':
        case 'B':
            printf("\n\ta. Didactico\n\tb. Facil\n");
            scanf("%c", &opcion2);
            switch(opcion2){
                case 'a':break;
                case 'b':break;
                default:
                    printf("Opcion invalida\n");
                    break;
            }
            break;
        case 'c':
        case 'C':
            createBoard(&jugador, size);
            createBoard(&cpu, size);
            Gameplay(&jugador, &cpu, size);
            break;
        case 'd':
        case 'D':break;
    }
    return 0;
}

