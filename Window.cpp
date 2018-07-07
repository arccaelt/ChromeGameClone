#include "Window.h"

Window::Window(int w, int h, char *Title)
{
    width = w;
    height = h;
    title = Title;
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                     width, height, SDL_WINDOW_SHOWN);

    // check if the windows has been created
    if(window == NULL)
    {
        std::cout << "Can't create window\n";
        exit(EXIT_FAILURE);
    }
}

SDL_Window *Window::get_window()
{
    return window;
}

// Updates the window
void Window::update()
{
    SDL_UpdateWindowSurface(window);
}

int Window::get_height()
{
    return height;
}

int Window::get_width()
{
    return width;
}

Window::~Window()
{
    SDL_DestroyWindow(window);
}
