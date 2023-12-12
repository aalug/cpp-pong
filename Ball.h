#ifndef PONG_BALL_H
#define PONG_BALL_H

#include <raylib.h>
#include <map>
#include <string>

class Ball {

    int m_x, m_y, m_speed_x, m_speed_y, m_radius;
    Color m_color{};

public:
    Ball(int x, int y, int speed_x, int speed_y, int radius, Color color);

    // getters
    [[nodiscard]] int x() const;

    [[nodiscard]] int y() const;

    [[nodiscard]] int speed_x() const;

    [[nodiscard]] int radius() const;

    // setters
    void set_speed_x(int speed_x);

    void set_speed_y(int speed_y);

    void set_color(Color color);

    /**
     * Draw a ball on the board.
     */
    void draw();


    /**
     * Update ball position.
     * @param score keeps the score.
     */
    void update(std::unordered_map<std::string, int> &score);

    /**
     * Reset ball position to the center of the board and
     * randomly choose direction to move.
     */
    void reset_position();
};


#endif //PONG_BALL_H
