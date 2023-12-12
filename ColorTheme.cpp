#include "ColorTheme.h"


ColorTheme::ColorTheme(Color background_left, Color background_right, Color paddle, Color ball, Color score) :
        m_background_left(background_left), m_background_right(background_right), m_paddle(paddle), m_ball(ball),
        m_score(score) {};

Color ColorTheme::get_background_left() {
    return m_background_left;
}

Color ColorTheme::get_background_right() {
    return m_background_right;
}

Color ColorTheme::get_paddle() {
    return m_paddle;
}

Color ColorTheme::get_score() {
    return m_score;
}

Color ColorTheme::get_ball() {
    return m_ball;
}
