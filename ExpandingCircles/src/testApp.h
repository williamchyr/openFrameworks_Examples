#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"

class CustomBall {
    
public:
    CustomBall();
    
    int r;
    int g;
    int b;
    
    int x;
    int y;
    
    
    int radius;
    int lineWidth;
    int expandRate;
    int timer;
    
    bool dead;
    
    
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
    
        vector <CustomBall> circles;
        
  
    

};

#endif
