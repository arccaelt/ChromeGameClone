#ifndef TEXTURE_H
#define TEXTURE_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

/*
    In SDL2, texture gives us hardware accelerated rendering.
    Also, textures are very flexible
*/

class Texture
{
private:
    SDL_Texture *tex;
    int width; // width of the texture
    int height; // height of the texture
public:
    // Gets the path to a file/image that will be loaded as a texture
    Texture(SDL_Renderer *wd, char *path, bool is_spritesheet = false, int r = 0, int g = 0, int b = 0);
    void draw_texture(SDL_Renderer *rd, SDL_Rect *src, SDL_Rect *dst);

    int get_width() {return width;}
    int get_height() {return height;}

    ~Texture();
};

#endif // TEXTURE_H
