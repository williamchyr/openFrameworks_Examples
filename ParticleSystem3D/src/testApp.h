#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include "ofx3DUtils.h"

#include "ParticleSystem.h"
#include "Particle.h"


//--------------------------------------------------------------

class testApp : public ofSimpleApp{
	
public:
	
	void setup();
	void update();
	void draw();
	
	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased();
	
	ofxCamera camera;
	
	ofxLight light1; //this will be a spot light;

	float centerX, centerY, centerZ;
	
	bool bSmoothLight;
	float camX, camY, camZ;

    
    ParticleSystem  ps;
   
	
};

#endif
	
