#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    ofImage image;
    image.load("B.jpg");
    
    for ( int y =0; y < image.getHeight(); y += 4)
    {
        for(int x=0; x< image.getWidth(); x+=4)
        {
            ofColor pixelColor;
            pixelColor = image.getColor(x, y);
            
            Particle p;
            p. position = glm::vec3(x,y,0);
            p. velocity = glm::vec3(0.001,0,0);
            p. radius = ofRandom(2,6);
            p.color = ofColor(pixelColor,100);
            
            
            particles.push_back(p);
        }
    }
}

//--------------------------------------------------------------
void ofApp::update()
{
    glm::vec3 mousePos(ofGetMouseX(), ofGetMouseY(), 0);
    
    for (auto &p : particles)
    {
        float dragCo = 0.01;
        glm::vec3 dragMagnitude = (p.velocity * p.velocity) * dragCo;
        glm::vec3 dragDirection = glm::normalize(p.velocity) * -1;
        
        glm::vec3 drag = dragMagnitude * dragDirection;
        
        //----------------------------------------------------------------
        
        glm::vec3 gravityForce = computeGravity(p, mousePos);
        
        float distance = glm::distance(mousePos, p.position);
        glm::vec3 directionVec = mousePos- p.position;
        glm::vec3 direction = glm::normalize(directionVec);
        
        float magnitude = distance * 0.09;
        
        gravityForce = magnitude * direction* forceDirection;
        
        //-------------------------------------------------------------------
        
        glm::vec3 awesomeGravityForce;
        awesomeGravityForce = computeGravity(p, mousePos)*forceDirection;
        p.applyForce(awesomeGravityForce);
        
        
        
        if (ofGetMousePressed())
        {
            p.applyForce(awesomeGravityForce);
        }
        
        p.applyForce(drag); //apply drag every frame
        p.update();
    }
}

glm::vec3 ofApp::computeGravity(Particle &part, glm::vec3 &attractor)
{
    float gravityConst = 10;
    
    glm::vec3 direction = glm::normalize(attractor - part.position);
    
   
    float distance = glm::distance(attractor, part.position);
  
    distance = ofClamp(distance, 5, 25);
    
   
    float magnitude = (gravityConst * part.mass) / (distance * distance);
    
    
    glm::vec3 gravity = direction * magnitude;
    
    
    return gravity;
}

//--------------------------------------------------------------
void ofApp::draw()
{
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    ofBackground((ofColor::lightPink));
    
    for (auto &p : particles)
    {
        p.draw();
    }
    
    ofPushStyle();
    string frameString = "FrameRate = " + ofToString(ofGetFrameRate());
    ofDrawBitmapString(frameString, 30, 20);
    
    string particleString = "Particle Number = " + ofToString(particles.size());
    ofDrawBitmapString(particleString, 20, 40);
    ofPopStyle();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    if (key == 'q')
    {
        forceDirection = 1;
        
    }
    if (key == 'w')
    {
        forceDirection = -1;
        
    }
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
