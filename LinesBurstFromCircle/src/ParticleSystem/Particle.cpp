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
    //location.set( x + int(ofRandom(-10, 10)), y + int(ofRandom(-10, 10)));
	
    float circleAngle;
    circleAngle = PI*ofRandom(0.0f, 2.0f);
    location.set(x + 15*sin(circleAngle), y + 15*cos(circleAngle) );
    startLocation = location;
    
	velocity.set(sin(circleAngle), cos(circleAngle) );	
    velocity *= ofRandom(10, 20);
    gravity.set( 0, 2);
    
	scale = ofRandom(2, 5);	
	lifeSpan = int ( ofRandom( 10, 15) );					
	age = 0;	
	agePer = 1.0;
	decay = 0.99;
	dead = false;
	
    angle = 0;
}

void Particle :: update()
{
	
    angle += PI/50;
	//location.x = startLocation.x + 120*sin(angle);
    //location.y = startLocation.y + 120*cos(angle);
    
    location += velocity;
    velocity *= decay;
    
    //velocity += gravity;
	
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
	//ofCircle( location.x, location.y, radius);
    
    ofPoint point;
    point.set(location.x, location.y);
    coordinates.push_back( point );
    
    if (coordinates.size() > 1) {
        for (int i = 0; i < coordinates.size()-1; i++) {
            ofLine (coordinates[i].x, coordinates[i].y, coordinates[i+1].x, coordinates[i+1].y);
        }
    }
}

