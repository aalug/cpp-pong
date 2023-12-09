#include <raylib.h>

int main() {

    const int screen_width{1280};
    const int screen_height{800};
    const char *title{"Pong"};
    const int fps{60};
    const int ball_radius{25};
    const Color base_color{WHITE};
    const int paddle_width{30};
    const int paddle_height{150};

    InitWindow(screen_width, screen_height, title);
    SetTargetFPS(fps);

    while (!WindowShouldClose()) {
        BeginDrawing();

        // create a ball
        DrawCircle(screen_width / 2, screen_height / 2, ball_radius, base_color);

        // create paddles
        int y_pos {screen_height / 2 - paddle_height / 2};
        int distance_from_border {15};

        // paddle 1
        DrawRectangle(distance_from_border, y_pos, paddle_width, paddle_height, base_color);

        // paddle 2
        int x_pos{screen_width - distance_from_border - paddle_width};
        DrawRectangle(x_pos, y_pos, paddle_width, paddle_height, base_color);

        // separating line
        DrawLine(screen_width/2, 0, screen_width/2, screen_height, base_color);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
