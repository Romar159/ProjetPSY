#ifndef PARTICLE_H_INCLUDED
#define PARTICLE_H_INCLUDED

#include <SDL/SDL.h>
#include <iostream>
#include <vector>   
#include <cstdlib>  
#include <ctime>

#include "particle.h"


class particle{ 
    float x,y,xvel,yvel;    
    Uint32 endTime; 
    Uint32 color;    
    public:
    particle(float X,float Y,float Xvel,float Yvel,int life,Uint32 Color);
    void move();
    void show();
    bool isDead(); 
};

#endif // PARTICLE_H_INCLUDED
