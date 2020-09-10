#ifndef PARTICLEENGINE_H_INCLUDED
#define PARTICLEENGINE_H_INCLUDED

#include <SDL/SDL.h>
#include <iostream>
#include <vector>   
#include <cstdlib>  
#include <ctime>

#include "particle.h"

class particleEngine{
public:
    std::vector<particle*> particles;   
    int x,y,maxparticle,colorp;
    public:
    particleEngine(int maxpart,int X, int Y, int color);
    ~particleEngine();  
    void refresh();
};

#endif // PARTICLEENGINE_H_INCLUDED
