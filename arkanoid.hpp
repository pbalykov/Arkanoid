#ifndef ARKANOID_HPP
#define ARKANOID_HPP


#include "ball.hpp"
#include "brick.hpp"
#include "platform.hpp"

class Arkanoid {  
    static constexpr int WIDTH = 19;
    static constexpr int HEIGHT = 24;
    static constexpr int START_BALL_Y = HEIGHT - 3;
    static constexpr int START_BALL_X = WIDTH / 2;
    static constexpr int START_PLATFORM_Y = HEIGHT - 2;

public:
    enum class TYPE_STEP {
        left = -1, right = 1
    };

    Arkanoid();
    
    bool step(); //шаг;
    
    bool isEnd(); //конец игры

    void shiftPlatform(TYPE_STEP step); 
                                        
    std::vector<std::vector<int> > getArr() const;

    
private:
    Brick _brick;
    Ball _ball;
    Platform _platform;
};


#endif
