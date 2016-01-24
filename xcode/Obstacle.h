//
//  Obstacle.h
//  learnPath
//
//  Created by William Field on 1/23/16.
//
//
//pragma once - only include this header once when compiled
#pragma once
//include cinder headers
#include <cinder/gl/gl.h>
#include <cinder/Vector.h>

using namespace ci;
//declare class & member vars
class Obstacle{
    public:
        Obstacle();
        vec2 location;
        void display();
};