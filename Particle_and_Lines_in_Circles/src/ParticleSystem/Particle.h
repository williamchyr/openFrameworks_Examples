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
#include "ofxVectorMath.h"

//-----------------------------------

class Particle {

    
public:
	
	Particle();
	
	void		setup(int _x, int _y);
	void		update();
	void		draw();
	
	float		radius;
	float		scale;
	
	ofxVec2f	location;
	ofxVec2f	velocity;
    ofxVec2f    gravity;
    
    ofxVec2f    startLocation;
    
	int			lifeSpan;
	int			age;
	float		agePer;
	float		decay;
	
    bool		dead;
    
    float       angle;
    
    vector <ofPoint> coordinates;
    
};

#endif