#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    b1.load("b1.png");
    
    ofSetBackgroundAuto(false);
    
    ofBackground(128);
    
    mCamWidth = 320;
    mCamHeight = 240;
    
    mVidGrabber.setDeviceID(0);
    mVidGrabber.setDesiredFrameRate(60); // if you get an error, you need to change setDesiredFrameRate to 29.97
    mVidGrabber.initGrabber(mCamWidth,mCamHeight);
    
    mColorImg.allocate(mCamWidth, mCamHeight);
    mGrayImage.allocate(mCamWidth,mCamHeight);
    mGrayBg.allocate(mCamWidth,mCamHeight);
    mGrayDiff.allocate(mCamWidth,mCamHeight);
    
                       mThreshold = 80;
                       mLearnBackground = true;

}

//--------------------------------------------------------------
void ofApp::update(){
    mVidGrabber.update();
    //Only do this when there is a new frame from webcam.
    if (mVidGrabber.isFrameNew()){
    //Convert the webcam to openCV format.
        mColorImg.setFromPixels(mVidGrabber.getPixels());
    //Convert ofxCvColorImage to ofxCVGrayscaleImage( 3 channels -> 1 channel}
        mGrayImage = mColorImg;
        
        if(mLearnBackground == true){//need to update difference background
            mGrayBg = mGrayImage;
            mLearnBackground = false;
        }
        //Take the absolute value of the diffrence between backgorund and current frame and then threshold
        mGrayDiff.absDiff(mGrayBg,mGrayImage);
        mGrayDiff.threshold(mThreshold); //Pixels that have value >= mThreshold become white(255); others become black(0).
        
        //Find contours which are between the size of 20pixels and 1/3 the w*h pixels.
        //Also, find holes set to true so we will get interior contours as well.
        mContourFinder.findContours(mGrayDiff,20, (340*240)/3, 10, true);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    

    //First draw background
    
    ofFill();
    ofSetColor(0);
    ofDrawRectangle(360, 540, 320, 240);
    ofSetColor(255);
    
    //Then draw blobs
    mContourFinder.draw(360,540);
    
    //Nowdraw blobs over webcam image.
    //First draw webcam image
    mVidGrabber.draw(20, 540);
    
    //Then draw blobs. This time we will draw each blob individually from the blobs vector. This is how to get access to them. You can use the blob data to do interesting things.
    for(int i=0; i< mContourFinder.nBlobs; i++){
        mContourFinder.blobs[i].draw(20,540);
        
        //Draw text over the centroid if the blob is a hole
        ofSetColor(255);

        if(mContourFinder.blobs[i].hole){
            ofDrawBitmapString("hole", mContourFinder.blobs[i].boundingRect.getCenter().x +20, mContourFinder.blobs[i].boundingRect.getCenter().y +540);
            ofDrawCircle(mContourFinder.blobs[i].boundingRect.getCenter().x +150, mContourFinder.blobs[i].boundingRect.getCenter().y +70,30);
            ofSetColor(300,140, 200);
            ofDrawEllipse(mContourFinder.blobs[i].boundingRect.getCenter().x +200, mContourFinder.blobs[i].boundingRect.getCenter().y +200,5,5);
            ofSetColor((int)ofRandom(0,255),(int)ofRandom(0,250),(int)ofRandom(0,100));
            ofDrawBox(mContourFinder.blobs[i].boundingRect.getCenter().x +50, mContourFinder.blobs[i].boundingRect.getCenter().y +250,mContourFinder.blobs[i].boundingRect.getCenter().z +30,30);
            b1.draw(mContourFinder.blobs[i].boundingRect.getCenter().x +250, mContourFinder.blobs[i].boundingRect.getCenter().y +150,30,30);
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    //use space key to update difference background --before the background was always the first frame)
    switch(key){
            case' ':
            mLearnBackground = true;
            break;
            
//use s key to save a snapshot image to the disk the image will be saved to bin/data floder in your project folder.
    
    case's':
    ofImage snapshot;
    snapshot.allocate(ofGetWindowWidth(), ofGetWindowHeight(),OF_IMAGE_COLOR);
    snapshot.grabScreen(0,0,ofGetWindowWidth(),ofGetWindowHeight());
    snapshot.save("snapshot.png");
    break;
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
