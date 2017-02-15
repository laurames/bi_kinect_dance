#pragma once

#include "ofMain.h"
#include "ofxOsc.h"
#include "ofxOpenCv.h"
#include "ofxKinect.h"


#define PORT 12345

// This should install the Kinect camera, motor, & audio drivers.
//
// You CANNOT use this driver and the OpenNI driver with the same device. You
// will have to manually update the kinect device to use the libfreenect drivers
// and/or uninstall/reinstall it in Device Manager.
//
// No way around the Windows driver dance, sorry.

// uncomment this to read from two kinects simultaneously
//#define USE_TWO_KINECTS

class ofApp : public ofBaseApp {
public:
    
    void setup();
    void update();
    void draw();
    void exit();
    
    void drawPointCloud();
    
    void keyPressed(int key);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void gotMessage(ofMessage msg);
    
    ofxOscReceiver receive;
    float alpha1 = 0.0;
    float alpha2 = 0.0;
    float attention = 0.0;
    float beta1 = 0.0;
    float beta2 = 0.0;
    float blink = 0.0;
    float contact = 0.0;
    float delta = 0.0;
    float gamma1 = 0.0;
    float gamma2 = 0.0;
    float meditation = 0.0;
    float raw = 0.0;
    float theta = 0.0;
    float total = 0.0;
    
    ofImage bg;
    ofxKinect kinect;
    ofMesh mesh;
    vector<ofVec3f> offsets;
    
#ifdef USE_TWO_KINECTS
    ofxKinect kinect2;
#endif
    
    ofxCvColorImage colorImg;
    
    ofxCvGrayscaleImage grayImage; // grayscale depth image
    ofxCvGrayscaleImage grayThreshNear; // the near thresholded image
    ofxCvGrayscaleImage grayThreshFar; // the far thresholded image
    
    ofxCvContourFinder contourFinder;
    
    bool bThreshWithOpenCV;
    bool bDrawPointCloud;
    
    int nearThreshold;
    int farThreshold;
    
    int angle;
    
    vector<ofPolyline> contourPoly;
    
    // used for viewing the point cloud
    ofEasyCam easyCam;
};
