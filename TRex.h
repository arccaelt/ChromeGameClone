#ifndef TREX_H
#define TREX_H

#include "SDL2/SDL.h"
#include "Texture.h"

// The TRex class is the player
class TRex
{
    int x, y; // where to draw the trex
    const int w, h; // the size of the player/trex sprite
    bool is_jumping;
    bool is_crunching;

    // To render a sprite sheet we need to define, for each frame, which section
    // of the sprite sheet will be renderer

    // Only 2 frames because for trex we have only 2 sprites
    SDL_Rect trex_run[4] = {{680, 0, 40, 50}, {720, 0, 40, 50},
                            {770, 0, 40, 50}, {810, 0, 40, 50}};

    // The idle sprite used for jumping is the first running sprite

    // Sprite for crunch
    SDL_Rect trex_crunch[2] = {{940, 0, 60, 50}, {1000, 0, 60, 50}};

    // dead sprite
    SDL_Rect dead = {855, 0, 60, 45};

    const int jump_amount = 160;
    const int jump_fall_amount = 3; // how fast the TRex is falling when he jumps

    SDL_Rect original_pos; // remember the original position. Used for collision

    // This method are private because they should be used
    // only in this class
    bool is_on_the_ground();

public:
    TRex(int a, int b, int w, int h);
    void draw(Texture &tex, SDL_Renderer *rd, int current_frame);
    SDL_Rect get_pos();

    void crunch();
    void jump();
    void run();
};

#endif // TREX_H
