//
//  Particle.h
//  FirstCinderProject
//
//  Created by William Field on 1/19/16.
//
//
//pragma once - only include this header once when compiled
#pragma once
//include cinder headers
#include <cinder/gl/gl.h>
#include <cinder/Vector.h>
#include "Obstacle.h"
//declare class & member vars
class Particle{
    public:
        Particle();
        Particle(ci::vec2 location,ci::vec2 tLocation, float rSeed,std::vector<Obstacle*> obs);
        ci::vec2 toTarget;
        void run();
        void update();
        void display();
        void reset();
    
        ci::vec2 mLocation;
        std::vector<ci::vec2> steps;
        ci::vec2 targetLocation;
        ci::vec2 _location;
    
        Color8u pColor;
    
        std::vector<Obstacle*> _obs;
    
    private:
        int stepPlace;
        int NUMSTEPS;
        int STEPSIZE;
        float distToTarget;
};
