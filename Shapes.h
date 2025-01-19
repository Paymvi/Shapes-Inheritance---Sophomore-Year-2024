#pragma once
// Author: Chelsea Alysson Ongjoco
// Student ID: 2552139
// Email: chelseaalysson.ongjoco@snhu.edu
// Assignment #: Project - Inheritance & Polymorphism
// Title : Shapes.h
// This is the header, and this is where the methods/functions for the Shapes project are declared


#include <iostream>
using namespace std;

// -------------------------------------------------------------

// The parent Shape class
class Shape {
public:
	virtual float Area() const = 0; //***				// Finds and returns the Area of the Shape
	virtual void Scale(float scale_factor) = 0;			// Scales (resizes) variables of the shape by the given scale_factor
	virtual void Display() const = 0;					// Displays the shape name, area/volume, and other variables
	virtual ~Shape() = 0;								// Deconstructor

};

// -------------------------------------------------------------

class Shape2D: virtual public Shape {

protected:
	string name;										// Stores the name of the shape

public:

	void ShowArea() const;								// Prints the area of the shape
	virtual string GetName2D() const = 0;				// Getter: name

	bool operator>(const Shape2D& rhs) const;			// Operator overload (redefines what ">" does) for 2D shapes
	bool operator<(const Shape2D& rhs) const;			// Operator overload (redefines what "<" does) for 2D shapes
	bool operator==(const Shape2D& rhs) const;			// Operator overload (redefines what "==" does) for 2D shapes

};


class Shape3D : virtual public Shape {

protected:
	string final_name;									// Stores the name of the shape

public:

	virtual float Volume() const = 0;					// Finds and returns the volume of the shape
	void ShowVolume() const;							// Prints the volume of the shape
	virtual string GetName3D() const = 0;				// Getter: finalName

	bool operator>(const Shape3D &rhs) const;			// Operator overload (redefines what ">" does) for 3D shapes
	bool operator<(const Shape3D &rhs) const;			// Operator overload (redefines what "<" does) for 3D shapes
	bool operator==(const Shape3D &rhs) const;			// Operator overload (redefines what "==" does) for 3D shapes

};



// -------------------------------------------------------------- Shape 2D --------------------------------------------------------------------------------------------------------------

// -- Square -------------------------------------------------------
class Square : virtual public Shape2D {

private:
	float side_length;									// Length of the square

public:

	Square();											// Constructor (no parameters)
	Square(float side);									// Constructor (with parameters)

	// 2D
	float Area() const override;						// Returns: the area of the square
	void ShowArea() const;								// Prints:  the area of the square 
	string GetName2D() const override;					// Getter:  the name of the shape... "Square"

	// shape
	void Scale(float scale_factor) override;				// Scales (resizes) variables of the square by the given scale_factor
	void Display() const override;						// Displays the shape name, area/volume, and other variables


};


// -- Rectangle ----------------------------------------------------
class Rectangle : virtual public Shape2D {

protected:
	float width;										// Width of rectangle (one of the sides)
	float height;										// Height of rectangle (one of the sides)

public: 

	Rectangle();										// Constructor (no parameters)
	Rectangle(float w, float h);						// Constructor (with parameters)

	// 2D
	float Area() const override;						// Returns: the area of the rectangle
	void ShowArea() const;								// Prints:  the area of the rectangle 
	string GetName2D() const override;					// Getter:  the name of the shape... "Rectangle"

	// shape
	void Scale(float scale_factor) override;				// Scales (resizes) variables of the rectangle by the given scale_factor 
	void Display() const override;						// Displays the shape name, area/volume, and other variables

};

// -- Triangle -----------------------------------------------------
class Triangle : virtual public Shape2D {

protected:
	float base;											// Base of the triangle
	float height;										// Height of the triangle

public:

	Triangle();											// Constructor (no parameters)
	Triangle(float b, float h);							// Constructor (with parameters)

	// 2D
	float Area() const override;						// Returns: the area of the triangle 
	void ShowArea() const;								// Prints:  the area of the triangle
	string GetName2D() const override;					// Getter:  the name of the shape... "Triangle"

	// shape
	void Scale(float scale_factor) override;				// Scales (resizes) variables of the triangle by the given scale_factor 
	void Display() const override;						// Displays the shape name, area/volume, and other variables

};

// -- Circle -------------------------------------------------------
class Circle : virtual public Shape2D {

protected:
	float radius;										// Radius of the circle

public:

	Circle();											// Constructor (no parameters)
	Circle(float r);									// Constructor (with parameters)

	// 2D
	float Area() const override;						// Returns: the area of the circle
	void ShowArea() const;								// Prints:  the area of the circle
	string GetName2D() const override;					// Getter:  the name of the shape... "Circle"

	// shape
	void Scale(float scale_factor) override;				// Scales (resizes) variables of the circle by the given scale_factor 
	void Display() const override;						// Displays the shape name, area/volume, and other variables

};

// -- Ellipse -------------------------------------------------------
class Ellipse : virtual public Shape2D {

protected:
	float len_major_axis;									// Length of the Major Axis of the ellipse
	float len_minor_axis;									// Length of the Minor Axis of the ellipse

public:

