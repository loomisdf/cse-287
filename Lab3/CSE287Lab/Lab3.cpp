#include "Lab3.h"


/**
* LAB3 INSTRUCTIONS:
* Below are description of problems in vector arithmetic three dimensional
* geometry. Most require you to implement a struct that can be used to
* represent two or three dimensional curves or surfaces.
*
* Coding up these problems gives you a chance to verify you work is correct.
* Test by using values or quantities for which you know the answer.
*
* Please note that BasicIncludes includes overloaded functions called "print"
* for printing vec2, vec3, and vec4 objects to the console.
*
* Note the using statement for the std namespace has been commented out in 
* BasicIncludesAndDefines.h to avoid potential namespace conflicts. Thus,
* std types and names must not be preceded by std::
*
* Uncomment all function calls before turning in the lab.
* When you have completed all the problems, complete the following turning 
* instructions:
* 
*	1.	Copy the folder containing your solution to the desktop.
*	2.	Change the name of the folder to CSE287LabThree followed by your unique 
*		identifier. For instance “CSE287LabThreeBachmaer.”
*	3.	Open the solution. Make sure it still runs.
*	4.	Clean the solution by selecting Build->Clean Solution. (This will delete 
*		all the intermediate temporary files that are part of your project and 
*		reduce the size of your submission.)
*	5.	Zip up the solution folder using the standard windows compression tool. 
*		(No 7zips, rars, etc. Just zips.)
*	6.	Submit your zip archive of the solution through canvas.

*/

// Complete the constuctor and the checkPoint methods for the Circle struct. The
// Constructor should assign the input arguments to the data members. The 
// checkPoint method should return a negative value for points that are inside the
// circle, zero for points that are on the circle, and positive values for points
// that are outside the circle. Test the checkPoint function using vec2s that 
// satify all three cases. Display the results to the console.

struct Circle {

	vec2 center;
	float radius;

	Circle(float r = 1.0, vec2 ctr = vec2(0.0, 0.0))
	{
		center = ctr;
		radius = r;
	}

	int checkPoint(vec2 pt)
	{
		return pow(glm::length(pt - center), 2.0) - radius * radius;
	}

};


void problem1()
{
	std::cout << "Problem 1" << std::endl;
	Circle circle;
	vec2 a(0, 1);
	vec2 b(5, 5);
	vec2 c(0, 0);

	std::cout << "On the circle = " << circle.checkPoint(a) << std::endl;
	std::cout << "Outside the circle = " << circle.checkPoint(b) << std::endl;
	std::cout << "In the circle = " << circle.checkPoint(c) << std::endl;
	std::cout << std::endl;

} // end Problem1

// Create a Sphere struct that is similar to the Circle struct. Again, it should 
// have a constructor with default arguments and a checkPoint method that returns
// negative values, zero, and positive values in a manner that is similar to the
// Circle struct. Test with points that are inside, on, and outside a Sphere that
// is NOT centered on the origin. Display the results to the console.

struct Sphere {
	vec3 center;
	float radius;

	Sphere(float r = 1.0, vec3 ctr = vec3(0.0, 0.0, 0.0))
	{
		center = ctr;
		radius = r;
	}

	int checkPoint(vec3 pt)
	{
		return pow(glm::length(pt - center), 2.0) - radius * radius;
	}
};



void problem2()
{
	std::cout << "Problem 2" << std::endl;

	Sphere sphere;
	vec3 a(0, 1, 0);
	vec3 b(5, 5, 0);
	vec3 c(0, 0, 0);

	std::cout << "On the sphere = " << sphere.checkPoint(a) << std::endl;
	std::cout << "Outside the sphere = " << sphere.checkPoint(b) << std::endl;
	std::cout << "In the sphere = " << sphere.checkPoint(c) << std::endl;
	std::cout << std::endl;


} // end Problem2

// Write a struct for a Quadric surface of your choice. It should include a 
// checkPoint method as in the previous problems. Test the method in a similar 
// manner and display the results.

struct Ellipsoid {
	vec3 center;
	float a;
	float b;
	float c;

	Ellipsoid(float a = 1, float b = 1, float c = 2, vec3 ctr = vec3(0.0, 0.0, 0.0))
	{
		center = ctr;
		this->a = a;
		this->b = b;
		this->c = c;
	}

	int checkPoint(vec3 pt)
	{

		return (pow(pt.x - center.x, 2.0) / (a * a)) +
			(pow(pt.y - center.y, 2.0) / (b * b)) +
			(pow(pt.z - center.z, 2.0) / (c * c)) - 1;
	}
};


