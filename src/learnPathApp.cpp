#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "Particle.h"
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
    
    Particle finder;
    ci::vec2 start;
    
    
};

void learnPathApp::setup()
{
    start = ci::vec2(getWindowWidth()/10,getWindowHeight()/2);
    finder = Particle(start);
    
    for(int i = 0;i<finder.steps.size();i++){
    cout<<finder.steps[i]<<endl;
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
    finder.run();
}

CINDER_APP( learnPathApp, RendererGl )
