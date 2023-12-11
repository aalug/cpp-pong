#include <raylib.h>
#include "Ball.h"
#include "Paddle.h"
#include "AutoPaddle.h"

int main() {

    // board
    const int screen_width{1280};
    const int screen_height{800};
    const char *title{"Pong"};
    const int fps{60};

    // colors
    const Color base_color{WHITE};
    const Color background_color{BLACK};

    // ball and paddles
    const int ball_radius{25};
    const int paddle_width{30};
    const int paddle_height{150};

    // score
    const int scores_font_size{70};
    const int computer_score_x_pos{screen_width / 4};
    const int player_score_x_post{3 * computer_score_x_pos - scores_font_size};
    const int score_y_pos{30};

    InitWindow(screen_width, screen_height, title);
    SetTargetFPS(fps);

    // create a ball object
    int speed_x{15};
    int speed_y{15};
    Ball ball(screen_width / 2, screen_height / 2, speed_x, speed_y, ball_radius, base_color);

    // create paddles
    int y_pos{screen_height / 2 - paddle_height / 2};
    int distance_from_border{15};
    int paddle_speed{10};

    // player's paddle
    int x_pos{screen_width - distance_from_border - paddle_width};
    Paddle player_paddle(x_pos, y_pos, paddle_width, paddle_height, paddle_speed, base_color);

    // paddle moved by a computer
    AutoPaddle auto_paddle(distance_from_border, y_pos, paddle_width, paddle_height, paddle_speed, base_color);

    // score
    std::unordered_map<std::string, int> scores{{"player",   0},
                                                {"computer", 0}};

    while (!WindowShouldClose()) {
        BeginDrawing();

        // update ball and paddle positions
        ball.update(scores);
        player_paddle.update();
        auto_paddle.update(ball.y());

        // check for collisions
        // first for player
        if (CheckCollisionCircleRec(Vector2{static_cast<float>(ball.x()),
                                            static_cast<float>(ball.y())},
                                    ball.radius(),
                                    Rectangle{
                                            static_cast<float>(player_paddle.x()),
                                            static_cast<float>(player_paddle.y()),
                                            static_cast<float>(player_paddle.width()),
                                            static_cast<float>(player_paddle.height())}) ||
            // for auto paddle
            (CheckCollisionCircleRec(Vector2{static_cast<float>(ball.x()),
                                             static_cast<float>(ball.y())},
                                     ball.radius(),
                                     Rectangle{
                                             static_cast<float>(auto_paddle.x()),
                                             static_cast<float>(auto_paddle.y()),
                                             static_cast<float>(auto_paddle.width()),
                                             static_cast<float>(auto_paddle.height())})
            )
                ) {
            // reverse the ball's speed in x direction
            // when it hits the paddle
            ball.set_speed_x(ball.speed_x() * -1);
        }


        // clear the background
        ClearBackground(background_color);

        // draw ball and paddles
        ball.draw();
        auto_paddle.draw();
        player_paddle.draw();

        // draw the score
        DrawText(TextFormat("%i", scores["computer"]), computer_score_x_pos, score_y_pos, scores_font_size, base_color);
        DrawText(TextFormat("%i", scores["player"]), player_score_x_post, score_y_pos, scores_font_size, base_color);

        // separating line
        DrawLine(screen_width / 2, 0, screen_width / 2, screen_height, base_color);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
