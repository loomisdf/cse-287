#pragma once

#include "BasicIncludesAndDefines.h"

#include "Surface.h"
#include "Sphere.h"
#include "Plane.h"

#include "Lights.h"

class RayTracer
{
public:

	RayTracer(ColorBuffer & cBuffer, color defaultColor = color(0.0, 0.0, 0.0, 1.0));

	~RayTracer(void);

	void raytraceScene(vector<Surface*> surfaces, vector<LightSource*> lights);

	void setCameraFrame(vec3 viewPosition, vec3 viewingDirection, vec3 up);

	void calculateOrthographicViewingParameters(float viewPlaneHeight = 10.0f);

	void calculatePerspectiveViewingParameters(float verticalFieldOfViewDegrees = 45.0f);

protected:

	color traceIndividualRay(const vec3 &e, const vec3 &d, int recursionLevel);
	void setOrthoRayOriginAndDirection( int x, int y);
	void setPerspectiveRayOriginAndDirection( int x, int y);
	vec2 getProjectionPlaneCoordinates(int x, int y);

	ColorBuffer & colorBuffer;

	// Color to which a pixel is set if there is no intersection
	// for the traced pixel ray.
	color defaultColor;

	// View frame parameters
	vec3 eye; // position of the viewpoint
	vec3 u; // "right" relative to the viewing direction
	vec3 v; // perpendicular up vector
	vec3 w; // camera looks in the negative w direction

	// Projection plane parameters
	// Measured relative to u (right)
	float rightLimit;
	float leftLimit;
	// Measured reltive to v (up)
	float topLimit;
	float bottomLimit;

	// Rendering window parameters
	float nx; // Width in pixels
	float ny; // Height in pixel

	// Distance from the viewpoint to the projection plane
	float distToPlane;

	// Parametric ray being traced for a pixel
	vec3 rayDirection; // Direction of the ray
	vec3 rayOrigin; // Origin of the ray

	// List of the surfaces in the scene that is being ray traced
	vector<Surface*> surfacesInScene;

	// List of the light sources in the scene that is being ray traced
	vector<LightSource*> lightsInScene;

};

