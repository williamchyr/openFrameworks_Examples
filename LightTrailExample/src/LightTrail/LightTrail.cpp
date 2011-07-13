//
//  LightParticleSystem.cpp
//  LightParticleSystem
//
//  Created by Willy Chyr on 11-05-31.
//  Copyright 2011 Willy Chyr. All rights reserved.
//

#include "LightTrail.h"

//----- LIGHT TRAIL BIT

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
    
    if (thickness > 0) {
        thickness -= 0.05;
    }
    
    
    
    //this is to make the color of the particles grow darker
    if (r < 255) {
        r += 2;
    }
    
    if (g < 255) {
        g += 2;
    }
    
    if (b < 255) {
        b += 2;
    }
    
    
}

bool LightTrailBit::dead() {
	if(timer <= 0.0) {
		return true;
	} else {
		return false;
	}
}


//----------- LIGHT TRAIL

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
	for(int i=0; i< light.size(); i++) {
		//light[i].draw();
        ofFill();
       // light[light.size()-1].draw();
        light.back().draw();

        //ofBezier(float x0, float y0, float x1, float y1, float x2, float y2, float x3, float y3)
        
        ofNoFill();
        ofSetColor(light[i].r, light[i].g, light[i].b);
        ofSetLineWidth(light[i].thickness);
        
        if ( i < light.size()-3 ){
           /*
            ofBezier(light[i].position.x, light[i].position.y, 
                     (light[i].position.x+light[i+1].position.x)/2, 
                     (light[i].position.y+light[i+1].position.y)/2, 
                     (light[i].position.x+light[i+1].position.x)/2,  
                     (light[i].position.y+light[i+1].position.y)/2,
                     light[i+1].position.x, light[i+1].position.y);
            */
            
            ofBezier(light[i].position.x, light[i].position.y, 
                     light[i+1].position.x, light[i+1].position.y,
                     light[i+2].position.x, light[i+2].position.y, 
                     light[i+3].position.x, light[i+3].position.y);

            
      
        }
	}
}

void LightTrail::addBit(float _posX, float _posY, float _timer) {
    
    LightTrailBit p;
    
    p.position.x = _posX;
    p.position.y = _posY;
    p.radius = 3;
    
                  
    p.timer = _timer;
    p.thickness=10;
    
    //setting the colors of the LightParticles
    p.r = 155;
    p.g = 105;
    p.b = 255;
    
    
    light.push_back(p);
    
}

