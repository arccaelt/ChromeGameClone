#include "TRex.h"

TRex::TRex(int a, int b, int width, int height) : w(width), h(height)
{
    x = a;
    y = b;
    is_jumping = false;
    is_crunching = false;
    original_pos = {a, b, width, height};
}

bool TRex::is_on_the_ground()
{
    // Assemble an SDL_Rect for the current position of the TRex sprite
    // for collision detection
    return y >= original_pos.y;
}

void TRex::jump()
{
    if(!is_jumping)
    {
        y -= jump_amount;
        is_crunching = false;
        is_jumping = true;
    }
}

void TRex::crunch()
{
    is_crunching = true;
}

void TRex::run()
{
    is_jumping = false;
    is_crunching = false;
}

SDL_Rect TRex::get_pos()
{
    SDL_Rect r = {x, y, w, h};
    return r;
}

void TRex::draw(Texture &tex, SDL_Renderer *rd, int current_frame)
{
    // Create and SDL_Rect for the position where to draw the player
    SDL_Rect draw_location = {x, y - 12, w, h};

    // TODO: Split drawing and moving parts into different functions
    if(is_jumping)
    {
        if(!is_on_the_ground())
        {
            y += jump_fall_amount;
            tex.draw_texture(rd, &trex_run[0], &draw_location);
        }
        else
        {
            is_jumping = false;
        }
    }
    else if(is_crunching)
    {
        tex.draw_texture(rd, &trex_crunch[current_frame % 2], &draw_location);
    }
    else
    {
        tex.draw_texture(rd, &trex_run[current_frame], &draw_location);
    }
}
