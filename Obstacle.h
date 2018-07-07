#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <SDL2/SDL.h>

/*
    I've defined a base class because all obstacles will share some common
    things like:
            - they will move with the same speed
            - they will have methods that test if it is offscreen, to implement
              the movement
    and using inheritence will reduce the amount of code.
    A ptera, cactus IS A obstacle
*/
class Obstacle
{
protected:
    const int screen_width;
    const int move_speed = 10;
    const int w, h; // width and height of the obstacle
    int x, y; // position of the obstacle
public:
    Obstacle(int a, int b, int sw, int width, int height) : x(a), y(b), screen_width(sw), w(width), h(height) {}
    void move();
    bool is_offscreen();
    SDL_Rect get_bounding_box();
};

#endif // OBSTACLE_H
