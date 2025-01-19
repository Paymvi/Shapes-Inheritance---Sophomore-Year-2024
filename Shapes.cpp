
// Author: Chelsea Alysson Ongjoco
// Student ID: 2552139
// Email: chelseaalysson.ongjoco@snhu.edu
// Assignment #: Project - Inheritance & Polymorphism
// Title : Shapes.cpp
// This is the where the methods/functions (mentioned in Shapes.h) are defined

#include "Shapes.h"
#include <iostream>
#include <math.h>
using namespace std;

const float PI = 3.14159f;

// Destructor
Shape:: ~Shape() {
}


// -------------------------------------------------------------- Shape 2D --------------------------------------------------------------------------------------------------------------


bool Shape2D:: operator>(const Shape2D &rhs) const {		// Operator overload (redefines what ">" does) for 2D shapes

	return this->Area() > rhs.Area();
}

bool Shape2D:: operator<(const Shape2D &rhs) const {		// Operator overload (redefines what "<" does) for 2D shapes

	return this->Area() < rhs.Area();
}

bool Shape2D:: operator==(const Shape2D& rhs) const {		// Operator overload (redefines what "==" does) for 2D shapes
	return this->Area() == rhs.Area();
}



// ------------- For 3D shapes -------------------------------
bool Shape3D:: operator>(const Shape3D &rhs) const {		// Operator overload (redefines what ">" does) for 3D shapes
	return this->Volume() > rhs.Volume();
}

bool Shape3D:: operator<(const Shape3D &rhs) const {		// Operator overload (redefines what "<" does) for 3D shapes
	return this->Volume() < rhs.Volume();
}

bool Shape3D:: operator==(const Shape3D &rhs) const {		// Operator overload (redefines what "==" does) for 3D shapes
	return this->Volume() == rhs.Volume();
}
// -----------------------------------------------------------


// --------------------------------------------------------------- SQUARE -----------------------------------------------------------

// Default Constructor
Square:: Square() {							
	name = "Square";
	side_length = 0;
}

// Constructor w/parameters
Square:: Square(float side) {				
	name = "Square";
	side_length = side;
}

// ------------------------------------------------- 2D override --------

// Returns area of Square
float Square:: Area() const {				
	return side_length * side_length;
}

// Displays the area of Square
void Square::ShowArea() const {				
	cout << "\tArea: " << Area() << endl;
}

// Returns name ("Square")
string Square::GetName2D() const {
	return name;
}

// ------------------------------------------------- shape override ------


// Scales/resizes the square
void Square:: Scale(float scale_factor) {
	side_length *= scale_factor;
}

// Prints the information of the square
void Square::Display() const {
	cout << "Display this " << name << "'s information:" << endl;
	ShowArea();
	cout << "\tLength of 1 side: " << side_length << endl;
	cout << endl;
}


// ------------------------------------------------------------- RECTANGLE ---------------------------------------------------------

// Default Constructor
Rectangle::Rectangle() {								
	name = "Rectangle";
	width = 0;
	height = 0;
}

// Constructor w/parameters
Rectangle::Rectangle(float w, float h) {				
	name = "Rectangle";
	width = w;
	height = h;
}

// ------------------------------------------------- 2D override --------

// Returns area of Rectangle
float Rectangle::Area() const {				
	return width * height;
}

// Displays the area of Rectangle
void Rectangle::ShowArea() const {				
	cout << "\tArea: " << Area() << endl;
}

// Returns name ("Rectangle")
string Rectangle::GetName2D() const {
	return name;
}

// ------------------------------------------------- shape override ------

// Scales/resizes the rectangle
void Rectangle:: Scale(float scale_factor) {

	width *= scale_factor;
	height *= scale_factor;

}

// Prints the information of the rectangle
void Rectangle::Display() const {

	cout << "Display this " << name << "'s information:" << endl;
	ShowArea();
	cout << "\tWidth: " << width << endl;
	cout << "\tHeight: " << height << endl;
	cout << endl;

}

// -------------------------------------------------------------- TRIANGLE ---------------------------------------------------------

// Default Constructor
Triangle::Triangle() {
	name = "Triangle";
	base = 0;
	height = 0;
}

// Constructor w/parameters
Triangle::Triangle(float b, float h) {
	name = "Triangle";
	base = b;
	height = h;
}

// ------------------------------------------------- 2D override --------

// Returns area of Triangle
float Triangle::Area() const {
	return 0.5 * (base * height);
}

// Displays the area of Triangle
void Triangle::ShowArea() const {
	cout << "\tArea: " << Area() << endl;
}

// Returns name ("Triangle")
string Triangle::GetName2D() const {
	return name;
}

// ------------------------------------------------- shape override ------

// Scales/resizes the triangle
void Triangle::Scale(float scale_factor) {

	base *= scale_factor;
	height *= scale_factor;

}

// Displays the information of the triangle
void Triangle::Display() const {

	cout << "Display this " << name << "'s information:" << endl;
	ShowArea();
	cout << "\tBase: " << base << endl;
	cout << "\tHeight: " << height << endl;
	cout << endl;

}


