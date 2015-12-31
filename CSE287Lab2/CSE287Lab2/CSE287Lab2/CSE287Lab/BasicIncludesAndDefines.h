/**
* Eric Bachmann
* Instructor: Eric Bachmann
* 
* Standard includes for CSE287. Expect to have a #include for this file
* in every header (.h) file that is created through out the semester.
*/

/** 
* Preprocessor "include guard" against cicular includes and redefinitions.
* Equivalent to serious of #ifndef #define #endif statements.
*/
#pragma once 

#include <iostream> // Access to I/O functionality
#include <vector> // Collection class for storing object

// Give access to members of the std namespace without qualification.
using namespace std; 

#include <GL/freeglut.h> // Provides rendering window and event mechanism

// GLM includes (See http://glm.g-truc.net/0.9.7/glm-0.9.7.pdf)

#define GLM_SWIZZLE  // Enable "swizzle" operators

#define GLM_FORCE_RADIANS // Force all GLM functions to adopt radians.

#include <glm/glm.hpp> // Basic glm functionality

// Stable glm extensions
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/swizzle.hpp>
#include <glm/gtc/constants.hpp>

// Experimental glm extensions.
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtx/euler_angles.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtx/constants.hpp>

// Give access to members of the glm namespace without qualification.
using namespace glm; 

/*
* Preprocessor statement for text substitution. Prior to compilation, every 
* instance of "color" will be replaces by "vec4"
*/
#define color vec4

// Class that controls memory through individual pixels colors can be set.
#include "ColorBuffer.h" 


inline void print(const vec2 & v0)
{
	cout << "[ " << v0.x << " " << v0.y << " ]" << endl;
}

inline void print(const vec3 & v0)
{
	cout << "[ " << v0.x << " " << v0.y << " " << v0.z << " " << " ]" << endl;
}

inline void print(const vec4 & v0)
{
	cout << "[ " << v0.x << " " << v0.y << " " << v0.z << " " << v0.w << " ]" << endl;
}
