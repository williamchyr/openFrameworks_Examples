//
//  ParticleSystem.cpp
//  ParticleSystem
//
//  Created by Willy Chyr on 11-05-31.
//  Copyright 2011 Willy Chyr. All rights reserved.
//

#include "ParticleSystem.h"


ParticleSystem::ParticleSystem() {
    
    particleImage.loadImage("particle.png");
	particleImage.setAnchorPercent(0.5, 0.5); 
    particleImage.resize(100, 100);
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
		p->draw(&particleImage);
       
        //particleImage.draw(p->location.x, p->location.y);
        //particleImage.resize(100*p->agePer, 100);
	}
	
}


void ParticleSystem::addParticle(float _posX, float _posY) {
    
	for (int i = 0; i < 15; i++) {		
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