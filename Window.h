#ifndef WINDOW_H
#define WINDOW_H
#include <SDL2/SDL.h>
#include <iostream>

class Window
{
private:
    SDL_Window *window; // actual window pointer
    int width; // screen width
    int height; // screen height
    char *title; // window title
public:
    Window(int, int, char *);
    void update();
    SDL_Window *get_window();
    int get_width();
    int get_height();
    ~Window();
};

#endif // WINDOW_H
