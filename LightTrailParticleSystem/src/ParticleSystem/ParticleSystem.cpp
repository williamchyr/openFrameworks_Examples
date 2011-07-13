//
//  ParticleSystem.cpp
//  ParticleSystem
//
//  Created by Willy Chyr on 11-05-31.
//  Copyright 2011 Willy Chyr. All rights reserved.
//

#include "ParticleSystem.h"


ParticleSystem::ParticleSystem() {
	
}

void ParticleSystem::update() {
	for(int i=0; i < particles.size(); i++) {
		particles[i].update();
		if(particles[i].dead) {
           // particles[i].destroyShape();
			particles.erase( particles.begin()+i );
            
            lightTrails.erase(lightTrails.begin()+i);
		}
        
        lightTrails[i].addBit(particles[i].position.x, particles[i].position.y, particles[i].timer );
        
        lightTrails[i].update();
	}
}

void ParticleSystem::draw() {
	for(int i=0; i< particles.size(); i++) {
        ofFill();
		particles[i].draw();
        
        ofNoFill();
        lightTrails[i].draw();
	}
}

void ParticleSystem::addParticle(float _posX, float _posY, float _radius, float _timer) {
    
    Particle p;
    
    p.dead == false;
    p.radius = _radius;
    
    //set velocity in x and y direction to be random number between -3 and 3
    
    p.position.set(_posX, _posY);
    p.velocity.set(int(ofRandom(-10, 10)), int(ofRandom(-30, 2)) );
    p.acceleration.set(0, 5);
                  
    p.timer = _timer;

    //setting the colors of the particles
    p.r = 130;
    p.g = 150;
    p.b = 255;
    
    particles.push_back(p);
    
    LightTrail      theLight;
  
    lightTrails.push_back(theLight);
}


bool ParticleSystem::dead() {
	if(particles.size() == 0) {
		return true;
	} else {
		return false;
	}
}