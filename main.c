// PHASE ONE - Quoridor Project - 2024
#include <stdio.h>
#include "raylib.h"
#include "graphic.c"

struct game getGame() {
    struct game g;

    // Read Size Of The Board :
    scanf("%d", &g.size);

    // Read Players' Positions :
    scanf("%d%d", &g.player1Pos.x, &g.player1Pos.y); g.player1Pos.x--, g.player1Pos.y--;
    scanf("%d%d", &g.player2Pos.x, &g.player2Pos.y); g.player2Pos.x--, g.player2Pos.y--;

    // Read Player 1 Walls :
    scanf("%d", &g.player1WallNo);
    for (int i = 0; i < g.player1WallNo; i++) {
        scanf(" %c", &g.player1WallList[i].dir);
        scanf("%d%d", &g.player1WallList[i].x, &g.player1WallList[i].y);
        g.player1WallList[i].x--, g.player1WallList[i].y--;
    }

    // Read Player 2 Walls :
    scanf("%d", &g.player2WallNo);
    for (int i = 0; i < g.player2WallNo; i++) {
        scanf(" %c", &g.player2WallList[i].dir);
        scanf("%d%d", &g.player2WallList[i].x, &g.player2WallList[i].y);
        g.player2WallList[i].x--, g.player2WallList[i].y--;
    }

    return g;
}

int main() {
    struct game gameState;
    gameState = getGame();
    graphic(gameState);
}