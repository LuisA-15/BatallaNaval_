typedef struct celda_struct {
    int state;
    int id;
    int impact;
} CELDA;

typedef struct nave_struct {
    int type;
    int state;
    char orientation;
} NAVE;

typedef struct player_struct {
    CELDA board[100][100];
    NAVE naves[100];
    int naveCount;
} PLAYER;

enum naves {
    LANCHA,
    CRUCERO,
    SUBMARINO,
    BUQUE,
    PORTAVIONES
};

enum orientation {
    ARRIBA,
    DERECHA,
    ABAJO,
    IZQUIERDA
};