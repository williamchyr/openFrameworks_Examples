//
//  Particle.h
//  ParticleSystem
//
//  Created by Willy Chyr on 11-05-31.
//  Copyright 2011 Willy Chyr. All rights reserved.
//


#ifndef PARTICLE_H
#define PARTICLE_H

#include "ofMain.h"
#include "ofx3DUtils.h"


//-----------------------------------

class Particle {
    
public:
    
    int orbitalRadius;
    int sphereRadius;
    
    int x;
    int y;
    int z;  
    
    int r;
    int g;
    int b;
    
    int yShift;
    float angle;
    
    void init();
    void update();
    void draw();
    
    bool dead;
    
};

#endif