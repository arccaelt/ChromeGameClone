#ifndef PTERA_H
#define PTERA_H

#include <SDL2/SDL.h>
#include "Texture.h"
#include "Obstacle.h"

class Ptera : public Obstacle
{
private:
    SDL_Rect frames[2] = {{135, 0, 45, 50}, {180, 0, 45, 50}};

public:
    Ptera(int a, int b, int sw, int w, int h) : Obstacle(a, b, sw, w, h) {}
    void draw(Texture &tex, SDL_Renderer *rd, int current_frame);

};
#endif // PTERA_H
