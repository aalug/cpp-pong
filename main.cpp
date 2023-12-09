#include <raylib.h>
#include "Ball.h"

int main() {

    const int screen_width{1280};
    const int screen_height{800};
    const char *title{"Pong"};
    const int fps{60};
    const int ball_radius{25};
    const Color base_color{WHITE};
    const Color background_color{BLACK};
    const int paddle_width{30};
    const int paddle_height{150};

    InitWindow(screen_width, screen_height, title);
    SetTargetFPS(fps);

    // create a ball object
    int speed_x{10};
    int speed_y{10};
    Ball ball(screen_width / 2, screen_height / 2, speed_x, speed_y, ball_radius, base_color);

    while (!WindowShouldClose()) {
        BeginDrawing();

        // update ball position
        ball.update();

        // clear the background
        ClearBackground(background_color);

        // draw sa ball
        ball.draw();

        // create paddles
        int y_pos{screen_height / 2 - paddle_height / 2};
        int distance_from_border{15};

        // paddle 1
        DrawRectangle(distance_from_border, y_pos, paddle_width, paddle_height, base_color);

        // paddle 2
        int x_pos{screen_width - distance_from_border - paddle_width};
        DrawRectangle(x_pos, y_pos, paddle_width, paddle_height, base_color);

        // separating line
        DrawLine(screen_width / 2, 0, screen_width / 2, screen_height, base_color);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
