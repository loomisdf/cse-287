#include "Lab2.h"

/**
* LAB2 INSTRUCTIONS:
* Below are description of problems in vector arithmetic. Each problem has
* at least one or two functions associated with it (functions - not methods. 
* there is not class). There is a function call in the main for each one 
* of the problems. For each problem write the necessary code to solve it.
* All console output should be labeled. Do NOT simply print a number. Make
* sure there is text that indicates what the number is and possibly its
* significance.
*
* You may find it helpful to have the chapter 2 lecture notes handy as you 
* work through the problems. As you are moving from problem to problem, you
* may want to comment out some of the function calls in the main so that you 
* easily see the output for the current problem. Uncomment all function calls
* before turning in the lab. BasicIncludesAndDefines includes definitions of 
* simple functions for printing vec2, vec3, and vec4 objects to the console.
*
* When you have completed all the problems, complete the following turning 
* instructions:
* 
*	1.	Copy the folder containing your solution to the desktop.
*	2.	Change the name of the folder to CSE287LabOne followed by your unique 
*		identifier. For instance “CSE287LabOneBachmaer.”
*	3.	Open the solution. Make sure it still runs.
*	4.	Clean the solution by selecting Build->Clean Solution. (The will delete 
*		all the intermediate temporary files that are part of your project and 
*		reduce the size of your submission.)
*	5.	Zip up the solution folder using the standard windows compression tool. 
*		(No 7zips, rars, etc.)
*	6.	Submit your zip archive of the solution through canvas.

*/

#define PI 3.14159

// Suppose x equals 45 degrees write a statement that does the necessary 
// calculation to convert this value to radians. Print out the resulting 
// value. Write another statement that uses the correct glm function
// to convert x to radians. Print out the resulting value.
void problem1()
{
	double x = 45;

	cout << "Problem 1" << endl;
	cout << "45 degrees is "<< (PI / 180) * x << " in radians" << endl << endl;
} // end Problem1

// Suppose x equals 2.0943951 radians write a statement that does the 
// necessary calculation to convert this value to degrees. Print out the
// resulting value. Write another statement that uses the correct glm 
// function to convert x to degrees. Print out the resulting value.
void problem2()
{
	double x = 2.0943951;

	cout << "Problem 2" << endl;
	cout << "2.0943951 radians is " << (180 / PI) * x << " degrees" << endl << endl;


} // end Problem2

// Suppose the cosine of an angle theta is  0.34202014332566873304409961468226.
// Use a trigometric function to determine angle. Print out the angle in 
// both degrees and radians.
void problem3()
{
	double x = 0.34202014332566873304409961468226;
	double angle = acos(x);
	double degrees = (180 / PI) * angle;
	cout << "Problem 3" << endl;
	cout << "Degrees=" << degrees << " Radians=" << angle <<  endl << endl;
} // end Problem3

// Suppose the vector v = [ 4 3 ]. Use the atan2 funtion
// to determine the angle that this vector makes with the x axis. Print 
// out the angle in degrees. Use the single argument atan function to 
// perform the same calculation. Print out this result as well.
void problem4()
{
	

	vec2 v(4, 3);
	double angle1 = atan2(v.y, v.x);
	double angle1Degrees = (180 / PI) * angle1;

	double angle2 = atan(v.y / v.x);
	double angle2Degrees = (180 / PI) * angle2;

	cout << "Problem 4" << endl;
	cout << "atan2: " << "degrees= " << angle1Degrees << endl;
	cout << "atan: " << " degrees=" << angle2Degrees << endl << endl;

} // end Problem4

// Suppose the vector v = [ -4 -3 ]. Use the atan2 funtion
// to determine the angle that this vector makes with the x axis. Print 
// out the angle in degrees. Use the single argument atan function to 
// perform the same calculation. Print out this result as well. Is the
// result given by the single argument atan correct? Include a print
// statement stating either "correct" or "not correct."
void problem5()
{

	vec2 v(-4, -3);
	double angle1 = atan2(v.y, v.x);
	double angle1Degrees = (180 / PI) * angle1;

	double angle2 = atan(v.y / v.x);
	double angle2Degrees = (180 / PI) * angle2;

	cout << "Problem 5" << endl;

	cout << "atan2: " << "degrees= " << angle1Degrees << endl;
	cout << "atan: " << " degrees=" << angle2Degrees << endl;
	cout << "not correct" << endl << endl;

} // end Problem5

