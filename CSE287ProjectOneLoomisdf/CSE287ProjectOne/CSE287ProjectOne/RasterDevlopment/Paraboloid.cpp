#include "Paraboloid.h"


Paraboloid::Paraboloid(const vec3 & position, float width, const color & mat)
	:QuadricSurface(position, mat), width(width)
{
	A = 0;
	B = 2;
	C = 1;
	D = 0;
	E = 0;
	F = 0;
	G = -1;
	H = 0;
	I = 0;
	J = 0;
	//center.x = -width;
}


HitRecord Paraboloid::findClosestIntersection(const vec3 &rayOrigin, const vec3 &rayDirection) {
	HitRecord hit = QuadricSurface::findClosestIntersection(rayOrigin, rayDirection);

	if (hit.interceptPoint.x > width) {
		hit.t = FLT_MAX;
	}
	return hit;
}

Paraboloid::~Paraboloid()
{
}