void problem3()
{
	std::cout << "Problem 3" << std::endl;

	Ellipsoid ellipsoid(10, 10, 10);
	vec3 a(1, 0, 0);
	vec3 b(10, 10, 0);
	vec3 c(0, 0, 0);

	std::cout << "On the ellipsoid = " << ellipsoid.checkPoint(a) << std::endl;
	std::cout << "Outside the ellipsoid = " << ellipsoid.checkPoint(b) << std::endl;
	std::cout << "In the ellipsoid = " << ellipsoid.checkPoint(c) << std::endl;
	std::cout << std::endl;


} // end Problem3

// Write a Plane struct. The constructor should have three vec3s as parameters
// that are assumed to be in counter=clockwise order. The data members of the 
// struct should include a normal vector and a point on the Plane. The normal
// vector should point out of the side of the Plane on which the vertices are
// in counter-clockwise order It be should unit length. 
//
// As long as the normal vector is a unit vector, the signed distance of a 
// point from a plane is given by the equation on page 60 of the notes. Write
// a singedDistance function that has a vec3 as an argument. Test it for 
// points behind, on, and infront of a Plane. Display the results on the 
// console.
//
// Can your checkPoint methods in the previous questions be modified to 
// return a signed distance? If you believe the answer is "yes," go ahead
// and modify the functions accordingly in each of the previous questions.

struct Plane {
	vec3 normal;
	vec3 pt;
	Plane(const vec3& a, const vec3& b, const vec3& c) {
		this->normal = normalize(cross(c - b, a - b));
		this->pt = a;
	}

	int signedDistance(const vec3& p) {
		return dot((p - pt), normal);
	}
};


void problem4()
{
	std::cout << "Problem 4" << std::endl;
	vec3 a(1, 0, 0);
	vec3 b(0, 1, 0);
	vec3 c(0, 0, 1);
	Plane plane(a, b, c);

	vec3 d(1, 0, 0);
	vec3 e(2, 3, 0);
	vec3 f(-1, 0, 0);

	std::cout << "On the plane = " << plane.signedDistance(d) << std::endl;
	std::cout << "In front of the plane = " << plane.signedDistance(e) << std::endl;
	std::cout << "Behind the plane = " << plane.signedDistance(f) << std::endl;

	std::cout << std::endl;

} // end Problem4

// Write a struct that supports a parametric representation of a line in
// in three dimensional space. The constructor should take two points on
// the line as parameters. 
//
// It should have a method called checkPoint that
// returns true if the input argument is on the line and false otherwise.
// If the point is on the line it should return the parameter of the 
// point "by reference." Test this method for points both on and off the
// line. Verify that the returned parameter is correct for points on the
// line. Display the results. 
//
// Write a method called getPoint. Given a value for the parameter, it
// should return a vec3 that contains the location that corresponds to the
// supplied parameter. Test this with points that on both sides of the pairs 
// used to specify the line as well as a point inbetween the two points.
// Display the results.
struct ParametricLine {
	vec3 pt1;
	vec3 pt2;

	ParametricLine(const vec3& a, const vec3& b) {
		this->pt1 = a;
		this->pt2 = b;
	}

	bool checkPoint(vec3 p, double & t)
	{
		t = 0.0;
		if (dot(p - pt1, pt2 - pt1) < (length(p - pt1) * length(pt2 - pt1))) {
			return false;
		}
		else {
			double sign;
			if (length(p - pt1) > length(p - pt2)) {
				sign = 1;
			}
			else {
				sign = -1;
			}
			t = length(p - pt1) / length(pt2 - pt1) * sign;
			return true;
		}
	}

	vec3 getPoint(double t) {
		return pt1 + ((float)t * (pt2 - pt1));
	}
};

void problem5()
{
	std::cout << "Problem 5" << std::endl;
	vec3 v(6, 0, 0);
	vec3 w(0, 0, 0);
	double t1;
	double t2;
	ParametricLine line(v, w);

	vec3 on(1, 0, 0);
	vec3 off(2, 2, 2);
	bool pointOn = (line.checkPoint(on, t1));
	bool pointOff = line.checkPoint(off, t2);
	std::cout << "Point on the line = " << pointOn << std::endl;
	std::cout << "Point off the line = " << pointOff << std::endl;
	std::cout << "t1 = " << t1 << std::endl;
	std::cout << "t2 = " << t2 << std::endl;

	vec3 inBetween = line.getPoint(0.5);
	vec3 past = line.getPoint(5);
	vec3 before = line.getPoint(-2);

	std::cout << "Point between = " << "(" << inBetween.x << "," << inBetween.y << "," << inBetween.z << ")" << std::endl;
	std::cout << "Point past = " << "(" << past.x << "," << past.y << "," << past.z << ")" << std::endl;
	std::cout << "Point before = " << "(" << before.x << "," << before.y << "," << before.z << ")" << std::endl;

	std::cout << std::endl;

} // end Problem5

