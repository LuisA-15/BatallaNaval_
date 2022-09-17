void Gameplay(PLAYER *jugador, PLAYER *cpu, int size);
void CheckForWin(PLAYER *p, char *gameFlag, char cpuFlag);
void PlayerAttack(PLAYER *cpu, int size);
void CPUAttack(PLAYER *jugador, int size);
void CheckNaveState(PLAYER *jugador, CELDA *pos, int size);

void Gameplay(PLAYER *jugador, PLAYER *cpu, int size) {
    srand(time(0));
    char playerTurn = rand() % 2; // 0 player turn; 1 cpu turn
    PLAYER *p; // Player on turn
    char gameFlag = 0; // 0: Nobody's won 1: Player won 2: CPU won

    while(!gameFlag) {
        switch (playerTurn) {
            case 0:
                PlayerAttack(cpu, size);
                p = jugador;
                break;
            case 1:
                CPUAttack(jugador, size);
                p = cpu;
                break;
        }
        CheckForWin(p, &gameFlag, playerTurn);
        playerTurn = (playerTurn + 1) % 2;
    }
}

void CheckForWin(PLAYER *p, char *gameFlag, char cpuFlag) {
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

    CELDA *pos = cpu->board;
    pos += (y * size) + x;

    if (pos->state) {
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

    CELDA *pos = jugador->board;
    pos += (y * size) + x;

    if (pos->state) {
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
    if (naveSunk)
        (jugador->naves + pos->id - 1)->state = 1;
}