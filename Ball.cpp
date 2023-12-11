#include "Ball.h"


Ball::Ball(int x, int y, int speed_x, int speed_y, int radius, Color color) {
    m_x = x;
    m_y = y;
    m_speed_x = speed_x;
    m_speed_y = speed_y;
    m_radius = radius;
    m_color = color;
}

// getters
int Ball::x() const {
    return m_x;
}

int Ball::y() const {
    return m_y;
}

int Ball::speed_x() const {
    return m_speed_x;
}

int Ball::radius() const {
    return m_radius;
}

// setters
void Ball::set_speed_x(int speed_x) {
    m_speed_x = speed_x;
}

void Ball::draw() {
    DrawCircle(m_x, m_y, float(m_radius), m_color);
}

void Ball::update() {
    m_x += m_speed_x;
    m_y += m_speed_y;

    if (m_x <= 0 + m_radius || m_x >= GetScreenWidth() - m_radius) {
        m_speed_x *= -1;
    }
    if (m_y <= 0 + m_radius || m_y >= GetScreenHeight() - m_radius) {
        m_speed_y *= -1;
    }
}
