// Print Given Game State :
#include "structures.c"

int graphic(struct game g) {

    const int screenWidth = 800;
    const int screenHeight = 800;
    const int PlayerSize = screenWidth / g.size;

    InitWindow(screenWidth, screenHeight, "Quoridor");

    Vector2 Player1 = {g.player1Pos.y * PlayerSize + PlayerSize / 2, g.player1Pos.x * PlayerSize + PlayerSize / 2};
    Vector2 Player2 = {g.player2Pos.y * PlayerSize + PlayerSize / 2, g.player2Pos.x * PlayerSize + PlayerSize / 2};

    while (!WindowShouldClose()) {

        BeginDrawing();

            ClearBackground(RAYWHITE);

            // Print Board :
            Rectangle boardCell = {0, 0, PlayerSize, PlayerSize};

            for (int i = 0; i < g.size; i++) {
                boardCell.x = 0;
                for (int j = 0; j < g.size; j++) {
                    DrawRectangleLinesEx(boardCell, 1, LIGHTGRAY);
                    boardCell.x += PlayerSize;
                }
                boardCell.y += PlayerSize;
            }

            // Print Players :
            DrawCircleV(Player1, 5 * PlayerSize / 12, ColorAlpha(MAROON, 0.3));
            DrawCircleV(Player2, 5 * PlayerSize / 12, ColorAlpha(DARKGREEN, 0.3));

            // Print Player 1 walls :
            for (int i = 0; i < g.player1WallNo; i++) {
                Vector2 wallStartPoint = {g.player1WallList[i].y * PlayerSize, g.player1WallList[i].x * PlayerSize};
                Vector2 wallEndPoint = wallStartPoint;
                if (g.player1WallList[i].dir == 'V' || g.player1WallList[i].dir == 'v')
                    wallEndPoint.y += 2 * PlayerSize;
                else
                    wallEndPoint.x += 2 * PlayerSize;
                DrawLineEx(wallStartPoint, wallEndPoint, PlayerSize / 8, ColorAlpha(GRAY, 0.7));
            }

            //Print Player 2 walls :
            for (int i = 0; i < g.player2WallNo; i++) {
                Vector2 wallStartPoint = {g.player2WallList[i].y * PlayerSize, g.player2WallList[i].x * PlayerSize};
                Vector2 wallEndPoint = wallStartPoint;
                if (g.player2WallList[i].dir == 'V' || g.player2WallList[i].dir == 'v')
                    wallEndPoint.y += 2 * PlayerSize;
                else
                    wallEndPoint.x += 2 * PlayerSize;
                DrawLineEx(wallStartPoint, wallEndPoint, PlayerSize / 8, ColorAlpha(GRAY, 0.7));
            }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}