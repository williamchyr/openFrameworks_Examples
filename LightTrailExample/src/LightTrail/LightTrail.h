//
//  LightParticleSystem.h
//  LightParticleSystem
//
//  Created by Willy Chyr on 11-05-31.
//  Copyright 2011 Willy Chyr. All rights reserved.
//


#ifndef LIGHT_TRAIL_H
#define LIGHT_TRAIL_H

#include "ofMain.h"

/**********************
 
The LighTrailBit is class for the particles 
which connect to make the lightTrail.
 
*********************/

class LightTrailBit {
    
public:
    
	float radius;
	float timer;
    
    ofPoint position;
    
    int r;
    int g;
    int b;
	
	void update();
	void draw();
    
    float thickness;
    
    bool dead();
    
};


/*********************
 
This is the LightTrail. It is a basically a vector of LightTrailBits,
with bezier curves connecting one LightTrailBit to the next. Therefore creating
a line, or a trail. 
 
********************/

class LightTrail {
    
public:
	LightTrail();
	
    void init();
	void update();
	void draw();
	void addBit(float _posX, float _posY, float _timer);
    
	bool dead;
    
    vector <LightTrailBit> light;

	
};

#endif