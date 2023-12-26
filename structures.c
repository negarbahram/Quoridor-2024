struct position {
    int x, y;
};

struct wall {
    char dir;
    int x, y;
};

struct game {
    int size;
    struct position player1Pos, player2Pos;
    int player1WallNo;
    int player2WallNo;
    struct wall player1WallList[100 + 10];
    struct wall player2WallList[100 + 10];
};
