#include "Paddle.h"
#include <raylib.h>


Paddle::Paddle(int x, int y, int width, int height, int speed, Color color) : m_x(x), m_y(y), m_width(width),
                                                                              m_height(height), m_speed(speed),
                                                                              m_color(color) {};

int Paddle::x() const { return m_x; }

int Paddle::y() const { return m_y; }

int Paddle::width() const { return m_width; }

int Paddle::height() const { return m_height; }

int Paddle::speed() const { return m_speed; }

void Paddle::set_speed(int speed) {
    m_speed = speed;
}

void Paddle::set_color(Color color) {
    m_color = color;
}

void Paddle::draw() const {
    DrawRectangle(this->m_x, this->m_y, m_width, m_height, m_color);
}

void Paddle::update() {
    if (IsKeyDown(KEY_UP) && this->m_y > 0) {
        this->m_y -= this->m_speed;
    } else if (IsKeyDown(KEY_DOWN) && this->m_y < GetScreenHeight() - this->m_height) {
        this->m_y += this->m_speed;
    }
}
