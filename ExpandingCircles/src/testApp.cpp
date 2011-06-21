#include "testApp.h"

CustomBall::CustomBall() {
    
    r = ofRandom(0, 20);
    g = ofRandom(100, 250);
    b = ofRandom(100, 250);
    
    radius = ofRandom(10, 50);
    lineWidth = ofRandom(2, 10);    
    expandRate = 2;
    
}

void CustomBall::update() {
    radius += expandRate;
    
    r += 1;
    g += 1;
    b += 1;
    
}

void CustomBall::draw() {
    ofSetColor(r, g, b, 100);
    ofNoFill();
    ofSetLineWidth(lineWidth);
    ofCircle (x, y, radius);
}

//--------------------------------------------------------------
void testApp::setup(){
    
    ofBackground(255, 255, 255);
    ofSetFrameRate(60);
    ofSetCircleResolution(150);
    ofEnableSmoothing();
    //ofEnableAlphaBlending();
 
}

//--------------------------------------------------------------
void testApp::update(){
    
    for (int i = 0; i < circles.size(); i++ ) {
        circles[i].update();
    }

}

//--------------------------------------------------------------
void testApp::draw(){
    
    for (int i = 0; i < circles.size(); i++ ) {
        circles[i].draw();
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
    CustomBall sampleCircle;
    
    sampleCircle.x = mouseX;
    sampleCircle.y = mouseY;
    
    circles.push_back(sampleCircle);
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

