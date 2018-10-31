#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetRectMode(OF_RECTMODE_CENTER);
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    ofSetLineWidth(5);
    ofSetColor(255, 0, 0);
    ofNoFill();
    //    ofSeedRandom(23);
    
    
    

    rotation = rotation + 1;
    
//        for (int x = 0; x<ofGetWidth(); x+=50)
//        {
//            for (int y = 0; y<ofGetHeight(); y+=50)
//            {
//                ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
//                ofNoFill();
//                ofDrawRectangle(x, y, 50, 50);
//            }
//        }
    
    
    for (int x = -ofGetWidth(); x<ofGetWidth(); x+=150)
    {
        for (int y = -ofGetHeight(); y<ofGetHeight(); y+=150)
        {
            ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
            ofNoFill(); //ofFIll 十分沙雕
            ofPushMatrix();
            ofTranslate(x, y);
            ofRotateZDeg(rotation);
            ofDrawRectangle(0, 0, 100, 100);
            ofPopMatrix();
        }
    }
    
    
    if (rotation > 360)
    {
        rotation = 0;
    }
    
    
    
    for (int x = -ofGetWidth(); x<ofGetWidth(); x+=150)
    {
        for (int y = -ofGetHeight(); y<ofGetHeight(); y+=150)
        {
            ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
            ofNoFill();
            ofPushMatrix();
            ofTranslate(x, y);
            ofDrawRectangle(0, 0, 100, 100);
            //ofDrawRectangle(0, 0, ofRandom(50,100), ofRandom(50,100));
            ofPopMatrix();
        }
    }
    
    if (rotation > 360)
    {
        rotation = 0;
    }
    //---------------------------------------------------------
//        for (int x = -ofGetWidth(); x<ofGetWidth(); x+=200)
//        {
//            for (int y = -ofGetHeight(); y<ofGetHeight(); y+=150)
//            {
//                ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
//                ofNoFill();
//                ofPushMatrix();
//                ofTranslate(400, 400);
//                ofRotateZDeg(15);
//                ofDrawRectangle(x, y, 100, 100);
//                ofPopMatrix();
//                glBegin(27);
//            }
//        }
//        for (int x = -ofGetWidth(); x<ofGetWidth(); x+=200)
//        {
//            for (int y = -ofGetHeight(); y<ofGetHeight(); y+=150)
//            {
//                ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
//                ofNoFill();
//                ofPushMatrix();
//                ofTranslate(400, 400);
//                ofRotateZDeg(45);
//                ofDrawRectangle(x, y, 100, 100);
//                ofPopMatrix();
//
//            }
//        }
//    //
    //    for (int x = -ofGetWidth(); x<ofGetWidth(); x+=200)
    //    {
    //        for (int y = -ofGetHeight(); y<ofGetHeight(); y+=150)
    //        {
    //            ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
    //            ofNoFill();
    //            ofPushMatrix();
    //            ofTranslate(400, 400);
    //            ofRotateZDeg(50);
    //            ofDrawRectangle(x, y, 100, 100);
    //            ofPopMatrix();
    //        }
    //    }
    //    for (int x = -ofGetWidth(); x<ofGetWidth(); x+=200)
    //    {
    //        for (int y = -ofGetHeight(); y<ofGetHeight(); y+=150)
    //        {
    //            ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
    //            ofNoFill();
    //            ofPushMatrix();
    //            ofTranslate(400, 400);
    //            ofRotateZDeg(-45);
    //            ofDrawRectangle(x, y, 100, 100);
    //            ofPopMatrix();
    //        }
    //    }
    //    for (int x = -ofGetWidth(); x<ofGetWidth(); x+=200)
    //    {
    //        for (int y = -ofGetHeight(); y<ofGetHeight(); y+=150)
    //        {
    //            ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
    //            ofNoFill();
    //            ofPushMatrix();
    //            ofTranslate(400, 400);
    //            ofRotateZDeg(-50);
    //            ofDrawRectangle(x, y, 100, 100);
    //            ofPopMatrix();
    //        }
    //    }
    
    
}
