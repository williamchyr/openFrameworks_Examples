#include "testApp.h"


//--------------------------------------------------------------	BUSINESS AS USUAL.

void testApp :: setup()
{
	ofBackground(0, 0, 0);
	ofSetFrameRate(30);


}

//--------------------------------------------------------------

void testApp :: update(){

    
    ps.update();
    
}

//--------------------------------------------------------------

void testApp :: draw()
{
	ofSetBackgroundAuto(true);

    //ps.addParticle(mouseX, mouseY);
	ps.draw();
   
    
}

void testApp::windowResized(int w, int h) {

}


//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 

}
//--------------------------------------------------------------
void testApp::keyReleased (int key){ 

}
//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button) {
    
     ps.addParticle(x, y);

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

	
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

void testApp::mouseDragged(int x, int y, int button) {

}


