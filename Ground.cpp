#include "Ground.h"

// The constructor needs the screen height(sh) and sprite
// width(sprtw) and screen width(sw) to find where to draw the ground
Ground::Ground(int sh, int sw, int sprtw, Texture &t, SDL_Renderer *r) : screen_width(sw), screen_height(sh), tex(t), rd(r)
{
    sprite_ground_pos.x = 0;
    sprite_ground_pos.y = 50;
    sprite_ground_pos.w = sprtw;
    sprite_ground_pos.h = 20;
    ground1.x = 0;
    ground1.y = sh - 50;
    ground1.w = sw;
    ground1.h = 20;

    ground2.x = sw;
    ground2.y = sh - 50;
    ground2.w = sw;
    ground2.h = 20;

    ground3.x = sw;
    ground3.y = sh - 50;
    ground3.w = sw;
    ground3.h = 20;

    // seed the RNG
    srand(time(NULL));
}

// To be able to do level scrolling we will use 3 SDL_Rect(s):
//   ground1 = the current ground bounding rect
//   ground2 = will be used when groun1.w is smaller then the window's
//             with
//   ground3 = stores the original bounding box for the groun
void Ground::move_ground()
{
    ground1.x -= move_speed;

    // If the current ground is off then renderer screen even just a little
    // bit then start drawing the other screen
    if(abs(ground1.x) - ground1.w <= screen_width)
    {
        ground2.x -= move_speed;
    }

    // If the current ground was rendered completed(totally of the map)
    // the switch him with ground2(which is still rendering) and init
    // ground2 with the original ground
    if(abs(ground1.x) >= ground1.w)
    {
        ground1 = ground2;
        ground2 = ground3;
        add_obstacle();
    }
}

// Obstacles(if they are generated) will be added on ground 2
void Ground::add_obstacle()
{
    int r = rand() % 3;
    std::cout << "rand: " << r << "\n";
    if(r) // if r == 0 no obst. is generated
    {
        if(r == 1)
        {
            // A ptera is created
            pteras.push_back(Ptera(screen_width + 10, screen_height - 150, screen_width, 30, 30));
        }
        else
        {
            cactus.push_back(Cactus(screen_width + 10, screen_height - 100, screen_width, rand() % 3, 60, 60));
        }
    }
}

void Ground::draw_obstacles()
{
    for(int i = 0; i < pteras.size(); i++)
    {
        pteras[i].draw(tex, rd, current_frame);
    }
    for(int i = 0; i < cactus.size(); i++)
    {
        cactus[i].draw(tex, rd);
    }
}

void Ground::move_obstacles()
{
    for(int i = 0; i < pteras.size(); i++)
    {
        pteras[i].move();
    }
    for(int i = 0; i < cactus.size(); i++)
    {
        cactus[i].move();
    }

    //remove offscreen pteras/cacts
}

bool Ground::obstacle_collision(SDL_Rect *pr)
{
    for(int i = 0; i < pteras.size(); i++)
    {
        SDL_Rect bd = pteras[i].get_bounding_box();
        if(SDL_HasIntersection(pr, &bd))
        {
            return true; // game over
        }
    }
    for(int i = 0; i < cactus.size(); i++)
    {
        SDL_Rect bd = cactus[i].get_bounding_box();
        if(SDL_HasIntersection(pr, &bd))
        {
            return true; // game over
        }
    }
    return false;
}

void Ground::update(int cf)
{
    current_frame = cf;
}

void Ground::draw()
{
    move_ground();
    move_obstacles();
    tex.draw_texture(rd, &sprite_ground_pos, &ground1);
    tex.draw_texture(rd, &sprite_ground_pos, &ground2);
    draw_obstacles();
}
