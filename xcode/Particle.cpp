//Users/willjfield/Desktop/Projects/ITP/Unconference_16/cinder_0.9.0_mac/myProjects/FirstCinderProject/xcode/FirstCinderProject.xcodeproj/
//  Particle.cpp
//  FirstCinderProject
//
//  Created by William Field on 1/19/16.
//
//
#include "Particle.h"
#include "cinder/Rand.h"
#include "cinder/cinderMath.h"

using namespace ci;
using namespace ci::app;

Particle::Particle()
{
};

Particle::Particle(ci::vec2 location)
{
    NUMSTEPS = getWindowWidth()*2;
    STEPSIZE = 5;
    targetLocation = vec2(getWindowWidth()-50,randFloat(getWindowHeight()));
    
    stepPlace = 0;
    for (int i =0; i<NUMSTEPS; i++) {
        randSeed(i+1*time(0));
        float randY = randFloat(-STEPSIZE,STEPSIZE);
        float randX = randFloat(-STEPSIZE*.9,STEPSIZE);
        //float randX = 1.0;
        vec2 randVec = vec2(randX,randY);
        steps.push_back(randVec);
    }
    mLocation = location;
};

void Particle::run()
{
    update();
    display();
};

void Particle::update()
{
    if(stepPlace<NUMSTEPS){
        stepPlace++;
    }else{
        stepPlace = 0;
        vec2 toTarget = vec2(glm::abs(targetLocation.x-mLocation.x),glm::abs(targetLocation.y-mLocation.y));
        distToTarget=glm::sqrt((toTarget.x*toTarget.x)+(toTarget.y*toTarget.y));
        std::cout << distToTarget << std::endl;
    }
    mLocation+=steps[stepPlace];
};

void Particle::display()
{
    gl::drawSolidCircle(mLocation, 3.0, 8);
    gl::drawStrokedCircle(targetLocation, 20);
};