	Ellipse();											// Constructor (no parameters)
	Ellipse(float inputMajorAxis, float inputMinorAxis);// Constructor (with parameters)

	// 2D
	float Area() const override;						// Returns: the area of the ellipse
	void ShowArea() const;								// Prints:  the area of the ellipse
	string GetName2D() const override;					// Getter:  the name of the shape... "Ellipse"

	// shape
	void Scale(float scale_factor) override;				// Scales (resizes) variables of the ellipse by the given scale_factor  
	void Display() const override;						// Displays the shape name, area/volume, and other variables

};

// -- Trapezoid -----------------------------------------------------
class Trapezoid : virtual public Shape2D {

protected:
	float side1;										// 1st side of trapezoid
	float side2;										// 2nd side of trapezoid
	float height;										// height of trapezoid

public:

	Trapezoid();										// Constructor (no parameters)
	Trapezoid(float s1, float s2, float h);				// Constructor (with parameters)

	// 2D
	float Area() const override;						// Returns: the area of the trapezoid
	void ShowArea() const;								// Prints: the area of the trapezoid
	string GetName2D() const override;					// Getter: the name of the shape... "Trapezoid" 

	// shape
	void Scale(float scale_factor) override;				// Scales (resizes) variables of the trapezoid by the given scale_factor  
	void Display() const override;						// Displays the shape name, area/volume, and other variables

};


// -- Sector -------------------------------------------------------
class Sector : virtual public Shape2D {

protected:
	float radius;										// Radius of the sector
	float angle;										// Angle of the sector... in radians

public:

	Sector();											// Constructor (no parameters)
	Sector(float r, float a);							// Constructor (with parameters)

	// 2D
	float Area() const override;						// Returns: the area of the sector
	void ShowArea() const;								// Prints:  the area of the sector
	string GetName2D() const override;					// Getter:  the name of the shape... "Sector"

	// shape
	void Scale(float scale_factor) override;				// Scales (resizes) variables of the sector by the given scale_factor  
	void Display() const override;						// Displays the shape name, area/volume, and other variables

};


// -------------------------------------------------------------- Shape 3D --------------------------------------------------------------------------------------------------------------

// -- TriangularPyramid -------------------------------------------------------
class TriangularPyramid : virtual public Shape3D, private Triangle {

private:
	//Triangle t;
	float height2;										// height2 of the TriangularPyramid

public:

	TriangularPyramid();									// Constructor (no parameters)
	TriangularPyramid(float b, float h, float h2);		// Constructor (with parameters)

	// 3D
	float Volume() const override;						// Returns: the volume of the TriangularPyramid
	void ShowVolume() const;							// Prints:  the volume of the TriangularPyramid
	string GetName3D() const override;					// Getter:  the name of the shape... "TriangularPyramid"

	// shape
	void Scale(float scale_factor) override;				// Scales (resizes) variables of the TriangularPyramid by the given scale_factor 
	void Display() const override;						// Displays the shape name, area/volume, and other variables


};

// -- RectangularPyramid -------------------------------------------------------
class RectangularPyramid : virtual public Shape3D, private Rectangle {

private:
	float height2;										// The 2nd height of the RectangularPyramid

public:

	RectangularPyramid();								// Constructor (no parameters)
	RectangularPyramid(float b, float h, float h2);		// Constructor (with parameters)

	// 3D
	float Volume() const override;						// Returns: the volume of the RectangularPyramid
	void ShowVolume() const;							// Prints:  the volume of the RectangularPyramid
	string GetName3D() const override;					// Getter:  the name of the shape... "RectangularPyramid"

	// shape
	void Scale(float scale_factor) override;				// Scales (resizes) variables of the RectangularPyramid by the given scale_factor 
	void Display() const override;						// Displays the shape name, area/volume, and other variables


};

// -- Cylinder -------------------------------------------------------
class Cylinder : virtual public Shape3D, private Circle {

private:
	float height2;										// The 2nd height of the Cylinder

public:

	Cylinder();											// Constructor (no parameters)
	Cylinder(float r, float h2);						// Constructor (with parameters)

	// 3D
	float Volume() const override;						// Returns: the volume of the Cylinder
	void ShowVolume() const;							// Prints:  the volume of the Cylinder
	string GetName3D() const override;					// Getter:  the name of the shape... "Cylinder"

	// shape
	void Scale(float scale_factor) override;				// Scales (resizes) variables of the Cylinder by the given scale_factor 
	void Display() const override;						// Displays the shape name, area/volume, and other variables


};

// -- Sphere -------------------------------------------------------
class Sphere : virtual public Shape3D, private Circle {

private:

public:

	Sphere();											// Constructor (no paramaters)
	Sphere(float r);									// Constructor (with parameters)

	// 3D
	float Volume() const override;						// Returns: the volume of the Sphere
	void ShowVolume() const;							// Prints: the volume of the Sphere
	string GetName3D() const override;					// Getter: the name of the shape... "Sphere"

	// shape
	void Scale(float scale_factor) override;				// Scales (resizes) variables of the Sphere by the given scale_factor 
	void Display() const override;						// Displays the shape name, area/volume, and other variables


};