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
	
	for( list<Particle>::iterator p = particles.begin(); p != particles.end(); ) {
		if( p->dead ){
			p = particles.erase( p );
		} else {
			p->update();
			++p;
		}
	}

    
}

void ParticleSystem::draw() {
	
	for( list<Particle>::iterator p = particles.begin(); p != particles.end(); ++p ){
		p->draw();
	}
	
}


void ParticleSystem::addParticle(float _posX, float _posY) {
    
	for (int i = 0; i < 5; i++) {		
		Particle p;		
		p.setup(_posX, _posY);
		particles.push_back(p);
	}

}


bool ParticleSystem::dead() {
	if(particles.size() == 0) {
		return true;
	} else {
		return false;
	}
}