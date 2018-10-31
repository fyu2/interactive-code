#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
    {
        grabber.setup(648, 480);
        gw = grabber.getWidth();
        gh = grabber.getHeight();
        grayPixels.allocate(gw, gh, OF_PIXELS_GRAY);
        grayTexture.allocate(gw,gh,GL_LUMINANCE);
        
    }


//--------------------------------------------------------------
void ofApp::update()
{
    threshold = ofMap( ofGetMouseX(),0,ofGetWidth(),0,255,true);
    grabber.update();
    if (grabber.isFrameNew());
    {
        for (int x=0; x < gw ;x++)
        {
            for (int y = 0 ; y <gh; y ++)
            {
                
                int brightnessValue = grabber.getPixels().getColor(x,y).getBrightness();
                if (brightnessValue > threshold)
                {
                    grayPixels.setColor(x,y,ofColor(0));
                    
                }
                else
                {
                    grayPixels.setColor(x, y, ofColor(brightnessValue));
                    
                }
            }
        }
        grayTexture.loadData(grayPixels);
    }
}


//--------------------------------------------------------------
void ofApp::draw()
{ofBackground(25);
    int halfw= gw/2;
    int halfh= gh/2;
//        grabber.draw(0,0,halfw,halfh);
//        grayTexture.draw(halfw,0);
    
    for (int x = 0; x<gw ;x+=20)
    {
        for (int y = 0; y<gh ; y +=20)
        {
            int brightness = grayPixels.getColor(x,y).getBrightness();
            int rotation = ofMap(brightness,0,255,0,180);
            
            ofColor originalColor = grabber.getPixels().getColor(x,y);
            ofPushMatrix();
            ofTranslate(x, y);
            ofRotateXDeg(rotation);
           
            ofSetColor(originalColor);
            ofDrawAxis(rotation);
            ofDrawRectangle(0-10, 0-10, 20, 20);
            ofPopMatrix();
        }
    }
    //display our threshold value
    string threshStr= "Threshold::"+ ofToString(threshold);
    ofDrawBitmapStringHighlight(threshStr,10,10);

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
