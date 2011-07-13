//
//  LightParticleSystem.cpp
//  LightParticleSystem
//
//  Created by Willy Chyr on 11-05-31.
//  Copyright 2011 Willy Chyr. All rights reserved.
//

#include "LightTrail.h"


//----- LIGHT TRAIL BIT STUFF

void LightTrailBit :: draw ()
{
	ofSetColor( r, g, b );
	ofCircle( position.x, position.y, radius );
}


void LightTrailBit :: update()
{
    timer -= 1;
    
    if (radius > 0) {
        // radius -= 0.1;
    }
    
    if (thickness < 8) {
        thickness += 0.2;
    }
   
    
        
    //this is to make the color of the particles grow darker
    if (r > 0) {
        r -= 2.5;
    }
    
    if (g > 0) {
        g -= 2.5;
    }
    
    if (b > 0) {
        b -= 2.5;
    }
}

bool LightTrailBit::dead() {
	if(timer <= 0.0) {
		return true;
	} else {
		return false;
	}
}


//----------- LIGHT TRAIL STUFF

LightTrail::LightTrail() {
	
}

void LightTrail::update() {
	for(int i=0; i < light.size(); i++) {
		light[i].update();
		if(light[i].dead()) {
			light.erase( light.begin()+i );
		}
	}
    
}

void LightTrail::draw() {
	//for(int i=0; i< light.size(); i++) {
    
    for (int i = light.size()-1; i >=0; i--) {
        
    
        ofFill();
        light.back().draw();

        ofNoFill();
        ofSetColor(light[0].r, light[0].g, light[0].b);
        //ofSetLineWidth(light[i].thickness);
        ofSetLineWidth(light[light.size()-1-i].thickness);
        
        //ofSetLineWidth(thickness);
        
       /*
        if (i > 3) {
        
            ofBezier(light[i].position.x, light[i].position.y, 
                     light[i-1].position.x, light[i-1].position.y,
                     light[i-2].position.x, light[i-2].position.y, 
                     light[i-3].position.x, light[i-3].position.y);

      
        }
         */
        
        if (i < light.size()-1 && i > 2) {
            
            ofBezier(light[i].position.x, light[i].position.y, 
                     light[i-1].position.x, light[i-1].position.y,
                     light[i-2].position.x, light[i-2].position.y, 
                     light[i-3].position.x, light[i-3].position.y);
            
           
        }
      
	}
}

void LightTrail::addBit(float _posX, float _posY, float _timer) {
    
    LightTrailBit p;
    
    p.position.x = _posX;
    p.position.y = _posY;
    p.radius = 3;
    
                  
    p.timer = _timer;
    //p.thickness= 0;
    
    //setting the colors of the LightParticles
    p.r = 155;
    p.g = 105;
    p.b = 255;
    
    
    light.push_back(p);
    
}

