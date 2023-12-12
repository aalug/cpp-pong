#include <raylib.h>
#include "Ball.h"
#include "Paddle.h"
#include "AutoPaddle.h"
#include "Menu.h"

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
    const int player_score_x_pos{3 * computer_score_x_pos - scores_font_size};
    const int score_y_pos{30};

    // menu
    const int header_font_size{80};
    const int subtitle_font_size{50};
    const Menu menu(screen_width, screen_height, header_font_size, subtitle_font_size, base_color, background_color);
    bool show_menu{true};
    bool show_welcome_menu{true};
    int difficulty_selector_position{};

    // difficulty levels
    std::map<int, std::map<std::string, int>> difficulty_levels;
    difficulty_levels[0] = {{"auto_paddle_speed",   6},
                            {"player_paddle_speed", 13},
                            {"ball_speed",          10}};  // Easy
    difficulty_levels[1] = {{"auto_paddle_speed",   9},
                            {"player_paddle_speed", 11},
                            {"ball_speed",          13}};  // Medium
    difficulty_levels[2] = {{"auto_paddle_speed",   10},
                            {"player_paddle_speed", 10},
                            {"ball_speed",          15}};  // Hard


    // create a ball object
    // for now, speed is 0, after choosing difficulty level it will change
    // to an appropriate value
    Ball ball(screen_width / 2, screen_height / 2, 0, 0, ball_radius, base_color);

    // create paddles
    int y_pos{screen_height / 2 - paddle_height / 2};
    int distance_from_border{15};

    // player's paddle
    int player_paddle_speed{difficulty_levels[difficulty_selector_position]["player_paddle_speed"]};
    int x_pos{screen_width - distance_from_border - paddle_width};
    Paddle player_paddle(x_pos, y_pos, paddle_width, paddle_height, player_paddle_speed, base_color);

    // paddle moved by a computer
    int auto_paddle_speed{difficulty_levels[difficulty_selector_position]["auto_paddle_speed"]};
    AutoPaddle auto_paddle(distance_from_border, y_pos, paddle_width, paddle_height, auto_paddle_speed, base_color);

    // score
    std::unordered_map<std::string, int> scores{
            {"player",   0},
            {"computer", 0}
    };

    // Initialize window
    InitWindow(screen_width, screen_height, title);
    SetTargetFPS(fps);

    while (!WindowShouldClose()) {
        BeginDrawing();

        // show manu
        if (show_menu) {
            if (show_welcome_menu) {
                menu.display_start_menu(show_welcome_menu);
            } else if (show_menu && !show_welcome_menu) {
                // difficulty_selector_position also represents difficulty level
                // if difficulty_selector_position == 0 then difficulty == easy
                // if difficulty_selector_position == 1 then difficulty == medium
                // if  difficulty_selector_position == 2 then difficulty == hard
                menu.display_choose_difficulty_menu(show_menu, difficulty_selector_position);

                // set ball speed based on chosen difficulty level
                int ball_speed{difficulty_levels[difficulty_selector_position]["ball_speed"]};
                ball.set_speed_x(ball_speed);
                ball.set_speed_y(ball_speed);

                // set paddle speeds based on chosen difficulty level
                player_paddle.set_speed(difficulty_levels[difficulty_selector_position]["player_paddle_speed"]);
                auto_paddle.set_speed(difficulty_levels[difficulty_selector_position]["auto_paddle_speed"]);
            }
        } else { // play the game
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
            DrawText(TextFormat("%i", scores["computer"]), computer_score_x_pos, score_y_pos, scores_font_size,
                     base_color);
            DrawText(TextFormat("%i", scores["player"]), player_score_x_pos, score_y_pos, scores_font_size,
                     base_color);

            // separating line
            DrawLine(screen_width / 2, 0, screen_width / 2, screen_height, base_color);
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
