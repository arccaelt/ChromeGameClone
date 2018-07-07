#include "Cactus.h"

void Cactus::draw(Texture &tex, SDL_Renderer *rd)
{
    SDL_Rect cact_pos = {x, y, w, h};
    tex.draw_texture(rd, &frames[type], &cact_pos);
}
