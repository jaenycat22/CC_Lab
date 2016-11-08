//
//  ParticleSystem.cpp
//  oFWeek3InClass
//
//  Created by jae kyong cheong on 11/1/16.
//
//

#include "ParticleSystem.hpp"

ParticleSystem::ParticleSystem(ofVec2f position)
: mPosition(position)
, mEmitRate(5)
, mIsAddingParticles(true)
{
    
}

//-------------------------------------
void ParticleSystem::update(ofVec2f force){
    if (mIsAddingParticles){
        // pushing particles into the array
        for (int i = 0; i < mEmitRate; i++) {
            Particle particle(mPosition);
            mParticleList.push_back(particle);
        }
    }
    for (int i = 0; i< mParticleList.size(); i++){
        //caculating the difference between center and particle position
         ofVec2f diff = ofVec2f(abs(mParticleList[i].mPosition.x - mPosition.x),abs(mParticleList[i].mPosition.y - mPosition.y));
        
        mParticleList[i].resetForces();
        //force in here is passed from ofApp
        mParticleList[i].applyForce(force);
        //apply to the random velocity to the particle
        mParticleList[i].update(ofMap(diff.length(),0,100,10,4));
        
        if (diff.length() >= ofRandom(400, 450)) {
            //stop adding particle if the particle's diff is higher than a certain number
            mIsAddingParticles = false;
            //erase the particle if it is too far from the center
            if (mParticleList.size()> 0 ){
                mParticleList.erase(mParticleList.begin()+i);
                
            }
        }
    }
}

//---------------------------------

            void ParticleSystem::draw(){
                for (int i= 0; i< mParticleList.size(); i++){
                    mParticleList[i].draw();
                }
            }
