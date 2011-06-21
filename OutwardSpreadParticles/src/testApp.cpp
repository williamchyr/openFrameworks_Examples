#include "testApp.h"

void CustomCircle::init(int _x, int _y, float _angle) {
    
    x = _x;
    y = _y;
    
    angle = _angle;
    
    r = 10+int(sin(angle)*200);
    g = 180+int(cos(angle)*75);
    b = 100+int(cos(angle)*100);
        
    vector.set(x - (ofGetWidth()/2), y - (ofGetHeight()/2));
    vector.scale(2);
    
    dead = false;
    
    timer = 400;
}

void CustomCircle::update() {
    
    x += vector.x;
    y += vector.y;
    
    timer -= 1;
    
    if (timer < 0) {
        dead = true;
    }
    


}

void CustomCircle::draw() {
    
    ofSetColor(r, g, b, 100);
    ofFill();
    ofCircle(x, y, 5);
}


//--------------------------------------------------------------
void testApp::setup(){
    
    ofBackground(0, 0, 0);
    ofSetFrameRate(60);
    
    angle = 0;
}

//--------------------------------------------------------------
void testApp::update(){

    angle += PI/260;
    
    numberOfParticles = int(ofRandom(1, 5));
                            
    for (int i = 0; i < numberOfParticles; i++) {
        CustomCircle    sampleCircle;    
        sampleCircle.init(mouseX+ofRandom(-10, 10), mouseY+ofRandom(-10, 10), angle);
        circles.push_back(sampleCircle);
    }
    
    for (int i = 0; i < circles.size(); i++) {
        circles[i].update();
        if(circles[i].dead) {
			circles.erase( circles.begin()+i );
		}
    }
}

//--------------------------------------------------------------
void testApp::draw(){

    
    for (int i = 0; i < circles.size(); i++) {
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

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

