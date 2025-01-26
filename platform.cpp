#include "platform.hpp"

Platform::Platform(int width, int height, int y) :
    _x(width / 2 - PLATFORM_WIDTH / 2), _y(y), 
    _width(width), _height(height) {}

void Platform::leftShift() {
    if ( _x - STEP >= 0 )
        _x -= STEP;
}

void Platform::rightShift() {
    if ( _x + PLATFORM_WIDTH + STEP <= _width ) 
        _x += STEP;
}

bool Platform::collision(int x, int y) const {
    return _y == y && ( _x <= x && x < _x + PLATFORM_WIDTH);
}

int Platform::getX() const {
    return _x;
}

int Platform::getY() const {
    return _y;
}

int Platform::getSize() const {
    return PLATFORM_WIDTH;
}
