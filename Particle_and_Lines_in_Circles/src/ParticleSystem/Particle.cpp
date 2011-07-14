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
	startLocation = location;
    
	velocity.set( ofRandom(-15, 15), ofRandom(-15, 15) );	
    gravity.set( 0, 2);
    
	scale = ofRandom(2, 5);	
	lifeSpan = int ( ofRandom( 50, 100) );					
	age = 0;	
	agePer = 1.0;
	decay = 0.99;
	dead = false;
	
    angle = 0;
}

void Particle :: update()
{
	
    angle += PI/50;
	location.x = startLocation.x + 120*sin(angle);
    location.y = startLocation.y + 120*cos(angle);
    
    location += velocity;
    velocity *= decay;
    
   // velocity += gravity;
	
	radius = scale * agePer;
	
	age ++;	
	agePer = 1.0f - ( float(age)/ float(lifeSpan));
	if (age > lifeSpan) {
		dead = true;
	}
    
 

}

void Particle :: draw ()
{
	ofSetColor( 255 * agePer, 255 * agePer, 0);
	ofCircle( location.x, location.y, radius);
    
    ofPoint point;
    point.set(location.x, location.y);
    coordinates.push_back( point );
    
    for (int i = 1; i < coordinates.size()-1; i++) {
        ofLine (coordinates[i].x, coordinates[i].y, coordinates[i+1].x, coordinates[i+1].y);
    }
}

