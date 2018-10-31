#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetFrameRate(5);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(ofColor::skyBlue);
    
   
    
    //marimo moss balls
    ofSetColor(ofColor::darkGreen);
    int width= ofGetWidth();
    int height= ofGetHeight();
    int yPos= ofRandom(height);
    ofSetCircleResolution(60);
    int color= ofRandom(3);
    for (int i = 2; i < width ; i = i + 10) // this is a for loop
    {
        //get random number inbetween 0- height
        //set yPos to that number || yPoss get that number
        int yPos = ofRandom(height);
        
        ofSetColor(ofColor::darkGreen);
        ofDrawCircle(i, yPos, 30);
        
        
        std::cout << i << std::endl;
    }
    ofSetColor(ofColor::aliceBlue);
    float centerX = ofGetMouseX();
    float centerY = ofGetMouseY();
    //    int centerX = 200;
    //    int centerY = 100;
    int bodyLength = 118;
    int bodyHeight = 74;
    
    
    ofSetColor(ofColor::blueSteel);
    
    
    // body
    
    ofDrawEllipse(centerX, centerY, bodyLength, bodyHeight);
    // tail
    int tailWidth = bodyLength/4;
    int tailHeight = bodyHeight/2;
    ofDrawTriangle(centerX-bodyLength/2, centerY,
                   centerX-bodyLength/2-tailWidth, centerY-tailHeight,
                   centerX-bodyLength/2-tailWidth, centerY+tailHeight);
    // eye
    ofSetColor(33, 33, 33);
    ofDrawEllipse(centerX+bodyLength/4, centerY, bodyHeight/5, bodyHeight/5);
    }


