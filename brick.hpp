#ifndef BRICK_HPP
#define BRICK_HPP

#include <vector>

//#include "bonuses.hpp"

class Brick {
static constexpr float PERCENTAGE_FILL = 0.25;
public:
    Brick(int width, int height);
    void generator();
    
    const std::vector<std::vector<bool> >& getBrickArr() const;

    bool collision(int x, int y) const;

    void delBrick(int x, int y);



private:
    std::vector<std::vector<bool> > _brick; //все болки сатические
    std::vector<std::pair<int, int> > _fallingBrick; //падающий блок
};

#endif

