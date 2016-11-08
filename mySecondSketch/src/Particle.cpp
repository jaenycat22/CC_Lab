//
//  Particle.cpp
//  oFWeek3InClass
//
//  Created by jae kyong cheong on 11/1/16.
//
//

#include "Particle.hpp"
//using the constructor to initialize all the variables
Particle::Particle(ofVec2f position)
:mPosition(position)
, mVelocity(ofRandom(-5.f, 5.f), ofRandom(-5.f, 5.f))
, mAcceleration(ofVec2f(0))
, mLifeSpan(255.f){
    
}



//---------------------------------------------
void Particle::resetForces(){
    //reset the acceleration
    mAcceleration *= -1;
}

//-----------------------------------------

void Particle::applyForce(ofVec2f force){
    //adding for to acceleration
    mAcceleration += force;
}

//----------------------------------------
void Particle::update(float multiplier){
//apply acceleration to velocity
    mVelocity += mAcceleration;
    mPosition += mVelocity * multiplier;

//decreasing the particle life
    if (mLifeSpan > 0){
        mLifeSpan -= 4.f;
    }
}
//-------------------------------------
void Particle::draw(){
    if(mLifeSpan > 100){
        //new particles will be brighter
        ofSetColor(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255));
        ofDrawBox(mPosition, 5.f * ofMap(mLifeSpan, 0 , 55.f, 0, 1.f));
       
        
    }else if (mLifeSpan <= 100){
        //do some sparkling!
        ofSetColor(ofRandom(0,255));
        ofDrawCircle(mPosition, 1.f * ofMap(mLifeSpan, 0 , 100.f, 0, 1.f));
        
    };
    //closer particle is smaller
    ofDrawCircle(mPosition, 4.f * ofMap(mLifeSpan, 0 , 255.f, 0, 1.f));
    
        }

//--------------------
