#include "testApp.h"



//--------------------------------------------------------------
void testApp::setup(){
    
	ofBackground(0, 0, 0);
	ofSetVerticalSync(true);
	glEnable(GL_DEPTH_TEST); //lights look weird if depth test is not enabled
	centerX = ofGetWidth()/2;
	centerY = ofGetHeight()/2;
	centerZ = 0;

	bSmoothLight = true;

	//reflexions!!
	ofxMaterialSpecular(0, 120, 120); //how much specular light will be reflect by the surface
	ofxMaterialShininess(90); //how concentrated the reflexion will be (between 0 and 128

	//the light will emit white reflexions
	light1.specular(255, 255, 255);

    camera.setOrigin(OF_ORIGIN);
	camera.position(centerX, centerY, 500); //initialize the camera at a far position from the sphere

    
    
}

//--------------------------------------------------------------
void testApp::update(){
 
	//--- SET UP LIGHT
	float L2ConeAngle = 200;
	float L2Concentration = 100;
	float L2PosX = 100;
	float L2PosY = 200;
	float L2PosZ = 300;
	float L2DirectionX = 0;
	float L2DirectionY = 0;
	float L2DirectionZ = -1;

    //I've mad the light white so that it doesn't cast a hue on the objects
	light1.spotLight(255, 255, 255,
					 L2PosX, L2PosY, L2PosZ,
					 L2DirectionX, L2DirectionY, L2DirectionZ,
					 L2ConeAngle,
					 L2Concentration);
    
    
    ps.update();
   
}

//--------------------------------------------------------------
void testApp::draw(){
    
    string info = "PRESS MOUSE TO CREATE 3D PARTICLE";
	ofSetColor(255, 255, 255);
	ofDrawBitmapString(info, 20, 20);
    
	camera.place();//this MUST be inside the draw function, and actually places the camera in position

	ofxLightsOn(); //turn lights on
	
    ps.draw();

	ofxLightsOff(); //turn lights off to draw text
    


}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){
    
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
    ps.addParticle();
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
}
