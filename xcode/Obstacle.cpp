//
//  Obstacle.cpp
//  learnPath
//
//  Created by William Field on 1/23/16.
//
//

#include "Obstacle.h"
#include "cinder/Rand.h"
#include "cinder/app/App.h"

using namespace ci;
using namespace ci::app;

Obstacle::Obstacle()
{
    location = vec2(randFloat(getWindowWidth()),randFloat(getWindowHeight()));
};

void Obstacle::display(){
    gl::color(255,255,255);
    gl::drawSolidRect(Rectf(location.x-5,location.y-5,location.x+5,location.y+5));
};
