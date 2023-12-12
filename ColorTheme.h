#ifndef PONG_COLORTHEME_H
#define PONG_COLORTHEME_H

#include <raylib.h>

class ColorTheme {
    Color m_background_left, m_background_right;
    Color m_paddle;
    Color m_ball;
    Color m_score;

public:
    ColorTheme(Color background_left,
               Color background_right,
               Color paddle,
               Color ball,
               Color score);

    // getters
    Color get_background_left();

    Color get_background_right();

    Color get_paddle();

    Color get_score();

    Color get_ball();
};


#endif //PONG_COLORTHEME_H
