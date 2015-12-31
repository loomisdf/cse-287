#include "Lab5.h"

#include "RayTracer.h"
#include "MyPolygon.h"
#include "Paraboloid.h"

// Globals

// For calculating frame rate
int totalFrames = 0;

#define winWidth 700
#define winHeight 500

ColorBuffer colorBuffer(winWidth, winHeight);

RayTracer rayTrace(colorBuffer);

vector<Surface*> surfaces;

Sphere redBall(vec3(0.0f, -0.5f, -10.0f), 1.5f, color(0.8f, 0.3f, 0.3f, 1.0f));
Sphere blueBall(vec3(3.0f, 0.0f, -12.0f), 2.0f, color(0.0f, 0.0f, 1.0f, 1.0f));
Sphere greenBall(vec3(-2.5f, -1.0f, -11.0f), 1.0f, color(0.1f, 1.0f, 0.02f, 1.0f));
Plane pl(vec3(0.0f, -2.0f, 0.0f), normalize(vec3(0.0f, 1.0f, 0.0f)), color(0.5f, 0.3f, 0.0f, 1.0f));
Paraboloid paraboloid(vec3(-3.0f, 2.0f, -8.0f), 2.0f, color(1.0f, 0.4f, 0.0f, 1.0f));

// Create an arbitrary polygon
vec3 p1(-4.0f, 2.5f, -8.0f);
vec3 p2(-4.2f, 0.0f, -8.0f);
vec3 p3(-1.5f, -0.5f, -8.0f);
vec3 p4(-1.3f, 1.0f, -8.0f);
MyPolygon polygon({ p1, p2, p3, p4 }, normalize(cross(p2 - p1, p3 - p2)), color(0.4f, 0.0f, 1.0f, 1.0f));


vector<LightSource*> lights;

LightSource ambientLight(color(0.25, 0.25, 0.25, 1.0));
PositionalLight lightPos(vec3(15, 15, 2), color(.75, .75, .75, 1));
DirectionalLight dLight(vec3(0, 5, 0), color(.75, .75, .75, 1.0));

/**
* Acts as the display function for the window. 
*/
static void RenderSceneCB()
{
	// Clear the color buffer
	//colorBuffer.clearColorBuffer( );

	rayTrace.raytraceScene( surfaces , lights );

	// Display the color buffer
	colorBuffer.showColorBuffer();

	totalFrames++;

} // end RenderSceneCB


// Reset viewport limits for full window rendering each time the window is resized.
// This function is called when the program starts up and each time the window is 
// resized.
static void ResizeCB(int width, int height)
{
	// Size the color buffer to match the window size.
	colorBuffer.setColorBufferSize( width, height );

	rayTrace.setCameraFrame(vec3(0, 0, 0), vec3(0, 0, -1), vec3(0, 1, 0) );

	rayTrace.calculatePerspectiveViewingParameters(45.0f);

	// Signal the operating system to re-render the window
	glutPostRedisplay();

} // end ResizeCB


// Responds to 'f' and escape keys. 'f' key allows 
// toggling full screen viewing. Escape key ends the
// program. Allows lights to be individually turned on and off.
static void KeyboardCB(unsigned char key, int x, int y)
{
	switch(key) {

	case('f'): case('F') : // 'f' key to toggle full screen
		glutFullScreenToggle();
		break;
	case(27): // Escape key
		glutLeaveMainLoop();
		break;
	default:
		cout << key << " key pressed." << endl;
	}
	glutPostRedisplay();

} // end KeyboardCB


// Responds to presses of the arrow keys
static void SpecialKeysCB(int key, int x, int y)
{
	switch(key) {
	
	case(GLUT_KEY_RIGHT):
		
		break;
	case(GLUT_KEY_LEFT):
		
		break;
	default:
		cout << key << " key pressed." << endl;
	}
	glutPostRedisplay();

} // end SpecialKeysCB


void buildScene()
{
	surfaces.push_back(&redBall);
	surfaces.push_back(&blueBall);
	surfaces.push_back(&greenBall);
	surfaces.push_back(&pl);
	//surfaces.push_back(&polygon);
	//surfaces.push_back(&paraboloid);

	lights.push_back(&lightPos);
	//lights.push_back(&ambientLight);
	lights.push_back(&dLight);
}


// Register as the "idle" function to have the screen continously
// repainted. Due to software rendering, the frame rate will not
// be fast enough to support motion simulation
static void animate()
{
	glutPostRedisplay();

} // end animate


int main(int argc, char** argv)
{
	// freeGlut and Window initialization ***********************

    // Pass any applicable command line arguments to GLUT. These arguments
	// are platform dependent.
    glutInit(&argc, argv);

	// Set the initial display mode.
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE );

	// Set the initial window size
	glutInitWindowSize( winWidth, winHeight );

	// Create a window using a string and make it the current window.
	GLuint world_Window = glutCreateWindow("Ray Trace");

	// Indicate to GLUT that the flow of control should return to the program after
	// the window is closed and the GLUTmain loop is exited.
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);

	// Callback for window redisplay
	glutDisplayFunc(RenderSceneCB);		
	glutReshapeFunc(ResizeCB);
	glutKeyboardFunc(KeyboardCB);
	glutSpecialFunc(SpecialKeysCB);

	// Request that the window be made full screen
	//glutFullScreenToggle();

	color blue (0.784, 0.784, 1.0, 1.0 );

	// Set red, green, blue, and alpha to which the color buffer is cleared.
	colorBuffer.setClearColor( blue );

	//calculateOrthographicViewingParameters();

	rayTrace.calculatePerspectiveViewingParameters();

	buildScene();

	int startTime = glutGet( GLUT_ELAPSED_TIME ); // Get start time

	// Enter the GLUT main loop. Control will not return until the window is closed.
    glutMainLoop();

	int endTime = glutGet( GLUT_ELAPSED_TIME ); // Get end time

	float totalTimeSec = (endTime - startTime) / 1000.0f;

	cout << totalFrames/totalTimeSec  << " fps" << endl;

	// To keep the console open on shutdown, start the project with Ctrl+F5 instead of just F5.

	return 0;

} // end main