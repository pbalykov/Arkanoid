#ifndef PLATFORM_HPP
#define PLATFORM_HPP

class Platform {
    static constexpr int STEP = 1;
    static constexpr int PLATFORM_WIDTH = 3; 
public:
    Platform(int width, int height, int y);

    void leftShift();
    void rightShift();

    bool collision(int x, int y) const;

    int getX() const;
    int getY() const;
    int getSize() const;

    //колизию бонуса

private:
    int _x, _y;
    int _width, _height;
};

#endif
