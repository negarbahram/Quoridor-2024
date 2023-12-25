#include <raylib.h>

const int screenWidth = 800;
const int screenHeight = 800;

const int MaximumWallNo = 100;

void MoveWall() {

}

int main() {

    InitWindow(screenWidth, screenHeight, "Quoridor");

    // چیزهایی که قراره ورودی این فایل باشه :
    int n = 10, wallNoOfPlayer1 = 8, wallNoOfPlayer2 = 8; // ابعاد جدول و تعداد دیوارها به ازای هر بازیکن
    const int PlayerSize = screenWidth / n; // سایز هر خونه بر اساس اندازه صفحه و ابعاد حدول
    Vector2 Player1 = {(n / 2) * PlayerSize + PlayerSize / 2, PlayerSize / 2}; // جایگاه بازیکن اول
    Vector2 Player2 = {(n / 2) * PlayerSize + PlayerSize / 2, (n - 1) * PlayerSize + PlayerSize / 2}; // جایگاه بازیکن دوم

    Vector2 wallStartPoint[MaximumWallNo], wallEndPoint[MaximumWallNo]; // دیوار های بازیکن اول و دوم مختصات
    // برای گرفتن جایگاه دیوارها از حلقه زیر استفاده میکنیم :
/*    for (int i = 0; i < wallNoOfPlayer1 + wallNoOfPlayer2; i++)
        wallStartPoint[i] = {0, PlayerSize},  wallEndPoint[i] = {2 * PlayerSize, PlayerSize};
    */
    // فعلن فرض میکنیم یدونه دیوار داریم :
    wallStartPoint[0].x = 0, wallStartPoint[0].y = PlayerSize;
    wallEndPoint[0].x = 2 * PlayerSize, wallEndPoint[0].y = PlayerSize;
    // پایان ورودی ها

    SetTargetFPS(10); // سرعت شاتر

    while (!WindowShouldClose()) {

        //بهتره این کارهایی که کامنت کردم رو تو main انجام بدیم و صرفن چاپ یک برد رو بسپاریم به این فایل
        // اسمش رو هم از graphic به print تغییر بدیم و کارش فقط چاپ یک برد و دیوار ها و مهرهها باشه
        /*
        DrawCircleV(Player1, PlayerSize / 2, RED);
        DrawCircleV(Player2, PlayerSize / 2, BLUE);

        int sw = 0;

        if (IsKeyDown(KEY_SPACE)) {
            if (IsKeyDown(KEY_UP)) wallStartPoint.y -= PlayerSize, wallEndPoint.y -= PlayerSize;
            if (IsKeyDown(KEY_DOWN)) s.y += PlayerSize, e.y += PlayerSize;
            if (IsKeyDown(KEY_RIGHT)) s.x += PlayerSize, e.x += PlayerSize;
            if (IsKeyDown(KEY_LEFT)) s.x -= PlayerSize, e.x -= PlayerSize;
            if (IsKeyDown(KEY_SPACE)) {
                if (s.x != e.x) s.x += PlayerSize, s.y += PlayerSize, e.x -= PlayerSize, e.y -= PlayerSize;
                else s.x -= PlayerSize, s.y -= PlayerSize, e.x += PlayerSize, e.y += PlayerSize;
            }
        }
        else {
            if (! sw) {
                if (IsKeyDown(KEY_UP)) Player1.y -= PlayerSize;
                if (IsKeyDown(KEY_DOWN)) Player1.y += PlayerSize;
                if (IsKeyDown(KEY_RIGHT)) Player1.x += PlayerSize;
                if (IsKeyDown(KEY_LEFT)) Player1.x -= PlayerSize;
           }
            else {
                if (IsKeyDown(KEY_UP)) Player2.y -= PlayerSize;
                if (IsKeyDown(KEY_DOWN)) Player2.y += PlayerSize;
                if (IsKeyDown(KEY_RIGHT)) Player2.x += PlayerSize;
                if (IsKeyDown(KEY_LEFT)) Player2.x -= PlayerSize;
            }
        }
        */
        BeginDrawing();

            ClearBackground(RAYWHITE);

            // چاپ جدول :
            Rectangle board = {0, 0, PlayerSize, PlayerSize};

            for (int i = 0; i < n; i++) {
                board.x = 0;
                for (int j = 0; j < n; j++) {
                    DrawRectangleLinesEx(board, 1, LIGHTGRAY);
                    board.x += PlayerSize;
                }
                board.y += PlayerSize;
            }

            //چاپ بازیکن ها :
            DrawCircleV(Player1, PlayerSize / 2, RED);
            DrawCircleV(Player2, PlayerSize / 2, BLUE);

            // برای چاپ  دیوارها از حلقه زیر استفاده میکنیم :
/*        for (int i = 0; i < wallNoOfPlayer1 + wallNoOfPlayer2; i++)
                DrawLineEx(wallStartPoint[i], wallEndPoint[i], 10, GRAY);
        */
        //فعلن فرض میکنیم یه دیوار داریم :
            DrawLineEx(wallStartPoint[0], wallEndPoint[0], 10, GRAY);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}