// Write a function that supports linear interpolation between
// two scalar (doubles) values. It should take two doubles as 
// arguments. These represent the initial and ending values. It
// should also take a value for the interpolation parameter as 
// an argument. If the parameter is zero or negative, the function
// should return the initial value. If the parameter is one or
// greater, the function should return the final value. Otherwise,
// is should return an interpolated value bewteeen the begining 
// and ending values. Use the function to interpolate between 5 and 15.
// Test it with parameter values of -1, 0, 0.6, 1, and 20. Display
// the results to the console.
double interpolate(double a, double b, double t) {
	if (t <= 0.0) {
		return a;
	}
	else if (t >= 1.0) {
		return b;
	}
	return a + (b - a) * t;
}

void problem6()
{
	std::cout << "Problem 6" << std::endl;
	double a = 5.0;
	double b = 15.0;
	std::cout << "parameter is -1  = " << interpolate(a, b, -1.0) << std::endl;
	std::cout << "parameter is 0   = " << interpolate(a, b, 0.0) << std::endl;
	std::cout << "parameter is 0.6 = " << interpolate(a, b, 0.6) << std::endl;
	std::cout << "parameter is 1   = " << interpolate(a, b, 1.0) << std::endl;
	std::cout << "parameter is 20  = " << interpolate(a, b, 20.0) << std::endl;

	std::cout << std::endl;

} // end Problem6

// Write a function that linearly interpolates between two three
// dimension vector values. Functionality should be similar to 
// the previous question. Test it with points at (0,0,0) and (4, 4, 0).
// Use the same parameter values as the previous question. Display the 
// results.

vec3 interpolate(const vec3& a, const vec3& b, double t) {
	if (t <= 0.0) {
		return a;
	}
	else if (t >= 1.0) {
		return b;
	}
	return vec3(b.x * (1 - t), b.y * (1 - t), b.z * (1 - t)) + vec3(a.x * (t - 1), a.y * (t - 1), a.z * (t - 1));
}
void problem7()
{
	std::cout << "Problem 7" << std::endl;
	vec3 a(0, 0, 0);
	vec3 b(4, 4, 0);
	std::cout << "parameter is -1  = " << "(" << interpolate(a, b, -1.0).x << "," << interpolate(a, b, -1.0).y << "," << interpolate(a, b, -1.0).z << ")" << std::endl;
	std::cout << "parameter is 0  = " << "(" << interpolate(a, b, 0.0).x << "," << interpolate(a, b, 0.0).y << "," << interpolate(a, b, 0.0).z << ")" << std::endl;
	std::cout << "parameter is 0.6  = " << "(" << interpolate(a, b, 0.6).x << "," << interpolate(a, b, 0.6).y << "," << interpolate(a, b, 0.6).z << ")" << std::endl;
	std::cout << "parameter is 1  = " << "(" << interpolate(a, b, 1.0).x << "," << interpolate(a, b, 1.0).y << "," << interpolate(a, b, 1.0).z << ")" << std::endl;
	std::cout << "parameter is 20  = " << "(" << interpolate(a, b, 20).x << "," << interpolate(a, b, 20).y << "," << interpolate(a, b, 20).z << ")" << std::endl;

	std::cout << std::endl;

} // end Problem7

// Refer to the updated version of slide 40 in the chapter two notes
// for this problem. (Handed out in class this Wednesday and available
// in canvas).
//
// Suppose the vector v = [ 2 -6 3 ]and the vector w = [-4 3 10 ].
// Find the vector that represents the projection of v onto w. Find the the
// vector that represents the part of v that is perpendicular to w. Print
// out each of these vectors. Verify correctness by adding together the
// two calculated vectors and checking for equality with v. Display the results.
void problem8()
{
	vec3 v(2, -6, 3);
	vec3 w(-4, 3, 10);

	vec3 proj = (dot(v, w) / pow(length(w), 2)) * w;
	vec3 perp = v - proj;

	std::cout << "Projection of v onto w  = " << "(" << proj.x << "," << proj.y << "," << proj.z << ")" << std::endl;
	std::cout << "Perpendicular component  = " << "(" << perp.x << "," << perp.y << "," << perp.z << ")" << std::endl;

	std::cout << "Correctness = " << (proj + perp == v) << std::endl;

	std::cout << std::endl;

} // end Problem8




int main(int argc, char** argv)
{
	// To keep the console open on shutdown, start the project with Ctrl+F5 instead of just F5.

	problem1();
	problem2();
	problem3();	
	problem4();	
	problem5();
	problem6();
	problem7();
	problem8();

	return 0;

} // end main