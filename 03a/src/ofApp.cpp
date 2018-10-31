#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
       ofSetFrameRate(5);
    img1.load("img1.png");
}


//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(ofColor::whiteSmoke);

    for (int x = -ofGetWidth(); x<ofGetWidth(); x+=150)
    {
        for (int y = -ofGetHeight(); y<ofGetHeight(); y+=150)
        {
            ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
            ofNoFill(); //ofFIll 十分沙雕
            ofPushMatrix();
            ofTranslate(x, y);

    int seconds = ofGetSeconds();
    int minutes = ofGetMinutes();
    int hours = ofGetHours();
    
 
    
    float sDegree = ofMap(seconds,0,60,0,360);
    float mDegree = ofMap(minutes,0,60,0,360);
    float hDegree = ofMap(hours, 0, 24, 0, 720);
   
            

    ofPushMatrix();
    
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    //ofRotateZDeg(180);
      ofPushMatrix();
            ofRotateZDeg(sDegree+180);
            img1.draw(0,300,100,100);
    
      ofSetLineWidth(1);
      ofSetColor(ofColor::hotPink);
      ofDrawLine(0, 0, 0, 300);
    
      ofPopMatrix();
      ofPushMatrix();
      ofRotateZDeg(mDegree+180);
      ofSetColor(ofColor::purple);
      ofSetLineWidth(3);
      ofDrawLine(0, 0, 0, 250);
      ofPopMatrix();
    
    
      ofPushMatrix();
      ofRotateZDeg(hDegree+180);
            ofSetColor(ofColor::yellow);
      ofSetLineWidth(5);
      ofDrawLine(0, 0, 0, 200);
      ofPopMatrix();
    
   
    
//    ofPushMatrix();
//    ofDrawCircle(0, 0, 350);
//    ofNoFill();
//    ofSetColor(ofColor::lightBlue);
//    ofSetLineWidth(2);
//    ofPopMatrix();
//
//
//    ofPopMatrix();
            
            ofPopMatrix();
        }
    }
    
    
    
    
    
    
    
    
    
//    ofSetColor(ofColor::lightBlue);
//    ofNoFill();
//
//    int width= ofGetWidth();
//    int height= ofGetHeight();
//    int yPos= ofRandom(height);
//    ofSetCircleResolution(60);
//    int color= ofRandom(3);
//    for (int i = 2; i < width ; i = i + 10) // this is a for loop
//    {
//        //get random number inbetween 0- height
//        //set yPos to that number || yPoss get that number
//        int yPos = ofRandom(height);
//
//        ofSetColor(ofColor::lightBlue);
//        ofDrawCircle(i, yPos, 30);
//
//
//        std::cout << i << std::endl;
//    }
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
