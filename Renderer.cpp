#include "Renderer.h"

Renderer::Renderer(SDL_Window *w)
{
    // note: SDL_RENDERER_ACCELERATED flag will tell SDL to use
    // hardware accelaration for drawing stuff
    render = SDL_CreateRenderer(w, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(render == NULL)
    {
        std::cout << "Can't create a renderer\n";
        exit(EXIT_FAILURE);
    }
}

SDL_Renderer *Renderer::get_renderer()
{
    return render;
}

void Renderer::set_color(int r, int g, int b, int a)
{
    SDL_SetRenderDrawColor(render, r, g, b, a);
}

void Renderer::clear()
{
    SDL_RenderClear(render);
}

void Renderer::update()
{
    SDL_RenderPresent(render);
}

void Renderer::set_background_color(int r, int g, int b, int a)
{
    SDL_SetRenderDrawColor(render, r, g, b, a);
}

Renderer::~Renderer()
{
    SDL_DestroyRenderer(render);
}
