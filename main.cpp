#include <iostream>
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

#include "Window.h"
#include "Renderer.h"
#include "Texture.h"

#include "TRex.h"
#include "Ground.h"

using namespace std;

int main()
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout << "Can't init sdl: " << SDL_GetError() << "\n";
        return -1;
    }

    Window w(800, 600, "TRexClone");
    // game loop
    SDL_Event e;
    bool end = false;

    Renderer rd(w.get_window());
    Texture tex(rd.get_renderer(), "sp3.bmp", true, 255, 255, 255);

    int current_frame = 0;

    // todo: find a nice way to calculate the starting position for the player
    // based on the screen size
    Ground ground(w.get_height(), w.get_width(), tex.get_width(), tex, rd.get_renderer());
    TRex player(0, w.get_height() - 120, w.get_width() / 6, w.get_height() / 6);

    while(!end)
    {
        // NOTE: SDL_PollEvent will return 0 when the event queue is empty
        while(SDL_PollEvent(&e) != 0)
        {
            // Handle events

            if(e.type == SDL_QUIT)
            {
                end = true;
            }

            // If the user pressed a key
            else if(e.type == SDL_KEYDOWN)
            {
                // Find out what key

                // For my game only the up, down and space keys have
                // an action attached to them

                if(e.key.keysym.sym == SDLK_UP || e.key.keysym.sym == SDLK_SPACE)
                {
                    current_frame++;
                    player.jump();
                }
                else if(e.key.keysym.sym == SDLK_DOWN)
                {
                    player.crunch();
                }
                else
                {
                    player.run();
                }
            }
        }

        // set a white background
        rd.set_background_color(255, 255, 255, 255);
        rd.clear();

        // draw the ground
        ground.update(current_frame);
        ground.draw();
        player.draw(tex, rd.get_renderer(), current_frame);

        SDL_Rect pr = player.get_pos();
        if(ground.obstacle_collision(&pr))
        {
            end = true;
        }

        rd.update();

        // update the current frame
        current_frame++;
        current_frame %= 4;
    }

    SDL_Quit();
    return 0;
}
