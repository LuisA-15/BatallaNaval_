void createBoard(PLAYER *jugador, int size);
void initBoard(CELDA *board, int size);
char checkSpace(int orientation, int posx, int posy, int size, int nave, CELDA *board);
void fillSpace(int orientation, int posx, int posy, int size, int nave, int id, PLAYER *jugador);
void printBoard(PLAYER *jugador, int size);

void createBoard(PLAYER *jugador, int size) {
    CELDA *board = *jugador->board;
    initBoard(*jugador->board, size);
    int filled = 0;
    int limit = size * size * 0.3;
    int id = 1;

    int upper = PORTAVIONES + 1;
    int lower = LANCHA + 1;

    srand((time(0) + rand()));
    srand((rand() * rand()) / rand());
    while (filled <= limit - (size * size * 0.05)) {
        /*
         * Define random characteristics for a ship
         */
        int nave = (rand() % (upper - lower + 1)) + lower;
        int posx = (rand() % size);
        int posy = (rand() % size);
        int orientation = (rand() % 4);
        char validPos;

        validPos = checkSpace(orientation, posx, posy, size, nave, board);

        if (validPos) {
            fillSpace(orientation, posx, posy, size, nave, id, jugador);
            filled += nave;
            id++;
        }
    }
}

void initBoard(CELDA *board, int size) {
    CELDA *current = board;
    for (int i = 0; i < size * size; i++) {
        current->id = 0;
        current++;
    }
}

char checkSpace(int orientation, int posx, int posy, int size, int nave, CELDA *board) {
    /*
     * Checks if the ship fits on the board and does not collide with other ships
     * based on given orientation and intial position
     */
    char valid = 1;
    CELDA *pos = board;
    switch (orientation) {
        case ARRIBA:
            pos += (posx * size) + posy;
            for (int i = 0; i < nave; i++) {
                posx--;
                if((pos - (i * size))->id != 0) {
                    valid = 0;
                    break;
                }
            } break;
        case DERECHA:
            pos += (posx * size) + posy;
            for (int i = 0; i < nave; i++) {
                posy++;
                if((pos + i)->id != 0) {
                    valid = 0;
                    break;
                }
            } break;
        case ABAJO:
            pos += (posx * size) + posy;
            for (int i = 0; i < nave; i++) {
                posx++;
                if((pos + (i * size))->id != 0) {
                    valid = 0;
                    break;
                }
            } break;
        case IZQUIERDA:
            pos += (posx * size) + posy;
            for (int i = 0; i < nave; i++) {
                posy--;
                if((pos - i)->id != 0) {
                    valid = 0;
                    break;
                }
            } break;
    }
    if (posx < 0 || posx >= size) {
        valid = 0;
    }
    if (posy < 0 || posy >= size) {
        valid = 0;
    }
    return valid;
}

void fillSpace(int orientation, int posx, int posy, int size, int nave, int id, PLAYER *jugador) {
    CELDA *pos = *jugador->board;
    pos += (posx * size) + posy;
    int movement;
    switch (orientation) {
        case ARRIBA: movement = -size; break;
        case DERECHA: movement = 1; break;
        case ABAJO: movement = size; break;
        case IZQUIERDA: movement = -1; break;
    }
    for (int i = 0; i < nave; i++) {
        (pos + (i * movement))->id = id;
        (pos + (i * movement))->state = 1;
        (pos + (i * movement))->impact = 0;
    }
    (jugador->naves + id - 1)->state = 0;
    (jugador->naves + id - 1)->type = nave;
    (jugador->naves + id - 1)->orientation = orientation;
    jugador->naveCount = id;
}

void printBoard(PLAYER *jugador, int size) {
    CELDA *pos = *jugador->board;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (pos->id > 9) {
                if (pos->id && pos->impact) {
                    printf("X  ");
                } else {
                    printf("%d  ", pos->id);
                }
            } else {
                if (pos->id && pos->impact) {
                    printf("X   ");
                } else {
                    printf("%d   ", pos->id);
                }
            }
            pos++;
        }
        printf("\n");
    }
    printf("\n");
}