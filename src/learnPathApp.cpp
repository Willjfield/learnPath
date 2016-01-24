#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "Particle.h"
#include "Obstacle.h"
#include "cinder/Rand.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class learnPathApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
    
    vec2 ftarget;
    
    const int NUMPARTICLES = 50;
    const int NUMOBS = 75;
    
    std::vector<Particle*> particles;
    std::vector<Obstacle*> obs;
};

void learnPathApp::setup()
{
    for(int i = 0;i<NUMOBS;i++){
        Rand::randomize();
        Obstacle* ob = new Obstacle();
        obs.push_back(ob);
    }
    
    ftarget = ci::vec2(randFloat(getWindowWidth()/2)+getWindowWidth()/4,randFloat(getWindowHeight()/2)+getWindowHeight()/4);
    
    for(int i = 0;i<NUMPARTICLES;i++){
        Rand::randomize();
        vec2 fstart = ci::vec2(randFloat(getWindowWidth()),randFloat(getWindowHeight()));
        Particle* finder = new Particle(fstart, ftarget, .1, obs);
        particles.push_back(finder);
    }

}

void learnPathApp::mouseDown( MouseEvent event )
{
}

void learnPathApp::update()
{
}

void learnPathApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) );
    
    gl::drawStrokedCircle(vec2(ftarget.x,ftarget.y), 20);
    
    for(int i = 0;i<NUMPARTICLES;i++){
        for(int j = 0;j<5;j++){
        Rand::randomize();
        particles[i]->run();
        }
    }
    
    for(int i = 0;i<NUMOBS;i++){
        Rand::randomize();
        obs[i]->display();
    }
}

CINDER_APP( learnPathApp, RendererGl )
