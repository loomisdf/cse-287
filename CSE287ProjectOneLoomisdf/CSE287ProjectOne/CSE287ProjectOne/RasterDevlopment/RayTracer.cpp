#include "RayTracer.h"


RayTracer::RayTracer(ColorBuffer & cBuffer, color defaultColor )
	:colorBuffer(cBuffer), defaultColor(defaultColor)
{
	
}


RayTracer::~RayTracer(void)
{
}

void RayTracer::setCameraFrame(vec3 viewPosition, vec3 viewingDirection, vec3 up)
{
	// TODO
	this->eye = viewPosition;
	this->w = -viewingDirection / length(viewingDirection);
	this->u = cross(up, w) / length(cross(up, w));
	this->v = cross(w, u) / length(cross(w, u));

} // end setCameraFrame


void RayTracer::calculatePerspectiveViewingParameters(float verticalFieldOfViewDegrees)
{
	// TODO
	float alpha = radians(verticalFieldOfViewDegrees);

	this->nx = (float)colorBuffer.getWindowWidth();
	this->ny = (float)colorBuffer.getWindowHeight();

	this->distToPlane = 1 / (tan(alpha / 2));

	this->topLimit = 1;
	this->bottomLimit = -topLimit;

	this->rightLimit = (topLimit) * (nx / ny);
	this->leftLimit = -rightLimit;
	
} // end calculatePerspectiveViewingParameters


void RayTracer::calculateOrthographicViewingParameters(float viewPlaneHeight)
{
	topLimit = fabs(viewPlaneHeight) / 2.0f;

	rightLimit = topLimit * ((float)colorBuffer.getWindowWidth()/colorBuffer.getWindowHeight()); // Set r based on aspect ratio and height of plane

	// Make view plane symetrical about the viewing direction
	leftLimit = -rightLimit;
	bottomLimit = -topLimit;

	// Calculate the distance between pixels in the horizontal and vertical directions
	nx = (float)colorBuffer.getWindowWidth();
	ny = (float)colorBuffer.getWindowHeight();

	distToPlane = 0.0; // Rays start on the view plane
	
} // end calculateOrthographicViewingParameters


void RayTracer::raytraceScene(vector<Surface*> surfaces, vector<LightSource*> lights)
{
	this->surfacesInScene = surfaces;
	this->lightsInScene = lights;
	
	
	// Set all the pixels to the default color
	for (int x = 0; x < colorBuffer.getWindowWidth(); x++) {
		for (int y = 0; y < colorBuffer.getWindowHeight(); y++) {
			setPerspectiveRayOriginAndDirection(x, y);
			color pixelColor = traceIndividualRay(rayOrigin, rayDirection, 4);
			colorBuffer.setPixel(x, y, pixelColor);
		}
	}

	// TODO

} // end raytraceScene


color RayTracer::traceIndividualRay(const vec3 &e, const vec3 &d, int recursionLevel)
{
	// TODO
	HitRecord closestHit;
	bool first = true;
	closestHit.material = defaultColor;

	//find all the hits
	for (int s = 0; s < (int)surfacesInScene.size(); s++)
	{
		HitRecord hit = surfacesInScene[s]->findClosestIntersection(e, d);
		
		// If t <= FLT_MAX there is an intersection
		if (hit.t < FLT_MAX) {
			if (first) {
				closestHit = hit;
				first = false;
			}
			else if (hit.interceptPoint.z > closestHit.interceptPoint.z) {
				closestHit = hit;
			}
		}
	}

	color totalLight(0.0f);

	for (int l = 0; l < (int)lightsInScene.size(); l++) {
		totalLight += lightsInScene[l]->illuminate(-d, closestHit, surfacesInScene);
	}

	// reflection vector
	if (recursionLevel > 0) {
		vec3 r = glm::reflect(d, closestHit.surfaceNormal);
		totalLight += traceIndividualRay(closestHit.interceptPoint + EPSILON * closestHit.surfaceNormal, r, recursionLevel - 1) * 0.25;
	}
	return totalLight;

} // end traceRay


void RayTracer::setOrthoRayOriginAndDirection( int x, int y)
{
	vec2 uv = getProjectionPlaneCoordinates(x, y);

	// Page 75
	rayDirection = normalize(-w);
	rayOrigin = eye + uv.x * u + uv.y * v;

} // end setOrthoOriginAndDirection


void RayTracer::setPerspectiveRayOriginAndDirection(int x, int y)
{
	// TODO
	vec2 s = getProjectionPlaneCoordinates(x, y);
	rayDirection = (-distToPlane * w + s.x * u + s.y * v) / length(-distToPlane * w + s.x * u + s.y * v);
	rayOrigin = eye;

} // end setPerspectiveOriginAndDirection


vec2 RayTracer::getProjectionPlaneCoordinates(int x, int y)
{
	// Page 75
	vec2 s;

	// TODO
	s.x = leftLimit + (rightLimit - leftLimit) * ((x + 0.5) / (nx));
	s.y = bottomLimit + (topLimit - bottomLimit) * ((y + 0.5) / (ny));

	return s;
}