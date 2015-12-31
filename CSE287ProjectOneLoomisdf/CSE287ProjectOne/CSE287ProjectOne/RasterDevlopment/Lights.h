#pragma once

#include "BasicIncludesAndDefines.h"

#define EPSILON 1.0E-4f

/**
* Base struct for all types of lights. Supports only specification of the 
* color and intensity of light sources. Parent of sub-structs that simulate
* positional, directional, and spot lights.
*
* Instances of this struct an be used to simulate only ambient light. Ambient
* light is described as bounced light that has been scattered so much that it
* is impossible to tell the direction to its source. If using a LightSource 
* instantiation to simulate ambient light, the overall intensity of the light
* should be low in order to avoid washing out shadows as well as diffuse and 
* specular effects that can be achieved when using children of this struct.
*/
struct LightSource
{
	LightSource(const color & color) 
		: lightColor(color) 
	{}

	virtual color illuminate(const vec3 & eyeVector, HitRecord & closestHit, vector<Surface*> surfaces)
	{
		//return lightColor * closestHit;
		return lightColor * closestHit.material;
	}

	/*
	* Using the half vector:
		a is the surface normal
		b is the half vector
	
	* Using the Reflection vector:
		a if the reflection vector
		b is the view vector
	*/
	virtual color specularLight(const vec3& a, const vec3 &b, float shininess) {
		return pow(max(0.0f, dot(a, b)), shininess) * vec4(1, 1, 1, 1.0) * lightColor;
	}

	virtual float clearShadowVec(const vec3 & e, const vec3 & d, vector<Surface*> surfaces) {
		HitRecord closestHit;
		closestHit.t = FLT_MAX;

		for (int s = 0; s < (int)surfaces.size(); s++) {

			HitRecord hitRec = surfaces[s]->findClosestIntersection(e, d);

			if (hitRec.t < closestHit.t) {

				closestHit = hitRec;
			}

		}

		return closestHit.t;
	}

	/* 
	* Color and intensity of the light.
	*/
	color lightColor; 
};

/**
* Struct for simulating light sources that have an explicit position and 
* shine equally in all directions. Instantiations of the struct will have
* a position property and a color and intensity of the light given off
* by the light.
*/
struct PositionalLight : public LightSource
{
	PositionalLight(vec3 position, const color & color)
		: LightSource(color), position(position)
	{}

	virtual color illuminate(const vec3 & eyeVector, HitRecord & closestHit, vector<Surface*> surfaces)
	{
		// Diffuse reflection
		vec3 lightVector = (position - closestHit.interceptPoint) / length(position - closestHit.interceptPoint);
		color diffuse = max(0.0f, dot(closestHit.surfaceNormal, lightVector)) * lightColor * closestHit.material;

		//Specular Reflection
		vec3 halfVector = (eyeVector + lightVector) / length(eyeVector + lightVector);
		vec3 reflectVector = normalize(-lightVector - 2.0f * (dot(lightVector, closestHit.surfaceNormal) * closestHit.surfaceNormal));
		float shininess = 200;
		//color specular = specularLight(closestHit.surfaceNormal, halfVector, shininess);
		color specular = specularLight(reflectVector, eyeVector, shininess);

		//Test for shadow
		vec3 offset = closestHit.interceptPoint + (EPSILON * normalize(closestHit.surfaceNormal));
		vec3 feeler = glm::normalize(position - offset);

		float t = LightSource::clearShadowVec(offset, feeler, surfaces);

		if (t > EPSILON && t < glm::distance(position, closestHit.interceptPoint)) {
			return color(0.0f, 0.0f, 0.0f, 1.0f);
		}

		return diffuse + specular;
	}

	/**
	* x, y, z position of the light source. 
	*/
	vec3 position; 
};

/**
* Struct for simulating light sources that do not have an explicit position.
* Such light sources have only a direction against which they are shinning.
* Instantiations of the struct will have this direction properties along with
* a color and intensity of the light given off by the light source.
*/
struct DirectionalLight : public LightSource
{
	DirectionalLight(vec3 direction, const color & color)
		: LightSource(color), direction(normalize(direction))
	{}

	virtual color illuminate(const vec3 & eyeVector, HitRecord & closestHit, vector<Surface*> surfaces)
	{
		// Diffuse reflection
		color diffuse = max(0.0f, dot(closestHit.surfaceNormal, direction)) * lightColor * closestHit.material;

		//Specular Reflection
		vec3 halfVector = (eyeVector + direction) / length(eyeVector + direction);
		float shininess = 225;
		vec3 reflectVector = normalize(-direction - 2.0f * (dot(direction, closestHit.surfaceNormal) * closestHit.surfaceNormal));
		color specular = specularLight(reflectVector, eyeVector, shininess);
		//color specular = pow(max(0.0f, dot(closestHit.surfaceNormal, halfVector)), shininess) * vec4(1, 1, 1, 1.0) * lightColor;

		//Test for shadow
		vec3 offset = closestHit.interceptPoint + (EPSILON * normalize(closestHit.surfaceNormal));
		vec3 feeler = direction;
		float t = LightSource::clearShadowVec(offset, feeler, surfaces);

		if (t > EPSILON && t < FLT_MAX) {
			return color(0.0f, 0.0f, 0.0f, 1.0f);
		}

		return diffuse + specular;
	}

	/**
	* Unit vector that points in the direction that is opposite 
	* the direction in which the light is shining.
	*/
	vec3 direction; 
};