// Write a function that will calculate and return the area of a triangle
// when passed the lengths of the three sides. Call the function and print
// out the area for a triangle with side lengths of 7, 10, and 5.

double triangleArea1(double a, double b, double c)
{
	double area = (0.5) * sqrt((a + b + c)*(-a + b + c)*(a - b + c)*(a + b - c));

	return area;

} // end triangleArea1

void problem6()
{
	double area = triangleArea1(7, 10, 5);
	cout << "Problem 6" << endl;
	cout << "Area=" << area << endl << endl;


} // end Problem6

// Find the polar coordinates for the point (-4, 3) and print them out. (Hint: Calculate the
// length of the vector and use the atan2 function.)
void problem7()
{
	vec2 v(-4, 3);
	double angle = atan2(v.y, v.x);
	double r = sqrt((v.x*v.x) + (v.y*v.y));

	cout << "Problem 7" << endl;
	cout << "poloar coords=(" << r << "," << angle << ")" << endl << endl;


} // end Problem7

// Suppose the vector v = [4 -6 7 ]. Create a vector 
// that is twice as long as v and points in the same direction as v. Print 
// out the result. Create a vector that has the same length as v and points 
// in the opposite direction of v. Print out the result. Create a vector 
// that is three quarter the length of v and points in the same direction 
// as v. Print out the result. 
void problem8()
{
	cout << "Problem 8" << endl;
	vec3 v(4, -6, 7);
	vec3 v2(v.x * 2, v.y * 2, v.z * 2);
	vec3 v3(v.x * -1, v.y * -1, v.z * -1);
	vec3 v4(v.x * 0.75, v.y * 0.75, v.z * 0.75);
	

	cout << "v2(" << v2.x << ", " << v2.y << ", " << v2.z << ")" << endl;
	cout << "v3(" << v3.x << ", " << v3.y << ", " << v3.z << ")" << endl;
	cout << "v4(" << v4.x << ", " << v4.y << ", " << v4.z << ")" << endl << endl;


} // end Problem8

// Write a function that compares two vec3s for equality by comparing 
// individual components. It should return true if the vectors are equal 
// and false otherwise. Check for correctness by using equal and unequal
// vec3s. Print out the results. Vertify that the same results are obtained
// when using the overloaded '==' operator. Print out the results.

bool vectorEquality(const vec3 & v, const vec3 & w)
{
	if (v.x == w.x &&
		v.y == w.y &&
		v.z == w.z) {
		return true;
	}
	else {
		return false;
	}

} // end vectorEquality

void problem9()
{
	vec3 v(1, 2, 3);
	vec3 w(1, 2, 3);

	vec3 w2(3, 2, 1);

	bool glmEqual = v == w;
	bool glmNotEqual = v == w2;

	cout << "Problem 9" << endl;

	cout << "Equal vectors=" << vectorEquality(v, w) << endl;
	cout << "Unequal vectors=" << vectorEquality(v, w2) << endl << endl;
	cout << "GLM Equal vectors=" << glmEqual << endl;
	cout << "GLM Unequal vectors=" << glmNotEqual << endl << endl;


} // end Problem9

// Write a function that calculates and returns the length of a vector. 
// Compare this to the result returned by the glm length function. Print 
// out the results.

double myLength(const vec3 & v)
{
	return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);

} // end myLength

void problem10()
{
	vec3 v(1, 2, 3);
	double length = myLength(v);
	double glmLength = v.length();

	cout << "Problem 10" << endl;
	cout << "My length=" << length << endl;
	cout << "GLM length=" << glmLength << endl << endl;


} // end Problem10

