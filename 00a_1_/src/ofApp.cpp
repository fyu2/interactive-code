#include "ofApp.h"
//_Wall Drawing #327_ - On a black wall, a white trapezoid within which are white vertical parallel lines and a white square within which are white horizontal parallel lines. The vertical lines within the trapezoid do not enter the square, and the horizontal lines within the square do not enter the trapezoid.


//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw()
{
    //on a black wall
    ofBackground(0);
    
    //a white trapezoid
    
    //Get the width and height of the screen
    int width = ofGetWidth();// and int is a whole number (integer)
    int height = ofGetHeight();
    
    //Get the center of out x dimention
    //float is short for "floating point". 3.14159, 400.0
    //centerX is a float in cse I need to divide a non-even number
//    float centerX = width/2;
//    //Get the center of y
//    float centerY = height/2;
    
    //ofGetMouseX() means get the x position of our mouse
    float centerX = ofGetMouseX();
    float centerY = ofGetMouseY();
    
    //set the top witdth of the trap
    float topWitdth = 300;
    //set the bottom witdth of the trap
    float bottomWidth = 600;
    //set the height of the trap
    float trapheight = 500;
    
    //my four points of the trap
    //vec2(x,y)
    glm::vec2 p0;
    glm::vec2 p1;
    glm::vec2 p2;
    glm::vec2 p3;
    
    //set the coord of p0
    p0.x = centerX - topWitdth/2;
    p0.y = centerY -  trapheight/2;
    
    //ditto for the resr
    p1.x = centerX + topWitdth/2;
    p1.y = centerY - trapheight/2;
    
    p2.x = centerX + bottomWidth/2;
    p2.y = centerY + trapheight/2;
    
    p3.x = centerX - bottomWidth/2;
    p3.y = centerY + trapheight/2;
    
    //print to the console my foir points, all on one line
    //at thet end, start a new line. // cout is part of the std:: library
//    std::cout << p0 << " " << p1 <<
//      " "<< p2 << " " << p3 <<std::endl;

    //draw lines connecting the points
    //dont fill anything in
    ofNoFill();
    //set my "line" color to white
    ofSetColor(255);
    
    //now draw the lines
    ofDrawLine(p0,p1);
    ofDrawLine(p1,p2);
    ofDrawLine(p2,p3);
    ofDrawLine(p3,p0);
    
    //"within which are white vertical parallel lines...."
    
    //this is space between each line
    int spacing = 10;
    
    //set the coord for wher the vertical line will satart and end on the x-axis
    int lineStart = (centerX - bottomWidth/2)+1;
    int lineEnd = centerX + bottomWidth/2;
    //for loop whatever ia inside the brackets
    //get exexuted as long as the middle statement in TRUE
    for(int x = lineStart ; x < lineEnd; x += spacing)
    {
    //we will use x to set the x position of our vertical line
    ofDrawLine(x, centerY-trapheight/2, x, centerY + trapheight/2);
    }
    
    ofFill();
    ofSetColor(0);
    
    //make a mask point from where p3 is one the x-axis
    //and where p0 is one the y-axis
    glm::vec2 maskLeft(p3.x, p0.y);
    ofDrawTriangle(p0, p3, maskLeft);
    
    glm::vec2 maskRight(p2.x, p1.y);
    ofDrawTriangle(p1, p2, maskRight);
    
    //---------------------------------
    // a white square
    //---------------------------------
    ofSetRectMode(OF_RECTMODE_CENTER);
    //set the size of square
    int squareSize = 200;
    //reate the satring point of the square
    glm::vec2 rectPoint(centerX,centerY);
    
    //draw the square out line
    
    ofSetColor(255);
    ofDrawRectangle(rectPoint,squareSize+2,squareSize+2);
    
    //draw the square mask
    ofSetColor(255);
    ofFill();
    ofSetColor(0);
    ofDrawRectangle(rectPoint,squareSize,squareSize);
    
    
    //-----
    //within which are white horizontal parallel lines///
    //------
    int hLineStart = centerY - squareSize/2;
    int hLineEnd = centerY + squareSize/2;
    
    for(int i = hLineStart; i < hLineEnd; i += spacing)
    {
        ofSetColor(255);
        ofDrawLine(centerX - squareSize/2 , i, centerX + squareSize/2 ,i);
    }
    
    
    
    
    
    
    
    
    
    
    //draw a circle at the center point just for reference
    glm::vec2 center(centerX, centerY);
    //set to fill in the shape
    ofFill();
    //set the color to red
    ofSetColor(255,0, 0);
    //now draw the shape
    ofDrawCircle(center, 5);
    
    
    
    
    //within which are white vertical parallel lines
    
    

}

