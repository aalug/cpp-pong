#include <raylib.h>

int main() {

    const int screen_width = 1280;
    const int screen_height = 800;
    const char *title = "Pong";
    const int fps = 60;

    InitWindow(screen_width, screen_height, title);
    SetTargetFPS(fps);

    while (!WindowShouldClose()) {
        BeginDrawing();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
