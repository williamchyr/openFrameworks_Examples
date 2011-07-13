#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofBackground(0, 0, 0);
    ofEnableSmoothing();
    ofEnableAlphaBlending();
    
    ofSetFrameRate(30);

}

//--------------------------------------------------------------
void testApp::update(){
    
  
    
    ps.update();    

}
//--------------------------------------------------------------
void testApp::draw(){

    ps.draw();
    
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
    
    /******
    If you want to create particle by clicking mouse, uncomment the line below
    ******/
    
    for (int i =0; i < 10; i++) {
        ps.addParticle(mouseX, mouseY, 10, 60);
    }
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

