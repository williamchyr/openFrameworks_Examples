//
//  ParticleSystem.h
//  ParticleSystem
//
//  Created by Willy Chyr on 11-05-31.
//  Copyright 2011 Willy Chyr. All rights reserved.
//


#ifndef PARTICLE_SYSYTEM_H
#define PARTICLE_SYSYTEM_H

#include "ofMain.h"
#include "Particle.h"


class ParticleSystem {
public:
	ParticleSystem();
	
	void update();
	void draw();
	void addParticle();
	bool dead();
    
    
    vector <Particle> particles;

	
};

#endif