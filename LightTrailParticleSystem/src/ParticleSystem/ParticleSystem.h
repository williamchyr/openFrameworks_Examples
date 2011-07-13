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
#include "LightTrail.h"


class ParticleSystem {
public:
	ParticleSystem();
	
	void update();
	void draw();
	void addParticle(float _posX, float _posY, float _radius, float _timer);
	bool dead();
    
    
    vector <Particle> particles;
    
    vector <LightTrail> lightTrails;
    
    //vector <LightParticleSystem> multiLightTrails;

	
};

#endif