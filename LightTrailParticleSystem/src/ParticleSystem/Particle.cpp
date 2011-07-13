//
//  Particle.cpp
//  ParticleSystem
//
//  Created by Willy Chyr on 11-05-31.
//  Copyright 2011 Willy Chyr. All rights reserved.
//

#include "Particle.h"

void Particle :: draw ()
{
	ofSetColor( r, g, b );
	ofCircle( position.x, position.y, radius );
}


void Particle :: update()
{
    position = position + velocity;
    velocity = velocity + acceleration;
    
    timer -= 1;
    
    if (radius > 0) {
        // radius -= 0.1;
    }
    
    if (timer < 0  ) {
        dead == true;
    }
    
    //this is to make the color of the particles grow darker
    if (r > -1) {
        r -= 2;
    }
    
    if (g > -1) {
        g -= 2;
    }
    
    if (b > -1) {
        b -= 2;
    }
}

