#ifndef PONG_MENU_H
#define PONG_MENU_H

#include <raylib.h>
#include <string>

class Menu {

private:
    int m_screen_width, m_screen_height;
    int m_header_font_size, m_subtitle_font_size;
    Color m_color, m_background_color;

public:
    Menu(int screen_width, int screen_height, int header_font_size, int subtitle_font_size, Color color,
         Color background_color);

    /**
     * Helper function for displaying general menu.
     * Used by other display_menu type functions for
     * improving code quality.
     * @param menu_title
     * @param options
     * @param show_menu
     * @param selector_position
     */
    void display_menu(const std::string &menu_title, const std::vector<std::string> &options, bool &show_menu,
                      int &selector_position) const;

    /**
    *  Draw a menu that should be displayed
    *  at the start of the application.
    * @param show_menu reference to a value based on
    * which menu will or will not be displayed.
    */
    void display_start_menu(bool &show_menu) const;


    /**
    * Draw a menu that will allow to choose a difficulty level.
    * @param show_menu reference to a value based on
    * which menu will or will not be displayed.
    * @param selector_position reference to an int that
    * represents difficulty level outside of the function,
    * and inside a position of graphical selector.
    */
    void display_choose_difficulty_menu(bool &show_menu, int &selector_position) const;

    /**
    * Draw a menu that will allow to choose color theme.
    * @param show_menu reference to a value based on
    * which menu will or will not be displayed.
    * @param selector_position reference to an int that
    * represents color themes outside of the function,
    * and inside a position of graphical selector.
    */
    void display_choose_color_theme_menu(bool &show_menu, int &selector_position) const;
};

#endif //PONG_MENU_H
