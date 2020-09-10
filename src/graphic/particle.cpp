#include <SDL/SDL.h>
#include <iostream>
#include <vector>   
#include <cstdlib>  
#include <ctime>

#include "particle.h"

particle::particle(float X,float Y,float Xvel,float Yvel,int life,Uint32 Color)
{
   
    x=X;
    y=Y;
    xvel=Xvel;
    yvel=Yvel;
    endTime=SDL_GetTicks()+life; 
    color=Color;
}

void particle::move()
{
    
    x+=xvel;
    y+=yvel;
    
    if(x<0)
        x=0;
    if(y<0)
        y=0;
    if(x>SDL_GetVideoSurface()->w)
        x=SDL_GetVideoSurface()->w-1;
    if(y>SDL_GetVideoSurface()->h)
        y=SDL_GetVideoSurface()->h-1;
}

void particle::show()
{
    Uint8* pixels=(Uint8*)SDL_GetVideoSurface()->pixels;
    Uint8* pixel=pixels+(int)y*SDL_GetVideoSurface()->pitch+(int)x;
    *pixel=color;
}

bool particle::isDead()
{
    return (SDL_GetTicks()>=endTime || x==0 || y==0 || x==SDL_GetVideoSurface()->w-1 || y==SDL_GetVideoSurface()->h-1);
}
