#include <iostream>
#include <gl/glew.h>
#include <gl/freeglut.h>

#include <glm/glm.hpp>

using namespace std;

static void RenderSceneCB();

static void displayOpenGlInfo(void);

int main(int argc, char** argv) {
	// Pass any applicable command line arguments to GLUT. These aguments
	// are platform dependent
	glutInit(&argc, argv);

	// Create a window using a string and make it the current window
	glutCreateWindow("CSE 287 Lab0");

	// Indicate to GLUT that the flow of control should return to the program after 
	// the window is closed and the GLUTmain loop is exited.
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);

	// GLEW does not entirely support the Cor GLUT Profile out of the box.
	// The following statement fixes the problem.
	glewExperimental = GL_TRUE;

	// Initilize GLEW. This must be done after glut is initialized.
	GLenum res = glewInit();
	if (res != GLEW_OK) {
		fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
		return false; // GLEW could not be initialized.
	}

	// Callback for window redisplay
	glutDisplayFunc(RenderSceneCB);

	// Display opengl info
	displayOpenGlInfo();

	// Enter the GLUT main loop. Control will not return until the 
	// window is closed.
	glutMainLoop();

	return 0;
}

/**
* Acts as the display function for the window.
*/
static void RenderSceneCB() {
	// Clear the color and depth buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

	// Flush all drawing commands and swapbuffers
	glutSwapBuffers();

}

/**
Function: Displays OpengGL and GLSL version information.
*/
static void displayOpenGlInfo(void)
{
	// Display the company responsible for this GL implementation
	fprintf(stdout, "OpenGL INFO:\n\tOpenGL Implementor: %s\n",
		glGetString(GL_VENDOR));
	// Display the renderer/graphics card
	fprintf(stdout, "\tRenderer: %s\n", glGetString(GL_RENDERER));
	// Display the OpenGL version that is implemented
	fprintf(stdout, "\tOpenGL Version: %s\n", glGetString(GL_VERSION));
	// Display the GLSL version
	fprintf(stdout, "\tGLSL Version: %s\n\n",
		glGetString(GL_SHADING_LANGUAGE_VERSION));
}