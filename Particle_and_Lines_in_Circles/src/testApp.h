#ifndef CONTACT_APP
#define CONTACT_APP

#include "ofMain.h"
#include "Particle.h"
#include "ParticleSystem.h"



//--------------------------------------------------------------

class testApp : public ofSimpleApp
{
public:
	
	void setup	();
	void update	();
	void draw	();
	
	
	void keyPressed		(int key);
	void keyReleased	(int key);
	void mousePressed	(int x, int y, int button);
	void mouseMoved		(int x, int y );
	void mouseDragged	(int x, int y, int button);
	void mouseReleased	(int x, int y, int button);

	void windowResized	(int w, int h);

    
    ParticleSystem              ps;
    
};

#endif