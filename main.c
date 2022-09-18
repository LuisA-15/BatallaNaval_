#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Structs.h"
#include "Board.h"
#include "GameMechanics.h"

void printMenu();

int main() {
    PLAYER jugador;
    PLAYER cpu;

    char opcion, opcion2;
    int size = 10;

    printMenu();

    do {
        scanf(" %c", &opcion);
        if (opcion > 'F')
            opcion -= 32;
        switch(opcion){
            case 'A':
                printf("\nIngrese la dimension de la que desea su tablero: ");
                scanf("%d", &size);
                break;
            case 'B':
                printf("\n1. Didactico\n2. Facil\n");
                scanf(" %c", &opcion2);
                switch(opcion2){
                    case '1':break;
                    case '2':break;
                    default:
                        printf("Opcion invalida\n\n");
                        printMenu();
                        opcion = 0;
                        break;
                }
                break;
            case 'C':
                createBoard(&jugador, size);
                createBoard(&cpu, size);
                Gameplay(&jugador, &cpu, size);
                break;
            case 'D':break;
            default: printf("Opcion invalida\n\n"); break;
        }
    } while (opcion < 'A' || opcion > 'D');
    return 0;
}

void printMenu() {
    printf("A. Modificar dimension del tablero\n");
    printf("B. Seleccionar modo de juego\n");
    printf("C. Iniciar juego\n");
    printf("D. Salir\n");
}
