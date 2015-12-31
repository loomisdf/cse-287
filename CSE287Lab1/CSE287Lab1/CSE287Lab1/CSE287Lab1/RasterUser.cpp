#include "RasterUser.h"

#include "MyRectangle.h"
#include "MySquare.h"
#include "RightTriangle.h"

#include "Colors.h"

/**
* Color buffer that maintains the individual pixel colors in memory
* before they are displayed on the screen.
* This object is a global variable. 
*/
ColorBuffer colorBuffer(winWidth, winHeight);

// Create the colors class
Colors colors;

// Rectangle object
MyRectangle r1;
MyRectangle r2 = MyRectangle(45, 150, 35, 100, colors.BLUE);
MyRectangle r3 = MyRectangle(300, 100, 70, 55, colors.GREEN);

RightTriangle t1 = RightTriangle(400, 200, 60, colors.BLUE);

MySquare s1 = MySquare(500, 400, 20, colors.RED);

/**
* Acts as the display function for the window. It is called every
* the window needs to be repainted.
*/
static void RenderSceneCB()
{
	// Clear the color buffer
	colorBuffer.clearColorBuffer();

	// Rendering code that updates the color buffer
	//TODO
	r1.setColor(colors.RED);

	r1.draw(colorBuffer);
	r2.draw(colorBuffer);
	r3.draw(colorBuffer);

	t1.draw(colorBuffer);

	s1.draw(colorBuffer);

	// Display the color buffer
	colorBuffer.showColorBuffer();

} // end RenderSceneCB


/**
* Resets the graphics viewport limits for full window rendering
* each time the window is resized.
*/
static void ResizeCB(int width, int height)
{
	// Size the color buffer to match the window size.
	colorBuffer.setColorBufferSize( width, height );

	// Signal the operating system to re-render the window
	glutPostRedisplay();

} // end ResizeCB


/**
* If registered as the "idle" function, this method will continously as the
* OS to repaint the window.
*/
static void animate()
{
	glutPostRedisplay();

} // end animate


int main(int argc, char** argv)
{
	// FreeGLUT and Window initialization ***********************

    // Pass any applicable command line arguments to GLUT. These arguments
	// are platform dependent.
    glutInit(&argc, argv);

	// Set the initial display mode.
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE );

	// Set the initial window size
	glutInitWindowSize( winWidth, winHeight );

	// Create a window using a string and make it the current window.
	GLuint world_Window = glutCreateWindow("2D Shapes");

	// Indicate to GLUT that the flow of control should return to the program after
	// the window is closed and the glutMainLoop is exited.
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);

	// Register event handlers using FreeGLUT commands
	glutDisplayFunc(RenderSceneCB);		
	glutReshapeFunc(ResizeCB);
	//glutIdleFunc(animate);

	// ColorBuffer initialization ***********************

	// Create a clear color for the window
	color blue (0.784, 0.784, 1.0, 1.0 );

	// Set red, green, blue, and alpha to which the color buffer is cleared.
	colorBuffer.setClearColor( blue );

	// Enter the GLUT main loop. Control will not return until the window is closed.
    glutMainLoop();

	// To keep the console open on shutdown, start the project with Ctrl+F5 instead of just F5.
	return 0;

} // end main