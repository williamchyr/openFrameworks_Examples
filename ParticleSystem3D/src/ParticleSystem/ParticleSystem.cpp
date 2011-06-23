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
        
        cout << particles[i].angle << "\n";

	}
}

void ParticleSystem::draw() {
	for(int i=0; i< particles.size(); i++) {
		particles[i].draw();
	}
}

void ParticleSystem::addParticle() {
    
    Particle p;
    
    p.init();
    
    
    particles.push_back(p);
    
}


bool ParticleSystem::dead() {
	if(particles.size() == 0) {
		return true;
	} else {
		return false;
	}
}