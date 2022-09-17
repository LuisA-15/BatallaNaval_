void Gameplay(PLAYER *jugador, PLAYER *cpu);
void CheckForWin(PLAYER *p, char *gameFlag, char cpuFlag);
void PlayerAttack();
void CPUAttack();

void Gameplay(PLAYER *jugador, PLAYER *cpu) {
    srand(time(0));
    char playerTurn = rand() % 2;; // 0 player turn; 1 cpu turn
    PLAYER *p; // Player on turn
    char gameFlag = 0; // 0: Nobody's won 1: Player won 2: CPU won

    while(!gameFlag) {
        switch (playerTurn) {
            case 0:
                PlayerAttack();
                p = jugador;
                break;
            case 1:
                CPUAttack();
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