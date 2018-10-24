#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    
    grabber.setup(640, 400);
    
    
    grabberPix.allocate(grabber.getWidth(), grabber.getHeight(), OF_PIXELS_RGB);
    texture.allocate(grabber.getWidth(), grabber.getHeight(), GL_RGB);
    //------------
    gw = grabber.getWidth();
    gh = grabber.getHeight();
    
    grabberPix.allocate(gw, gh, OF_PIXELS_RGB);
    texture.allocate(gw, gh, GL_RGB);
}

//--------------------------------------------------------------
void ofApp::update()
{
    
    float noiseStep = 0.02;
    grabber.update();
    
    if (grabber.isFrameNew())
    {
        grabberPix=grabber.getPixels();
        
        for(int x= 0;x< grabberPix.getWidth();x++)
        {
            for(int y=0; y< grabberPix.getHeight();y++)
            {
                
               
                float noiseValue = ofNoise((x+ofGetMouseX())* noiseStep);
        
                int displacedX = x + (noiseValue * grabberPix.getWidth());
                
                
                displacedX =  ofWrap(displacedX, 0, grabberPix.getWidth());
                
               
                ofColor displacedColor= grabber.getPixels().getColor(displacedX,y);
                
             
                grabberPix.setColor(x, y, displacedColor);
                
                //--------------------------------------------------------------
                
                float threshold = 150;
                grabber.update();
                
                if (grabber.isFrameNew())
                {
                    grabberPix = grabber.getPixels();
                    
                    for (int x = 0; x < gw; x++)
                    {
                        for (int y= 0; y < gh; y++)
                        {
                            
                            ofColor pixelColor = grabberPix.getColor(x, y);
                            float brightness = pixelColor.getBrightness();
                            
                            
                            if (brightness > threshold)
                            {
                                
                                grabberPix.setColor(x, y, ofColor(255));
                            }
                            else
                            {
                                
                                grabberPix.setColor(x, y, ofColor(0));
                            }
                            
                        }
                    }
                }
                
              
            }
        }
    }
    texture.loadData(grabberPix);
}

//--------------------------------------------------------------
void ofApp::draw()
{
    ofBackground(ofColor::lightPink);
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2 + grabber.getWidth()/2, ofGetHeight()/2-grabber.getWidth()/2);
    

    ofScale(-2, 2,2);
 
    texture.draw(0,0);
    
    ofPopMatrix();
    
    
    
    for (int x = 0; x< grabberPix.getWidth();x +=15)
    {
        for (int y = 0; y< grabberPix.getHeight();y+=20)
        {
            ofColor pixelColor = grabberPix.getColor(x,y);
            float brightnessValue = pixelColor.getBrightness();
            
            brightnessValue = ofMap(brightnessValue,0,255,0,15);
            ofSetColor(pixelColor);
            ofFill();
            ofDrawCircle(x, y, brightnessValue);
            
            
        }
    }
    
    
    
    
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
