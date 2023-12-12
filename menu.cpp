#include "Menu.h"
#include <raylib.h>


Menu::Menu(int screen_width, int screen_height, int header_font_size, int subtitle_font_size, Color color,
           Color background_color)
        : m_screen_width(screen_width), m_screen_height(screen_height),
          m_header_font_size(header_font_size), m_subtitle_font_size(subtitle_font_size), m_color(color),
          m_background_color(background_color) {}

void Menu::display_start_menu(bool &show_menu) const {
    if (IsKeyPressed(KEY_SPACE)) {
        show_menu = false;
    }
    const char *welcome_text{"Welcome to Pong!"};
    const char *play_text{"Press SPACE to start"};

    // draw welcome text
    DrawText(welcome_text, m_screen_width / 2 - 350, m_screen_height / 2 - 150, m_header_font_size, m_color);
    DrawText(play_text, m_screen_width / 2 - 300, m_screen_height / 2 - 50, m_subtitle_font_size, m_color);
}

void Menu::display_choose_difficulty_menu(bool &show_menu, int &selector_position) const {
    // clear the background
    ClearBackground(m_background_color);

    const int x_position{m_screen_width / 2 - 90};
    const int y_positions[]{300, 400, 500};
    const int num_difficulty_levels = 3;

    // draw welcome text
    DrawText("Choose difficulty", m_screen_width / 2 - 350, 100, m_header_font_size, m_color);
    DrawText("Easy", x_position, y_positions[0], m_subtitle_font_size, m_color);
    DrawText("Medium", x_position, y_positions[1], m_subtitle_font_size, m_color);
    DrawText("Hard", x_position, y_positions[2], m_subtitle_font_size, m_color);

    // draw triangle to show which level is selected
    Vector2 point_1{static_cast<float>(x_position - 80), static_cast<float>(y_positions[selector_position] + 8)};
    Vector2 point_2{static_cast<float>(x_position - 40), static_cast<float>(y_positions[selector_position] + 23)};
    Vector2 point_3{static_cast<float>(x_position - 80), static_cast<float>(y_positions[selector_position] + 38)};
    DrawTriangle(point_3, point_2, point_1, m_color);

    if (IsKeyPressed(KEY_SPACE)) {
        show_menu = false;
    } else if (IsKeyPressed(KEY_DOWN)) {
        // Move down, and wrap around if necessary
        selector_position = (selector_position + 1) % num_difficulty_levels;
    } else if (IsKeyPressed(KEY_UP)) {
        // Move up, and wrap around if necessary
        selector_position = (selector_position - 1 + num_difficulty_levels) % num_difficulty_levels;
    }
}


