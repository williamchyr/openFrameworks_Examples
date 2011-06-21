#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include "ofxVectorMath.h"

class CustomCircle {
public:
    
    float x;
    float y;
    
    float angle;
    
    int r;
    int g;
    int b;
 
    
    ofxVec2f vector;
    
    bool dead;
    
    int timer;
    
    void init(int _x, int _y, float _angle);  
    void update();
    void draw();
};

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
    
        //vector <ofPoint>   mousePoints;
    
        vector <CustomCircle>  circles;
        int numberOfParticles;
    
        float angle;
       

};

#endif
