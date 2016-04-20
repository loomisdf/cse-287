#include "MyPolygon.h"

MyPolygon::MyPolygon(const vector<vec3> &vertices, const vec3 &normal, const color &material)
	:Plane(vertices.front(), normal, material), vertices(vertices)
{
}

HitRecord MyPolygon::findClosestIntersection(const vec3 &rayOrigin, const vec3 &rayDirection) {
	HitRecord hit = Plane::findClosestIntersection(rayOrigin, rayDirection);
	
	// If there is an intersection with the plane
	if (hit.t < FLT_MAX) {
		// Check the last side of the polygon first
		if (dot(cross(vertices[0] - vertices[vertices.size() - 1], hit.interceptPoint - vertices[vertices.size() - 1]), Plane::n) <= 0) {
			hit.t = FLT_MAX;
			return hit;
		}
		for (int v = 0; v < vertices.size() - 1; v++) {
			// If it is not left
			if (dot(cross(vertices[v + 1] - vertices[v], hit.interceptPoint - vertices[v]), Plane::n) <= 0) {
				hit.t = FLT_MAX;
				return hit;
			}
		}
	}
	// There is no intersection with the plane
	else {
		return hit;
	}

	// The point is both in the plane and within the polygon
	return hit;
}

MyPolygon::~MyPolygon()
{
}
