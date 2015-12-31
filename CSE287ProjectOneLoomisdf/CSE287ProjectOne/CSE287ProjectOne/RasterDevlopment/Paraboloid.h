#pragma once
#include "QuadricSurface.h"

class Paraboloid :
	public QuadricSurface
{
public:
	Paraboloid(const vec3 & position, float width, const color & mat);
	~Paraboloid();

	HitRecord findClosestIntersection(const vec3 &rayOrigin, const vec3 &rayDirection);

	float width;
};