// Write a function caculates and returns the unit length version of a vec3
// that is received as an argument. Compare the returned result to that
// which is returned by the glm normalize function. Print out the results.
vec3 myUnitVector(const vec3 & v)
{
	double length = myLength(v);

	return vec3(v.x / length, v.y / length, v.z / length);

} // end myUnitVector

void problem11()
{
	vec3 v(1, 2, 3);
	vec3 unit = myUnitVector(v);
	vec3 unit2 = normalize(v);

	cout << "Problem 11" << endl;
	cout << "vector(1, 2, 3)" << endl;
	cout << "myUnitVector=" << "(" << unit.x << ", " << unit.y << ", " << unit.z << ")" << endl;
	cout << "glmUnitVector=" << "(" << unit2.x << ", " << unit2.y << ", " << unit2.z << ")" << endl << endl;


} // end Problem8

// Suppose the vector v = [ -4 2 -3 ]. Create a vector
// that points in the same direction, but has a length of one. Print out the
// result. Create a vector that points in the same direction, but has a 
// length of three. Print out the result. Create a vector that points in 
// the opposite direction and has a length of five. Print out the result.
// (Feel free to use the glm normalize function for this problem.)
void problem12()
{
	vec3 v(-4, 2, -3);
	vec3 unit = normalize(v);
	vec3 length3(unit.x * 3, unit.y * 3, unit.z * 3);
	vec3 length5(unit.x * -5, unit.y * -5, unit.z * -5);

	cout << "Problem 12" << endl;
	cout << "Vector with length 1=" << "(" << unit.x << ", " << unit.y << ", " << unit.z << ")" << endl;
	cout << "Vector with length 3=" << "(" << length3.x << ", " << length3.y << ", " << length3.z << ")" << endl;
	cout << "Vector with length 5 in opposite direction=" << "(" << length5.x << ", " << length5.y << ", " << length5.z << ")" << endl << endl;


} // end Problem12

// Suppose the vector v = [ 2 -6 3 ]and the vector w = [-4 3 10 ]
// Add the two vectors together using the overloaded glm addtion operator. 
// Print the resulting sum.
void problem13()
{
	vec3 v(2, -6, 3);
	vec3 v2(-4, 3, 10);
	vec3 v3 = v + v2;

	cout << "Problem 13" << endl;
	cout << "(2, -6, 3) + (-4, 3, 10) = " << "(" << v3.x << ", " << v3.y << ", " << v3.z << ")" << endl << endl;


} // end Problem13

// Suppose someone walks three miles north and then seven miles west. 
// Assume they started at position 0,0. Asssume the X axis points north.
// Use vector arithmetic to determine the coordinates of their finishing 
// point. Print the result. Also print a result that shows that is does 
// not matter whether they walk north or west first. 
void problem14()
{
	vec2 start(0, 0);
	
	vec2 v(3, 7);
	vec2 v3 = v + start;
	vec2 v4 = start + v;

	cout << "Problem 14" << endl;
	cout << "Resulting coordinates= " << "(" << v3.x << ", " << v3.y << ")" << endl;
	cout << "starting north first" << "(" << v4.x << ", " << v4.y << ")" << endl << endl;


} // end Problem14

// Suppose the person in the previous quesion starts at 3,4. What would
// their finishing point be? Print the result.
void problem15()
{
	vec2 start(3, 4);
	vec2 v(3, 7);
	vec2 v3 = v + start;

	cout << "Problem 15" << endl;
	cout << "Resulting coordinates= " << "(" << v3.x << ", " << v3.y << ")" << endl << endl;


} // end Problem15

// Use two vectors to show that vector subtraction is not communitive.
// Print the vectors and the values that indicate the fact.
void problem16()
{
	vec2 v(1, 2);
	vec2 v2(3, 4);

	vec2 sub1 = v - v2;
	vec2 sub2 = v2 - v;
	cout << "Problem 16" << endl;
	cout << "(1, 2) - (3, 4) = " << "(" << sub1.x << ", " << sub1.y << ")" << endl;
	cout << "(3, 4) - (1, 2) = " << "(" << sub2.x << ", " << sub2.y << ")" << endl << endl;


} // end Problem16

