#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include "ofx3DUtils.h"

//--------------------------------------------------------------
class OrbitingSphere {
    
    public:
    
    int orbitalRadius;
    int sphereRadius;
    
    int x;
    int y;
    int z;   
    
    int yShift;
    int angleShift;
    
    void init();
    void update(float &angle);
    void draw();
    
};

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
	
    
    vector <OrbitingSphere>   moonSeries;
    
	float centerX, centerY, centerZ;
	float rotX, rotY;
	
	bool bSmoothLight;
	float camX, camY, camZ;
    
    float angle;
   
	
};

#endif
	