// -------------------------------------------------------------- CIRCLE ---------------------------------------------------------

// Default Constructor
Circle::Circle() {
	name = "Circle";
	radius = 0;
}

// Constructor w/parameters
Circle::Circle(float r) {
	name = "Circle";
	radius = r;
}

// ------------------------------------------------- 2D override --------

// Returns area of Circle
float Circle::Area() const {
	return  PI * radius * radius;
}

// Displays the area of Circle
void Circle::ShowArea() const {
	cout << "\tArea: " << Area() << endl;
}

// Returns name ("Circle")
string Circle::GetName2D() const {
	return name;
}

// ------------------------------------------------- shape override ------

// Scales/resizes the circle
void Circle::Scale(float scale_factor) {

	radius *= scale_factor;

}

// Displays the information of the circle
void Circle::Display() const {

	cout << "Display this " << name << "'s information:" << endl;
	ShowArea();
	cout << "\tRadius: " << radius << endl;
	cout << endl;

}



// -------------------------------------------------------------- ELLIPSE ---------------------------------------------------------

// Default Constructor
Ellipse:: Ellipse() {
	name = "Ellipse";
	len_major_axis = 0;
	len_minor_axis= 0;
}

// Constructor w/parameters
Ellipse:: Ellipse(float inputMajorAxis, float inputMinorAxis){
	name = "Ellipse";
	len_major_axis = inputMajorAxis;
	len_minor_axis = inputMinorAxis;
}

// ------------------------------------------------- 2D override --------

// Returns area of Ellipse
float Ellipse::Area() const {
	return  PI * len_minor_axis * len_major_axis;
}

// Displays the area of Ellipse
void Ellipse::ShowArea() const {
	cout << "\tArea: " << Area() << endl;
}

// Returns name ("Ellipse")
string Ellipse::GetName2D() const {
	return name;
}

// ------------------------------------------------- shape override ------

// Scales/resizes the ellipse
void Ellipse::Scale(float scale_factor) {

	len_major_axis *= scale_factor;
	len_minor_axis *= scale_factor;

}

// Displays the information of the ellipse
void Ellipse::Display() const {

	cout << "Display this " << name << "'s information:" << endl;
	ShowArea();
	cout << "\tlength of minor axis: " << len_minor_axis << endl;
	cout << "\tlength of major axis: " << len_major_axis << endl;
	cout << endl;

}

// -------------------------------------------------------------- TRAPEZOID ---------------------------------------------------------

// Default Constructor
Trapezoid::Trapezoid() {
	name = "Trapezoid";
	side1 = 0;
	side2 = 0;
	height = 0;
}

// Constructor w/parameters
Trapezoid::Trapezoid(float s1, float s2, float h) {
	name = "Trapezoid";
	side1 = s1;
	side2 = s2;
	height = h;
}

// ------------------------------------------------- 2D override --------

// Returns area of Trapezoid
float Trapezoid::Area() const {
	return  0.5 * (side1 + side2) * height;
}

// Displays the area of Trapezoid
void Trapezoid::ShowArea() const {
	cout << "\tArea: " << Area() << endl;
}

// Returns name ("Trapezoid")
string Trapezoid::GetName2D() const {
	return name;
}

// ------------------------------------------------- shape override ------

// Scales/resizes the trapezoid
void Trapezoid::Scale(float scale_factor) {

	side1 *= scale_factor;
	side2 *= scale_factor;
	height *= scale_factor;

}

// Displays the information of the trapezoid
void Trapezoid::Display() const {

	cout << "Display this " << name << "'s information:" << endl;
	ShowArea();
	cout << "\tside1: " << side1 << endl;
	cout << "\tside2: " << side2 << endl;
	cout << "\theight: " << height << endl;
	cout << endl;

}

// -------------------------------------------------------------- SECTOR ---------------------------------------------------------

// Default Constructor
Sector::Sector() {
	name = "Sector";
	radius = 0;
	angle = 0;
}

// Constructor w/parameters
Sector::Sector(float r, float a) {
	name = "Sector";
	radius = r;
	angle = a;
}

// ------------------------------------------------- 2D override --------

// Returns area of Sector
float Sector::Area() const {
	return  0.5 * (radius * radius) * ((angle*PI)/180);
}

// Displays the area of Sector
void Sector::ShowArea() const {
	cout << "\tArea: " << Area() << endl;
}

// Returns name ("Sector")
string Sector::GetName2D() const {
	return name;
}

// ------------------------------------------------- shape override ------

// Scales/resizes the sector
void Sector::Scale(float scale_factor) {

	radius *= scale_factor;
	angle *= scale_factor;
	
}

// Displays the information of the sector
void Sector::Display() const {

	cout << "Display this " << name << "'s information:" << endl;
	ShowArea();
	cout << "\tradius: " << radius << endl;
	cout << "\tangle (degrees): " << angle << endl;
	cout << endl;

}

// -------------------------------------------------------------- Shape 3D --------------------------------------------------------------------------------------------------------------


// ---------------------------------------------------------- TRIANGULAR PYRAMID -----------------------------------------------------------

// Default Constructor
TriangularPyramid::TriangularPyramid() {
	final_name = "TriangularPyramid";
	height2 = 0;
}


