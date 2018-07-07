#include "Obstacle.h"

bool Obstacle::is_offscreen()
{
    return x <= 0;
}

void Obstacle::move()
{
    x -= move_speed;
}

SDL_Rect Obstacle::get_bounding_box()
{
    SDL_Rect r = {x, y, w, h};
    return r;
}
