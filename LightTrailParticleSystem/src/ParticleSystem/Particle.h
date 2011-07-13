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

//-----------------------------------

class Particle 
{
    
public:
    
	float radius;
	float timer;
    
    ofPoint position;
    ofPoint velocity;
    ofPoint acceleration;
    
    int r;
    int g;
    int b;
	
	void update();
	void draw();
    
    bool dead;
    
};

#endif