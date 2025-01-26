#include "arkanoid.hpp"


Arkanoid::Arkanoid() : _brick(WIDTH, HEIGHT), 
    _ball(WIDTH, HEIGHT, START_BALL_X, START_BALL_Y), 
    _platform(WIDTH, HEIGHT, START_PLATFORM_Y)
{
    _brick.generator();       
}


bool Arkanoid::step() {
    if ( _ball.getY() >= HEIGHT ) {
        return true;
    }
    if ( _ball.step(_brick, _platform) )  { 
        _brick.delBrick(_ball.getX(), _ball.getY());
    }
    return false;
}

void Arkanoid::shiftPlatform(TYPE_STEP step) {
    switch ( step ) {
        case TYPE_STEP::left :
            _platform.leftShift();
            break;
        case TYPE_STEP::right :
            _platform.rightShift();
            break;
        default :
            break;
    }
}

std::vector<std::vector<int> > Arkanoid::getArr() const {
    std::vector<std::vector<int> > arr(HEIGHT, std::vector<int>(WIDTH));
    auto x = _brick.getBrickArr();
    for (int i = 0; i < x.size(); i++) {
        for (int j = 0; j < x[i].size(); j++) {
            arr[i][j] = x[i][j];
        }
    }
    if ( _ball.getY() < HEIGHT ) {
        arr[_ball.getY()][_ball.getX()] = 2;
    }
    int a = _platform.getY();
    int b = _platform.getX();
    for (int i = 0; i < _platform.getSize(); i++) {
        arr[a][b + i] = 3;
    }
    return arr;
}


/*#include <iostream>
#include <cstdlib>
#include <unistd.h>

int main() {
    std::system("clear");
    Arkanoid game;
    while ( true ) {
        std::system("clear");
        auto arr = game.getArr(); 
        for (int i = 0; i <  arr.size(); i++) {
            for (int j = 0; j < arr[i].size(); j++) 
                if ( arr[i][j] == 0 ) std::cout << "-";
                else  std::cout << arr[i][j] ;
            std::cout << " | " << std::endl;
        }
        game.step();
        usleep(50000);
    }
 
} */
