#include "AutoPaddle.h"
#include <raylib.h>


AutoPaddle::AutoPaddle(int x, int y, int width, int height, int speed, Color color) : Paddle(x, y, width, height, speed,
                                                                                             color) {};

void AutoPaddle::update(int ball_y) {
    if (y() + height() / 2 > ball_y) {
        m_y -= m_speed;
    } else if (y() + height() / 2 < ball_y) {
        m_y += m_speed;
    }
}