// Write a funtion that calculates the dot product of two vec3s and returns
// this scalar value as a double. Use the vectors v = [ 2 6 3 ] and w = [-4 3 10] 
// to show that your function produces the sam value as the glm dot function.
// Print the results.
double myDot(const vec3 a, const vec3 b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z;

} // end myDot

void problem17()
{
	vec3 a(2, 6, 3);
	vec3 b(-4, 3, 10);
	double dot1 = myDot(a, b);
	double dot2 = dot(a, b);

	cout << "Problem 17" << endl;
	cout << "My Dot=" << dot1 << endl;
	cout << "GLM Dot=" << dot2 << endl << endl;


} // end Problem17

// Use the dot product to find the cosines of the angles that the vector 
// v = [ -2 1 3 ] makes with each of the following vectors. Print out the
// values. 
//   v = [2 6 3] 
//   w = [-4 3 10]
//   q = [ 3 0 0 ]
void problem18()
{
	vec3 a(-2, 1, 3);

	vec3 v(2, 6, 3);
	vec3 w(-4, 3, 10);
	vec3 q(3, 0, 0);
	double r1 = dot(a, v) / (myLength(a) * myLength(v));
	double r2 = dot(a, w) / (myLength(a) * myLength(w));
	double r3 = dot(a, q) / (myLength(a) * myLength(q));

	cout << "Problem 18" << endl;
	cout << "Cosine of v=" << r1 << endl;
	cout << "Cosine of w=" << r2 << endl;
	cout << "Cosine of q=" << r3 << endl;


} // end Problem18

// Write a function that compares two vec3s. If they are within 90 degrees of
// each other, it should return an integer value of 1. If they are prependicular
// the function should return 0. If the vectors are more than 90 degrees apart, 
// the function should return -1. Do not use any trigometric functions.
int vectorCompare( vec3  a,  vec3  b)
{
	if (dot(a, b) == 0) {
		return 0;
	}
	else if (dot(a, b) > 0) {
		return 1;
	}
	else if (dot(a, b) < 0) {
		return -1;
	}

	return 0;
}
void problem19()
{
	vec3 a(2, 0, 0);
	vec3 b(0, 2, 0);
	vec3 c(2, 4, 0);
	vec3 d(-2, -4, 0);

	cout << "Problem 19" << endl;
	cout << "(2, 0, 0) dot (0, 2, 0)=" << vectorCompare(a, b) << endl;
	cout << "(2, 0, 0) dot (2, 4, 0)=" << vectorCompare(a, c) << endl;
	cout << "(2, 0, 0) dot (-2, -4, 0)=" << vectorCompare(a, d) << endl << endl;


} // end Problem19

// Write a function that finds the projection of one vector onto another and 
// returns it as a double. Use it to find the projection of   v = [ 2 6 3 ] on to 
// w = [-4 3 10]. Print the result.
double project(vec3 from, vec3 onto)
{
	return dot(from, onto) / myLength(onto);
}
void problem20()
{
	vec3 v(2, 6, 3);
	vec3 w(-4, 3, 10);

	cout << "Problem 20" << endl;
	cout << "(2, 6, 3) projected onto (-4, 3, 10) = " << project(v, w) << endl << endl;


} // end Problem20

// Take the cross product of the vectors v = [ 2 6 3 ] and w = [-4 3 10]. use the glm cross
// product function. Print the result. Use the dot product to verify the the resulting
// product is perpendicular to each of the multiplicands. Print the result.
void problem21()
{
	vec3 v(2, 6, 3);
	vec3 w(-4, 3, 10);

	vec3 r = cross(v, w);

	cout << "Problem 21" << endl;
	cout << "v cross w = " << "(" << r.x << ", " << r.y << ", " << r.z << ")" << endl;
	cout << "result dot w = " << dot(r, w) << endl;
	cout << "result dot v = " << dot(r, v) << endl << endl;


} // end Problem21

