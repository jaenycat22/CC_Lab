#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundAuto(false);
    mySound.load("Creek.mp3");
        mySound.play();
    
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    //--------------------------- rectangles
    ofFill();
    for (int i = 0; i < 10; i++){
        ofSetColor((int)ofRandom(0,255),(int)ofRandom(0,10),(int)ofRandom(0,100));
        ofDrawRectangle(ofRandom(10,100),ofRandom(10,50),ofRandom(50,100),ofRandom(50,100));
        
    }


    //-------------------dynamic shape
    float xPct = (float)(mouseX) / (float)(ofGetWidth());
    float yPct = (float)(mouseY) / (float)(ofGetHeight());
    int nTips = 5 + xPct * 70;
    int nStarPts = nTips * 2;
    float angleChangePerPt = TWO_PI / (float)nStarPts;
    float innerRadius = 0 + yPct* 80;
    float outerRadius = 70;
    float origx = 300;
    float origy = 80;
    float angle = 0;
    
    for (int i = 0; i < 10; i++){
        ofSetColor((int)ofRandom(0,10),(int)ofRandom(0,10),(int)ofRandom(0,255));}
    ofBeginShape();
    for (int i = 0; i < nStarPts; i++){
        if (i % 2 == 0) {
            // inside point:
            float x = origx + innerRadius * cos(angle);
            float y = origy + innerRadius * sin(angle);
            ofVertex(x,y);
        } else {
            // outside point
            float x = origx + outerRadius * cos(angle);
            float y = origy + outerRadius * sin(angle);
            ofVertex(x,y);
        }
        angle += angleChangePerPt;
    }
    ofEndShape();
    
    //--------------draw shape in circle
    ofPushMatrix();
    ofTranslate(300,300,0);
    for (int i = 0; i < 10; i++){
        ofSetColor((int)ofRandom(0,100),(int)ofRandom(0,0),(int)ofRandom(0,100));}
    ofFill();
    ofSetPolyMode(OF_POLY_WINDING_ODD);
    ofBeginShape();
    float angleStep 	= TWO_PI/(30.0f + sin(ofGetElapsedTimef()/5.0f) * 60);
    float radiusAdder 	= 0.5f;
    float radius 		= 0;
    for (int i = 0; i < 200; i++){
        float anglef = (i) * angleStep;
        float x = radius * cos(anglef);
        float y = radius * sin(anglef);
        ofVertex(x,y);
        radius 	+= radiusAdder;
    }
    ofEndShape(OF_CLOSE);
    ofPopMatrix();
    

   	//--------------------------- circles
    //let's draw a circle:
    for (int i = 0; i < 10; i++){
        ofSetColor((int)ofRandom(0,255),(int)ofRandom(0,250),(int)ofRandom(0,100));
    ofDrawCircle(500,80,ofRandom(10,70));}
    ofFill();

   //------------------------random shape
    ofSetPolyMode(OF_POLY_WINDING_ODD);
    ofBeginShape();
    for (int i = 0; i < 40; i++){
        ofSetColor((int)ofRandom(0,0),(int)ofRandom(0,100),(int)ofRandom(0,100));
        ofVertex(ofRandom(600,800), ofRandom(20,150));
    }
    ofEndShape();
    
    //-----------------------screenshot
    ofSetHexColor(0x000000);
    ofDrawBitmapString(" press'x' for screenshot", 20,210);
    
    //-----------------------soundplay
    //-----------------------screenshot
    ofSetHexColor(0x000000);
    ofDrawBitmapString(" press'p' for play sound", 20,230);
   
    //------------------draw brush
    ofSetColor(0,140, 200);
    ofDrawEllipse(mouseX,mouseY,5,10);
    
    //-------------------
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if(key == 'x'){
        img.grabScreen(0, 0 , ofGetWidth(), ofGetHeight());
        img.save("screenshot.png");
    }
    
    if(key == 'p'){
        mySound.play();}

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
