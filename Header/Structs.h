typedef struct celda_struct {
    int state;
    int id;
    int impact;
} CELDA;

typedef struct nave_struct {
    char *type;
    char orientation;
    int state;
} NAVE;

typedef struct player_struct {
    CELDA board[10][10];
    NAVE naves[35];
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