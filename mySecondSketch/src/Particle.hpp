//
//  Particle.hpp
//  oFWeek3InClass
//
//  Created by jae kyong cheong on 11/1/16.
//
//

#pragma once
#include "ofMain.h"

class Particle{
public:
    //creating a constructor
    Particle(ofVec2f pos);
    
    void resetForces();
    void applyForce(ofVec2f force);
    void update(float multiplier);
    void draw();
    ofImage star;
    ofVec2f mPosition, mVelocity, mAcceleration;
    float mLifeSpan;
};
