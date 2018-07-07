#include "Ptera.h"

void Ptera::draw(Texture &tex, SDL_Renderer *rd, int current_frame)
{
    SDL_Rect pt_pos = {x, y, frames[0].w, frames[0].h};
    tex.draw_texture(rd, &frames[current_frame % 2], &pt_pos);
}
