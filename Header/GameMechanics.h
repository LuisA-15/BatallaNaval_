void Gameplay(PLAYER *jugador, PLAYER *cpu, int size, int gameMode);
void CheckForWin(PLAYER *p, char *gameFlag, char cpuFlag);
void PlayerAttack(PLAYER *cpu, int size);
void CPUAttack(PLAYER *jugador, int size);
void CheckNaveState(PLAYER *jugador, CELDA *pos, int size);
void sinkShip(NAVE *nave, CELDA *pos, int size);
int convertCoordinates(int y, int size);
void PrintWin(int p);

void Gameplay(PLAYER *jugador, PLAYER *cpu, int size, int gameMode) {
    srand(time(0));
    char playerTurn = rand() % 2;   // 0: player turn 1: cpu turn
    PLAYER *p;                      // Player not on turn
    char gameFlag = 0;              // 0: Nobody's won 1: Player won 2: CPU won

    while(!gameFlag) {
        switch (playerTurn) {
          case 0:
                if(gameMode == 1){
                    printf("CPU\n");
                    printBoard(cpu,size);
                }
                printf("Jugador\n");
                printBoard(jugador, size);
                PlayerAttack(cpu, size);
                p = cpu;
                break;
            case 1:
                CPUAttack(jugador, size);
                p = jugador;
                break;
        }
        CheckForWin(p, &gameFlag, playerTurn);
        playerTurn = (playerTurn + 1) % 2;
    }
    PrintWin(gameFlag);
}

void CheckForWin(PLAYER *p, char *gameFlag, char cpuFlag) {
    /*
     * Checks if all ships from the player not on turn have sunk
     */
    char playerWon = 1;
    if (cpuFlag)
        playerWon = 2;

    NAVE *current = p->naves;
    for (int i = 0; i < p->naveCount; i++) {
        if (!current->state) {
            playerWon = 0;
            break;
        }
        current++;
    }
    *gameFlag = playerWon;
}

void PlayerAttack(PLAYER *cpu, int size) {
    int x;
    int y;
    printf("Tu turno\n");
    do {
        printf("Escriba coordenada x: ");
        scanf("%d", &x);
        printf("\n");
    } while (x < 0 || x >= size);
    do {
        printf("Escriba coordenada y: ");
        scanf("%d", &y);
        printf("\n");
    } while (y < 0 || y >= size);
    y = convertCoordinates(y, size);
    CELDA *pos = *cpu->board;
    pos += (y * size) + x;

    if (pos->state && !pos->impact) {
        pos->impact = 1;
        printf("Atinaste a una nave!\n");
        CheckNaveState(cpu, pos, size);
    } else {
        printf("Fallaste!\n");
    }
}

void CPUAttack(PLAYER *jugador, int size) {
    srand(time(0));
    int x = rand() % size;
    int y = rand() % size;
    y = convertCoordinates(y, size);

    printf("Turno de CPU\n");
    CELDA *pos = *jugador->board;
    pos += (y * size) + x;

    if (pos->state && !pos->impact) {
        pos->impact = 1;
        printf("Te atacaron una nave!\n");
        CheckNaveState(jugador, pos, size);
    } else {
        printf("CPU fallo!\n");
    }
}

void CheckNaveState(PLAYER *jugador, CELDA *pos, int size) {
    NAVE *current = jugador->naves + pos->id - 1;
    char naveSunk = 1;
    switch (current->orientation) {
        case ARRIBA:
        case ABAJO:
            for (int i = 0; i < current->type; i++) {
                if (pos->id == (pos + (i * size))->id) {
                    if (!(pos + (i * size))->impact) {
                        naveSunk = 0;
                        break;
                    }
                }
                if (pos->id == (pos - (i * size))->id) {
                    if (!(pos - (i * size))->impact) {
                        naveSunk = 0;
                        break;
                    }
                }
            }
            break;
        case DERECHA:
        case IZQUIERDA:
            for (int i = 0; i < current->type; i++) {
                if (pos->id == (pos + i)->id) {
                    if (!(pos + i)->impact) {
                        naveSunk = 0;
                        break;
                    }
                }
                if (pos->id == (pos - i)->id) {
                    if (!(pos - i)->impact) {
                        naveSunk = 0;
                        break;
                    }
                }
            }
            break;
    }
    if (naveSunk){
        (jugador->naves + pos->id - 1)->state = 1;
        sinkShip(current,pos,size);
    }
}

void sinkShip(NAVE *nave, CELDA *pos, int size){
    /*
     * Disappear ship from board when all its parts have received impact
     */
    int id = pos->id;
    switch (nave->orientation) {
        case ARRIBA:
        case ABAJO:
            for (int i = 0; i < nave->type; i++) {
                if (id == (pos + (i * size))->id) {
                    (pos + (i * size))->id = 0;
                }
                if (id == (pos - (i * size))->id) {
                    (pos - (i * size))->id = 0;
                }
            }
            break;
        case DERECHA:
        case IZQUIERDA:
            for (int i = 0; i < nave->type; i++) {
                if (id == (pos + i)->id) {
                    (pos + i)->id = 0;
                }
                if (id == (pos - i)->id) {
                    (pos - i)->id = 0;
                }
            }
            break;
    }
}

int convertCoordinates(int y, int size) {
    /*
     * Convert given y coordinates to adjust board origin from the top left corner to the bottom left corner
     */
    int newY;
    newY = -y + (size - 1);
    return newY;
}

void PrintWin(int p) {
    switch (p) {
        case 1: printf("\nGanaste!"); break;
        case 2: printf("\nCPU gano!"); break;
    }
}