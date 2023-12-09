#ifndef PONG_BALL_H
#define PONG_BALL_H

#include <raylib.h>

class Ball {

    int x, y, speed_x, speed_y;
    float radius;
    Color color{};

public:
    Ball(int x, int y, int speed_x, int speed_y, float radius, Color color);
    void draw();
    void update();

};


#endif //PONG_BALL_H
