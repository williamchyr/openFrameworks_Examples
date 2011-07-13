#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofBackground(255, 255, 255);
    ofEnableSmoothing();
    ofEnableAlphaBlending();

}

//--------------------------------------------------------------
void testApp::update(){
    

    lightTail.update();  
    lightTail.addBit(mouseX, mouseY, 100 );
    

}
//--------------------------------------------------------------
void testApp::draw(){

    lightTail.draw();
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
    
    //ps.addParticle(box2d, mouseX, mouseY, 20, 150);
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

