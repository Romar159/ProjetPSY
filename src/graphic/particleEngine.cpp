#include <SDL/SDL.h>
#include <iostream>
#include <vector>   
#include <cstdlib> 
#include <ctime>

#include "particleEngine.h"

particleEngine::particleEngine(int maxpart,int X, int Y, int color)
{
    x=X;
    y=Y;
    color=colorp;
    maxparticle=maxpart;
    for(int i=0;i<maxparticle;i++)  
        particles.push_back(new particle(x+rand()%6-3,y+rand()%6-3,rand()%10+(float)rand()/(float)RAND_MAX-5,rand()%10+(float)rand()/(float)RAND_MAX-5,500+rand()%1000,/*rand()%255*/colorp));
}

particleEngine::~particleEngine()
{
   
    for(int i=0;i<maxparticle;i++)
        delete particles[i];
}

void particleEngine::refresh()
{
    for(int i=0;i<maxparticle;i++)
    {
        if(particles[i]->isDead())  
        {
            delete particles[i];    
            particles[i]=new particle(x+rand()%6-3,y+rand()%6-3,rand()%10+(float)rand()/(float)RAND_MAX-5,rand()%10+(float)rand()/(float)RAND_MAX-5,500+rand()%2000,/*rand()%255*/colorp);
        }else{  
            particles[i]->move();  
            particles[i]->show();
        }
    }
}
