#ifndef CACTUS_H
#define CACTUS_H

#include <SDL2/SDL.h>
#include "Texture.h"
#include "Obstacle.h"

class Cactus : public Obstacle
{
private:
    SDL_Rect frames[3] = {{360, 0, 73, 50}, {230, 0, 30, 38}, {335, 0, 25, 50}};

    const int type; // what type of cactus is this object
public:
    Cactus(int a, int b, int sw, int t, int width, int height) : Obstacle(a, b, sw, width, height), type(t) {}
    void draw(Texture &tex, SDL_Renderer *rd);
};

#endif // CACTUS_H
