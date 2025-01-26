#ifndef BALL_HPP
#define BALL_HPP

#include "brick.hpp"
#include "platform.hpp" //потом добавить платформу

class Ball {
    static constexpr int X_STEP = 1;
    static constexpr int Y_STEP = 1;

public:
    Ball(int width, int height, int x, int y);

    bool step(Brick& brick, Platform& platform);
    
    int getX() const;
    int getY() const;

private:
    int _x, _y;
    int _width, _height;
    int _x_step, _y_step;
};


#endif
