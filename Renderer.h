#ifndef RENDERER_H
#define RENDERER_H

#include <iostream>
#include <SDL2/SDL.h>

/*
    Renderers in SDL are needed to be able to draw Textures onto  a
    windows screen. In addition, they are a lot more efficient then
    simple blit rendering because they use hardware acceleration
*/
class Renderer
{
protected:
    SDL_Renderer *render; // defined as being protected to be able to access it from Texture class
public:
    Renderer(SDL_Window *w);
    void set_color(int r, int g, int b, int a);
    void clear();
    void update();
    void set_background_color(int r, int g, int b, int a);
    SDL_Renderer *get_renderer();
    ~Renderer();
};

#endif // RENDERER_H
