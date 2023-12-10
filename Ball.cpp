#include "Ball.h"


Ball::Ball(int x, int y, int speed_x, int speed_y, int radius, Color color) {
    this->x = x;
    this->y = y;
    this->speed_x = speed_x;
    this->speed_y = speed_y;
    this->radius = radius;
    this->color = color;
}

void Ball::draw() {
    DrawCircle(x, y, float(radius), color);
}

void Ball::update() {
    this->x += speed_x;
    this->y += speed_y;

    if (this->x <= 0 + this->radius || this->x >= GetScreenWidth() - this->radius) {
        speed_x *= -1;
    }
    if (this->y <= 0 + this->radius || this->y >= GetScreenHeight() - this->radius) {
        speed_y *= -1;
    }
}
