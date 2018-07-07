#ifndef GROUND_H
#define GROUND_H

#include <SDL2/SDL.h>
#include "Texture.h"

// for random
#include <stdlib.h>
#include <time.h>

// headers for colliders/obstacles
#include "Ptera.h"
#include "Cactus.h"
#include <vector>

class Ground
{
private:
    SDL_Rect sprite_ground_pos;
    SDL_Rect ground1;
    SDL_Rect ground2;
    SDL_Rect ground3;

    // used in obst. generation
    const int screen_width;
    const int screen_height;
    Texture &tex;
    SDL_Renderer *rd;

    std::vector<Ptera> pteras;
    std::vector<Cactus> cactus;

    const int move_speed = 10; // how fast the ground is moving
    int current_frame;

    void move_ground();
    void move_obstacles();
    void add_obstacle();
    void draw_obstacles();

public:
    Ground(int sh, int sw, int sprt, Texture &tex, SDL_Renderer *rd);
    void draw();
    void update(int cf);
    void move();

    bool obstacle_collision(SDL_Rect *pr);
};

#endif // GROUND_H
