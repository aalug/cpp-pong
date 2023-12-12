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

    // getters
    [[nodiscard]] int x() const;

    [[nodiscard]]int y() const;

    [[nodiscard]] int width() const;

    [[nodiscard]] int height() const;

    [[nodiscard]]int speed() const;

    // setters
    void set_speed(int speed);

    void draw() const;

    void update();
};

#endif //PONG_PADDLE_H
