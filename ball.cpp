#include "ball.hpp"

#include <cstdlib>

Ball::Ball(int width, int height, int x, int y) 
    : _x(x), _y(y), _width(width), _height(height), 
    _x_step(X_STEP), _y_step(-Y_STEP) {}


bool Ball::step(Brick& brick, Platform& platform) {
    _x += _x_step;
    _y += _y_step;

    if ( brick.collision(_x, _y) || platform.collision(_x, _y) ) {
        _x_step = std::rand() % 2 ? -X_STEP : X_STEP;
        _y_step = -_y_step;
        return true;
    }
    if ( _x + _x_step >= _width || _x <= 0 ) {
        _x_step = -_x_step;
    }
    if ( _y  >= _height || _y <= 0 ) {
        _y_step = - _y_step;
    }
    return false;
}


int Ball::getX() const {
    return _x;
}

int Ball::getY() const {
    return _y;
}
