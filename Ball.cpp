#include <string>
#include <map>
#include <random>
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

void Ball::set_speed_y(int speed_y) {
    m_speed_y = speed_y;
}

void Ball::set_color(Color color) {
    m_color = color;
}


void Ball::draw() {
    DrawCircle(m_x, m_y, float(m_radius), m_color);
}

void Ball::reset_position() {
    // set position to center
    m_x = GetScreenWidth() / 2;
    m_y = GetScreenHeight() / 2;

    // generate random direction
    int directions[2]{-1, 1};
    m_speed_x *= directions[GetRandomValue(0, 1)];
    m_speed_y *= directions[GetRandomValue(0, 1)];
}

void Ball::update(std::unordered_map<std::string, int> &score) {
    m_x += m_speed_x;
    m_y += m_speed_y;

    if (m_y <= 0 + m_radius || m_y >= GetScreenHeight() - m_radius) {
        m_speed_y *= -1;
    } else if (m_x <= 0 + m_radius) {
        // update score and move ball back to center
        score["player"]++;
        reset_position();

        // sleep for 1s
        WaitTime(1.0);
    } else if (m_x >= GetScreenWidth() - m_radius) {
        // update score and move ball back to center
        score["computer"]++;
        reset_position();

        // sleep for 2s
        WaitTime(1.0);
    }
}
