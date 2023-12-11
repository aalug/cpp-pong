#ifndef PONG_PADDLE_H
#define PONG_PADDLE_H

#include <raylib.h>


class Paddle {
private:
    int m_x, m_width, m_height;
    Color m_color;

protected:
    int m_y, m_speed;

public:
    Paddle(int x, int y, int width, int height, int speed, Color color);


    [[nodiscard]] int x() const;

    [[nodiscard]]int y() const;

    [[nodiscard]] int width() const;

    [[nodiscard]] int height() const;

    [[nodiscard]]int speed() const;

    void draw() const;

    void update();
};

#endif //PONG_PADDLE_H
