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
//declare class & member vars
class Particle{
    public:
        Particle();
        Particle(ci::vec2 location);
        
        void run();
        void update();
        void display();
        
        ci::vec2 mLocation;
        std::vector<ci::vec2> steps;
    ci::vec2 targetLocation;
    
    private:
        int stepPlace;
        int NUMSTEPS;
        int STEPSIZE;
    float distToTarget;
};
