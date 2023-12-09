#include "Ball.h"


Ball::Ball(int x, int y, int speed_x, int speed_y, float radius, Color color) {
    this->x = x;
    this->y = y;
    this->speed_x = speed_x;
    this->speed_y = speed_y;
    this->radius = radius;
    this->color = color;
}

void Ball::draw() {
    DrawCircle(x, y, radius, color);
}

void Ball::update() {
    this->x += speed_x;
    this->y += speed_y;
}
