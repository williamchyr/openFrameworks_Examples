#include "testApp.h"


//--------------------------------------------------------------

void CustomPoint::init(int _x, int _y) {
    
    x = _x;
    y = _y;
    
    timer = 250;
 
}

void CustomPoint::update() {
    
    vector.set(x - (ofGetWidth()/2), y - (ofGetHeight()/2));
    vector.scale(2);
    
    x += vector.x;
    y += vector.y;
    
    timer -= 1;
    
    if (timer < 1) {
        dead = true;
    }
    
    r -= 1;
    g -= 1;
    b -= 1;
}



//--------------------------------------------------------------
void testApp::setup(){
    
    ofBackground(0, 0, 0);
    ofSetFrameRate(80);
    ofEnableSmoothing();
    
    
    angle = 0;
}

//--------------------------------------------------------------
void testApp::update(){

    angle += PI/260;
    
    
      
    
    CustomPoint mousePoint;
    
    //This is just to give the user some time to put the mouse in window, so coordinates are not (0, 0);
    if (ofGetFrameNum() < 40) {
        mousePoint.init(ofGetWidth()/2, ofGetHeight()/2);
    } else {
        mousePoint.init(mouseX, mouseY);
    }
    
    mousePoint.r = 100+sin(angle)*150;
    mousePoint.g = 255;
    mousePoint.b = 10 + cos(angle)*200;
    
    linePoints.push_back(mousePoint);
    
    
    for (int i = 0; i < linePoints.size()-1; i++) {
        
        linePoints[i].update();
        if(linePoints[i].dead) {
			linePoints.erase( linePoints.begin()+i );
		}
    }
 
    
}

//--------------------------------------------------------------
void testApp::draw(){

    
    ofSetLineWidth(10);
    
    for (int i = 0; i < linePoints.size()-1; i++) {
        
        ofSetColor(linePoints[i].r, linePoints[i].g, linePoints[i].b);
        
        ofLine(linePoints[i].x, linePoints[i].y, 
               linePoints[i+1].x, linePoints[i+1].y);
        
        
        /*
        ofBezier(linePoints[i].x, 
                linePoints[i].y, 
                linePoints[i].x+10, 
                linePoints[i].y+10, 
                linePoints[i+1].x+10, 
                linePoints[i+1].y+10, 
                linePoints[i+1].x, 
                linePoints[i+1].y);
         */
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

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

