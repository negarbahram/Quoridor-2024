#include <raylib.h>

const int screenWidth = 800;
const int screenHeight = 800;

void MoveWall() {

}

int main() {

    InitWindow(screenWidth, screenHeight, "Quoridor");

    const int n = 10;
    const int PlayerSize = screenWidth / n;


    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        Rectangle board = {0, 0, PlayerSize, PlayerSize};

        for (int i = 0; i < n; i++) {
            board.x = 0;
            for (int j = 0; j < n; j++) {
                DrawRectangleLinesEx(board, 1, LIGHTGRAY);
                board.x += PlayerSize;
            }
            board.y += PlayerSize;
        }

       // for (int i = PlayerSize / 2)

        EndDrawing();
    }
    return 0;
}