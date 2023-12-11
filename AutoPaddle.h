#ifndef PONG_AUTOPADDLE_H
#define PONG_AUTOPADDLE_H

#include "Paddle.h"

class AutoPaddle : public Paddle {

public:
    AutoPaddle(int x, int y, int width, int height, int speed, Color color);

    void update(int ball_y);
};


#endif //PONG_AUTOPADDLE_H
