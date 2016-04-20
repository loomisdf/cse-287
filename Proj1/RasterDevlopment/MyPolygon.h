#pragma once
#include "Plane.h"
class MyPolygon :
	public Plane
{
public:
	MyPolygon(const vector<vec3> &vertices, const vec3 &normal, const color &material);
	~MyPolygon();

	virtual HitRecord findClosestIntersection(const vec3 &rayOrigin, const vec3 &rayDirection);

	vector<vec3> vertices;
};