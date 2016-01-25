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
#include "cinder/Vector.h"

using namespace ci;
using namespace ci::app;

Particle::Particle()
{
};

Particle::Particle(ci::vec2 location, ci::vec2 tLocation, float rSeed, std::vector<Obstacle*> obs)
{
    NUMSTEPS = (getWindowWidth()+getWindowHeight())*2;
    STEPSIZE = 1;
    pColor = Color8u(randFloat(0, 255),randFloat(0, 255),randFloat(0, 255));
    
    Rand::randomize();
    _location = location;
    targetLocation = tLocation;
    stepPlace = 0;
    _obs = obs;
    for (int i =0; i<NUMSTEPS; i++) {
        Rand::randomize();
        float randY = randFloat(-STEPSIZE,STEPSIZE);
        float randX = randFloat(-STEPSIZE,STEPSIZE);
        vec2 randVec = vec2(randX,randY);
        steps.push_back(randVec);
    }
    mLocation = *new vec2(_location);
};

void Particle::run()
{
    update();
    display();
};

void Particle::update()
{
    toTarget = vec2(targetLocation.x-mLocation.x,targetLocation.y-mLocation.y);
    float dist2 = (toTarget.x*toTarget.x)+(toTarget.y*toTarget.y);
    float dist = sqrtf(dist2);
    if(dist>20.0){
        if(stepPlace<NUMSTEPS){
            stepPlace++;
            distToTarget = (toTarget.x*toTarget.x)+(toTarget.y+toTarget.y);
            distToTarget = sqrtf(distToTarget);
            for(int o = 0;o<_obs.size();o++){
                vec2 toObs = vec2(_obs[o]->location.x-mLocation.x,_obs[o]->location.y-mLocation.y);
                float dist = sqrtf((toObs.x*toObs.x)+(toObs.y*toObs.y));
                dist *= dist;
                if(dist < 50){
                    for (int i =stepPlace-int(stepPlace/10); i<stepPlace; i++){
                        Rand::randomize();
                        steps.at(i).x = randFloat(-1.0,1.0);
                        steps.at(i).y = randFloat(-1.0,1.0);
                    }
                    mLocation = *new vec2(_location);
                    stepPlace = 0;
                }
            }
        }else{
            stepPlace = 0;
            reset();
        }
            mLocation+=steps[stepPlace];
    }

};

void Particle::display()
{
    gl::color(pColor);
    gl::drawSolidCircle(mLocation, 3.0, 8);
    gl::drawStrokedCircle(_location, 3.0, 8);
};

void Particle::reset()
{
	gl::clear( Color( 0, 0, 0 ) );
    float amntToChangeX = toTarget.x/2000;
    float amntToChangeY = toTarget.y/2000;
    for (int i =0; i<NUMSTEPS; i++){
        Rand::randomize();
        steps[i].y+=randFloat(amntToChangeY);
        steps[i].x+=randFloat(amntToChangeX);
    }
   mLocation = *new vec2(_location);
    
};