// Calculate the cross product v x w and then w x v. Use the vectors v = [ 2 6 3 ] 
// and w = [-4 3 10].Print each of the products.  Verify that cross product is not
// commutitative by checking for equality or by adding the two products together 
// and checking the sum. Print the result.
void problem22()
{
	vec3 v(2, 6, 3);
	vec3 w(-4, 3, 10);

	vec3 r1 = cross(v, w);
	vec3 r2 = cross(w, v);

	cout << "Problem 22" << endl;
	cout << "v cross w = " << "(" << r1.x << ", " << r1.y << ", " << r1.z << ")" << endl;
	cout << "w cross v = " << "(" << r2.x << ", " << r2.y << ", " << r2.z << ")" << endl;
	cout << "equal? = " << (bool) (r1 == r2) << endl << endl;


} // end Problem22

// Write a function that has three vec3 parameters. The parameters should give 
// three corners of a parallelogram in counter-clockwise order. In the function
// use the cross product to calculate the area of the parallelogram. Test the
// function with the following vertices [ 0 2 0 ], [ 0 0 0 ] [4 0 0]. Print the 
// result. Then test the function with another three vertices of you choosing
// Print out this area as well. The returned areas should be positive for 
// vertices in counter clockwise order.

double areaOfParallelogram(vec3 a, vec3 b, vec3 c)
{
	vec3 u = a - b;
	vec3 v = c - b;

	return myLength(cross(u, v));
}

void problem23()
{
	vec3 v(0, 2, 0);
	vec3 w(0, 0, 0);
	vec3 q(4, 0, 0);

	cout << "Problem 23" << endl;
	cout << "area = " << areaOfParallelogram(v, w, q) << endl << endl;


} // end Problem23

// Write a function that has three vec3 parameters. The parameters should give 
// three corners of a triangle in counter-clockwise order. In the function
// use the cross product to calculate the area of the triangle of call the 
// function you wrote for the previous quesion and multipley the returned area
// by on half. Test the function with the following vertices [ 0 2 0 ],
// [ 0 0 0 ] [4 0 0]. Print the result. Then test the function with another
// three vertices of you choosing Print out this area as well. The returned 
// areas should be positive for vertices in counter clockwise order.

double triangleArea2(vec3 a, vec3 b, vec3 c)
{
	vec3 u = b - a;
	vec3 v = c - a;

	return 0.5 * myLength(cross(u, v));

} // end triangleArea2

void problem24()
{
	vec3 a(0, 2, 0);
	vec3 b(0, 0, 0);
	vec3 c(4, 0, 0);

	double areaByOneHalf = areaOfParallelogram(a, b, c) / 2;
	cout << "Problem 24" << endl;
	cout << "Area = " << triangleArea2(a, b, c) << endl;
	cout << "Parallelogram / 2 = " << areaByOneHalf << endl;
	cout << "My own = " << areaOfParallelogram(vec3(0, 1, 5), vec3(4, 6, 2), vec3(10, 1, 1)) << endl << endl;


} // end Problem24

// Write a fucntion has two vec3 parameters. The function should find and 
// return a unit lenght vector that points from the position described by 
// the first vec3 to the position described by the seconds vec3. Test the 
// function with the following vectors. [ 0 4 0 ] [4 0 0]. Print the 
// result.
vec3 findPointingVector(vec3 first, vec3 second)
{

	return normalize(second - first);

} // end findPointingVector

void problem25()
{
	vec3 a(0, 4, 0);
	vec3 b(4, 0, 0);

	vec3 p = findPointingVector(a, b);

	cout << "Problem 25" << endl;
	cout << "pointing vecotr = " << "(" << p.x << ", " << p.y << ", " << p.z << ")" << endl << endl;


} // end Problem25


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
	problem9();
	problem10();
	problem11();
	problem12();
	problem13();
	problem14();
	problem15();
	problem16();
	problem17();
	problem18();
	problem19();
	problem20();
	problem21();
	problem22();
	problem23();
	problem24();
	problem25();

	return 0;

} // end main