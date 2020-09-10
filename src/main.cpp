#include <SDL/SDL.h>
#include <iostream>
#include <vector>   
#include <cstdlib>
#include <ctime>
#include <SDL_image.h>

#include "../src/graphic/particle.h"
#include "../src/graphic/particleEngine.h"



int main(int argc,char** argv)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Surface* screen;
    screen=SDL_SetVideoMode(1280,720,8,SDL_SWSURFACE|SDL_DOUBLEBUF);
    bool running=true;
    const int FPS=30;   
    Uint32 start;
    srand(time(0)); /
    particleEngine ps(600,screen->w/2,screen->h/2, 0);

    SDL_EnableKeyRepeat(10,10);

    SDL_Surface* glow;
    SDL_Surface* background;

    glow = IMG_Load("textures/ylight.png");
    background = IMG_Load("textures/concrete.jpg");

        if (!background)
        {
            printf("Unable to load surface: %s\n", SDL_GetError());
            return 1;
        }
        if (!glow)
        {
            printf("Unable to load surface: %s\n", SDL_GetError()); // !
            return 1;
        }

    SDL_Rect posZZ, posCenter;

    posZZ.x = 0;
    posZZ.y = 0;
    posCenter.x = screen->w/2;
    posCenter.y = screen->h/2;




    while(running)
    {
        start=SDL_GetTicks();
        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_QUIT:
                    running=false;
                    break;
                case SDL_MOUSEMOTION:

                    ps.x = event.button.x;
                    ps.y = event.button.y;
                    break;
                case SDL_KEYUP:
                    if (event.key.keysym.sym == SDLK_UP)
                        ps.colorp++;
                    if (event.key.keysym.sym == SDLK_DOWN)
                        ps.colorp--;
            }
        }

      //SDL_FillRect(screen,&screen/*->clip_rect*/,SDL_MapRGB(screen->format,0x00,0x00,0x00));  //clear the screen
          SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));

    SDL_BlitSurface(background, NULL, screen, &posZZ);
    SDL_BlitSurface(glow, NULL, screen, &posCenter);
	ps.refresh();


    SDL_Flip(screen);
        if(1000/FPS>SDL_GetTicks()-start)
            SDL_Delay(1000/FPS-(SDL_GetTicks()-start));
    }
    SDL_Quit();
    return 0;
}
