void createBoard(CELDA *board, int size);
char checkSpace(int orientation, int posx, int posy, int size, int nave, CELDA [][size]);
void fillSpace(int orientation, int posx, int posy, int size, int nave, int id, CELDA *board);

void createBoard(CELDA *board, int size) {
    int filled = 0;
    int limit = size * size * 0.3;
    int id = 1;

    int upper = PORTAVIONES + 1;
    int lower = LANCHA + 1;

    srand(time(0));
    while (filled <= limit - (size * size * 0.05)) {
        int nave = (rand() % (upper - lower + 1)) + lower;
        int posx = (rand() % 10);
        int posy = (rand() % 10);
        int orientation = (rand() % 4);
        char validPos;

        validPos = checkSpace(orientation, posx, posy, size, nave, board);

        if (validPos) {
            fillSpace(orientation, posx, posy, size, nave, id, board);
            filled += nave;
            id++;
        }
    }
}

char checkSpace(int orientation, int posx, int posy, int size, int nave, CELDA board[][size]) {
    char valid = 1;
    CELDA *pos = board;
    switch (orientation) {
        case ARRIBA:
            pos += (posx * size) + posy;
            for (int i = 0; i < nave; i++) {
                posx--;
                if((pos - (i * 10))->id != 0) {
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
                if((pos + (i * 10))->id != 0) {
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

void fillSpace(int orientation, int posx, int posy, int size, int nave, int id, CELDA *board) {
    CELDA *pos = board;
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
}