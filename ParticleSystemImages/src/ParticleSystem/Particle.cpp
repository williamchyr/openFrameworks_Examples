//
//  Particle.cpp
//  ParticleSystem
//
//  Created by Willy Chyr on 11-05-31.
//  Copyright 2011 Willy Chyr. All rights reserved.
//

#include "Particle.h"

Particle::Particle() {
}

void Particle :: setup (int x, int y) 
{
	location.set( x + int(ofRandom(-10, 10)), y + int(ofRandom(-10, 10)));
	velocity.set( ofRandom(-7, 7), ofRandom(-7, 7) );	
	scale = ofRandom(2, 5);	
	lifeSpan = int ( ofRandom( 30, 50) );					
	age = 0;	
	agePer = 1.0;
	decay = 0.99;
	dead = false;
	
}

void Particle :: update()
{
	location += velocity;
	velocity *= decay;
	
	radius = scale * agePer;
	
	age ++;	
	agePer = 1.0f - ( float(age)/ float(lifeSpan));
	if (age > lifeSpan) {
		dead = true;
	}

}

void Particle :: draw (ofImage *image)
{
	ofSetColor( 255, 255, 255, 255 * agePer);
	//ofCircle( location.x, location.y, radius);
    
    ofImage mImage = *image;
    //mImage.resize(100.0 * agePer, 100.0 * agePer);
    mImage.draw(location.x, location.y);
    
}

