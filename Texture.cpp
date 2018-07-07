#include "Texture.h"

Texture::Texture(SDL_Renderer *rd, char *path, bool is_spritesheet, int r, int g, int b)
{
    SDL_Surface *ld = SDL_LoadBMP(path);
    if(ld == NULL)
    {
        std::cout << "Can't load image texture: " << path << "\n";
        std::cout << "Error message: " << SDL_GetError();
        exit(EXIT_FAILURE);
    }
    else
    {
        // save the size of the texture
        width = ld->w;
        height = ld->h;

        // NOTE: If you are using .BMP make sure the file has 24 bit and NOT 32 bit
        if(is_spritesheet)
        {
            // If the texture is a spritesheet then we want to do color keying.
            // Color keying is a way to remove the background(or a pixel in our case)
            // from a texture.
            // To do this we call the SDL_SetColorKey with:
            //     ld = the loaded surface
            //     SDL_TRUE = because we want to do color keying
            //     the third arugment is the pixel we want to remove. Calling SDL_MapRGB
            //     will make this cross platform and will map the R,G,B values to a value
            SDL_SetColorKey(ld, SDL_TRUE, SDL_MapRGB(ld->format, r, g, b));
        }

        // create the texture
        tex = SDL_CreateTextureFromSurface(rd, ld);

        // at this point we can destroy the surface
        SDL_FreeSurface(ld);
    }
}

/*
    When we want to render a texture we have to get/have a renderer,
    a texture and 2(optionl) SDL_Rects src, dst which have the following meaning:
        src will define the piece/section of the texture which we want to render
        dst will define a location on the renderer/window in which the selected
            piece/section will be rendered
        if src or dst are NULL then the hole texture/window will be used
*/
void Texture::draw_texture(SDL_Renderer *rd, SDL_Rect *src, SDL_Rect *dst)
{
    SDL_RenderCopy(rd, tex, src, dst);
}

Texture::~Texture()
{
    SDL_DestroyTexture(tex);
}