// Constructor w/parameters
TriangularPyramid::TriangularPyramid(float b, float h, float h2): height2(h2), Triangle(b, h) {
	final_name = "TriangularPyramid";
	height2 = h2;
}



// ------------------------------------------------- 3D override --------

// Returns area of TriangularPyramid
float TriangularPyramid::Volume() const {
	return  Triangle::Area() * height2 / 3;
}

// Displays the area of TriangularPyramid
void TriangularPyramid::ShowVolume() const {
	cout << "\tVolume: " << Volume() << endl;
}

// Returns name ("TriangularPyramid")
string TriangularPyramid::GetName3D() const {
	return final_name;
}

// ------------------------------------------------- shape override ------

// Scales/resizes the TriangularPyramid
void TriangularPyramid::Scale(float scale_factor) {

	base *= scale_factor;
	height *= scale_factor;
	height2 *= scale_factor;

}

// Displays the info of the TriangularPyramid
void TriangularPyramid::Display() const {

	cout << "Display this " << final_name << "'s information:" << endl;
	ShowVolume();
	ShowArea();
	cout << "\theight2: " << height2 << endl;
	cout << endl;

}

// ---------------------------------------------------------- RECTANGULAR PYRAMID -----------------------------------------------------------

// Default Constructor
RectangularPyramid::RectangularPyramid() {
	final_name = "RectangularPyramid";
	height2 = 0;
}


// Constructor w/parameters
RectangularPyramid::RectangularPyramid(float w, float h, float h2) : height2(h2), Rectangle(w, h) {
	final_name = "RectangularPyramid";
	height2 = h2;
}


// ------------------------------------------------- 3D override --------

// Returns area of RectangularPyramid
float RectangularPyramid::Volume() const {
	return  RectangularPyramid::Area() * height2 / 3;
}

// Displays the area of RectangularPyramid
void RectangularPyramid::ShowVolume() const {
	cout << "\tVolume: " << Volume() << endl;
}

// Returns name ("RectangularPyramid")
string RectangularPyramid::GetName3D() const {
	return final_name;
}

// ------------------------------------------------- shape override ------

// Scales/resizes the rectangularpyramid
void RectangularPyramid::Scale(float scale_factor) {

	width *= scale_factor;
	height *= scale_factor;
	height2 *= scale_factor;

}

// Displays the info of the rectangularpyramid
void RectangularPyramid::Display() const {

	cout << "Display this " << final_name << "'s information:" << endl;
	ShowVolume();
	ShowArea();
	cout << "\theight2: " << height2 << endl;
	cout << endl;

}

// ---------------------------------------------------------- Cylinder -----------------------------------------------------------

// Default Constructor
Cylinder::Cylinder() {
	final_name = "Cylinder";
	height2 = 0;
}


// Constructor w/parameters
Cylinder::Cylinder(float r, float h2) : height2(h2), Circle(r) {
	final_name = "Cylinder";
	height2 = h2;
}



// ------------------------------------------------- 3D override --------

// Returns area of Cylinder
float Cylinder::Volume() const {
	return  Cylinder::Area() * height2;
}

// Displays the area of Cylinder
void Cylinder::ShowVolume() const {
	cout << "\tVolume: " << Volume() << endl;
}

// Returns name ("Cylinder")
string Cylinder::GetName3D() const {
	return final_name;
}

// ------------------------------------------------- shape override ------

// Scales/resizes the cylinder
void Cylinder::Scale(float scale_factor) {

	radius *= scale_factor;
	height2 *= scale_factor;

}

// Displays the information of the cylinder
void Cylinder::Display() const {

	cout << "Display this " << final_name << "'s information:" << endl;
	ShowVolume();
	ShowArea();
	cout << "\theight2: " << height2 << endl;
	cout << "\tradius: " << radius << endl;
	cout << endl;

}


// ---------------------------------------------------------- SPHERE -----------------------------------------------------------

// Default Constructor
Sphere::Sphere() {
	final_name = "Sphere";
}

// Constructor w/parameters
Sphere::Sphere(float r): Circle(r) {
	final_name = "Sphere";
}


// ------------------------------------------------- 3D override --------

// Returns area of Sphere
float Sphere::Volume() const {
	return  4 * Sphere::Area() * radius / 3;
}

// Displays the area of Sphere
void Sphere::ShowVolume() const {
	cout << "\tVolume: " << Volume() << endl;
}

// Returns name ("Sphere")
string Sphere::GetName3D() const {
	return final_name;
}

// ------------------------------------------------- shape override ------

// Scales / resizes the sphere
void Sphere::Scale(float scale_factor) {

	radius *= scale_factor;

}

// Displays the information of the sphere
void Sphere::Display() const {

	cout << "Display this " << final_name << "'s information:" << endl;
	ShowVolume();
	ShowArea();
	cout << "\tradius: " << radius << endl;
	cout << endl;

}



// -----------------------------------------------------------------------------------------------------------------------------------------------------

// These will be overriden
void Shape2D::ShowArea() const {
}
void Shape3D::ShowVolume() const {
}
