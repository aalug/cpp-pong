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

void Menu::display_menu(const std::string &menu_title, const std::vector<std::string> &options, bool &show_menu,
                        int &selector_position) const {
    // Clear the background
    ClearBackground(m_background_color);

    const int x_position{m_screen_width / 2 - 90};
    const int num_options = static_cast<int>(options.size());

    // Draw welcome text
    DrawText(menu_title.c_str(), m_screen_width / 2 - 350, 100, m_header_font_size, m_color);

    // Draw menu options
    for (int i = 0; i < num_options; ++i) {
        DrawText(options[i].c_str(), x_position, 300 + i * 100, m_subtitle_font_size, m_color);
    }

    // Draw triangle to show which option is selected
    Vector2 point_1{static_cast<float>(x_position - 80), static_cast<float>(300 + selector_position * 100 + 8)};
    Vector2 point_2{static_cast<float>(x_position - 40), static_cast<float>(300 + selector_position * 100 + 23)};
    Vector2 point_3{static_cast<float>(x_position - 80), static_cast<float>(300 + selector_position * 100 + 38)};
    DrawTriangle(point_3, point_2, point_1, m_color);

    // draw movement instructions
    const char *instructions[4]{"USE: ",
                                "UP and DOWN arrows to move",
                                "SPACE to confirm your choice",
                                "ESC to exit"};

    int pos_m{4};
    for (auto instruction: instructions) {
        DrawText(instruction, 30, m_screen_height - (pos_m * 35), 30, m_color);
        pos_m--;
    }

    // Handle user input
    if (IsKeyPressed(KEY_SPACE)) {
        show_menu = false;
    } else if (IsKeyPressed(KEY_DOWN)) {
        // Move down, and wrap around if necessary
        selector_position = (selector_position + 1) % num_options;
    } else if (IsKeyPressed(KEY_UP)) {
        // Move up, and wrap around if necessary
        selector_position = (selector_position - 1 + num_options) % num_options;
    }
}

void Menu::display_choose_difficulty_menu(bool &show_menu, int &selector_position) const {
    const std::vector<std::string> difficulty_options{"Easy", "Medium", "Hard"};
    display_menu("Choose difficulty", difficulty_options, show_menu, selector_position);
}

void Menu::display_choose_color_theme_menu(bool &show_menu, int &selector_position) const {
    const std::vector<std::string> color_theme_options{"Classic", "Dark blue", "Grey", "Colorful"};
    display_menu("Choose color theme", color_theme_options, show_menu, selector_position);
}




