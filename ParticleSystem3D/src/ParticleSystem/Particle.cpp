//
//  Particle.cpp
//  ParticleSystem
//
//  Created by Willy Chyr on 11-05-31.
//  Copyright 2011 Willy Chyr. All rights reserved.
//

#include "Particle.h"

void Particle::init() {
    
    orbitalRadius = ofRandom(100, 350);
    
    sphereRadius = ofRandom(7, 15);
    
    yShift = ofRandom(-100, 150); //how far up or down the orbit is shifted;
    
    angle = 0;
    r = ofRandom(150, 255);
    g = ofRandom(150, 255);
    b = ofRandom(0, 255);
    
}

void Particle::update() {
    
    angle += PI/(ofRandom(80, 360));
    
    x = ofGetWidth()/2 + orbitalRadius*sin(angle);
    z = orbitalRadius*cos(angle);
    y = ofGetHeight()/2+yShift;
    
}

void Particle::draw() {
    
    ofSetColor(r, g, b);
    ofxSphere(x, y, z, sphereRadius, sphereRadius, sphereRadius, 0, 0, 0);
}
