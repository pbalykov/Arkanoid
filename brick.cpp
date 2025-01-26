#include "brick.hpp"

#include <cstdlib>
#include <ctime>

Brick::Brick(int width, int height) : _brick(height * PERCENTAGE_FILL, std::vector<bool>(width, false)) {}

void Brick::generator() {
    std::srand(std::time(nullptr));
    for (size_t i = 0; i < _brick.size(); i++) {
        for (size_t j = 0; j < _brick[i].size(); j++) {
            int rand = std::rand() % 100;
            _brick[i][j] = rand <= 80 ? true : false;
        }
    }
}

const std::vector<std::vector<bool> >& Brick::getBrickArr() const {
    return _brick;
}

bool Brick::collision(int x, int y) const {
    if ( y >= _brick.size() || x >= _brick[y].size() ) {
        return false;
    }
    return _brick[y][x];
}

void Brick::delBrick(int x, int y) {
    if ( y >= _brick.size() || x >= _brick[y].size() ) {
        return ;
    }
    _brick[y][x] = false;
}
