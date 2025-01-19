
// Author: Chelsea Alysson Ongjoco
// Student ID: 2552139
// Email: chelseaalysson.ongjoco@snhu.edu
// Assignment #: Project - Inheritance & Polymorphism
// Title : Main.cpp
// This is the driver class (user interface program) for Shapes. This program creates many shapes, 2D and 3D, and allows the user to see the shapes' properties and search/sort through the shapes.

#include "Shapes.h"
#include <iostream>
#include <vector>
using namespace std;

// insertion sort returns sorted shapes list
vector<Shape2D*> insertionSort(vector<Shape2D*> arr, int n) { // Make sure you make it Shape2D* And NOT just Shape!!!

	int i, j;			// variables for the loops
	Shape2D* hold;		// holds the current element during insertion


	// Loop through the shapes in the array starting from the 2nd shape
	for (i = 1; i < n; i++) {

		hold = arr[i];			// store current element(shape) in hold
		j = i - 1;				// j is the previous element's index

		// Shift elements of the sorted part of the shapes list if their area is greater than hold's area
		while (j >= 0 && *arr[j] > *hold) {

			arr[j + 1] = arr[j];
			j = j - 1;
			arr[j + 1] = hold;
		}
	}

	return arr; // return the sorted list of 2D shapes

	
}

// Searches the sorted list to see if there is a shape with an area greater than or equal to the given x
int binarySearch(vector<Shape2D*> arr, float x, int low, int high) {

	// Repeat until the low and high meet each other

	while (low <= high) {


		int mid = low + (high - low) / 2;	// calculate mid and store it

			if (arr[mid]->Area() >= x) {	// compares to see if the shape at mid has an area greater than or equal to the target... if yes then return mid
				return mid;
			}
		if (arr[mid]->Area() < x) {			// update the low if the shape's area is lower than the target
			low = mid + 1;
		}
		else {
			high = mid - 1;					// update the high is the shape's area is higher than the target
		}

	}
	
	return -1; // if there is no shape that is greater than or equal to x

}



int main()
{
	/* Asked professor if it was okay to move the code that makes the shapes to the top on 12/4/2024, 10 am, and it was approved */

	// ------------------------------------ Populate shapes2D with 14 2D shapes ------------------------------------
	vector <Shape2D*> shapes2D;

	shapes2D.push_back(new Square);							// Make a Square x2
	shapes2D.push_back(new Square(2.0));

	shapes2D.push_back(new Rectangle);						// Make a Rectangle x2
	shapes2D.push_back(new Rectangle(2.0, 4.0));

	shapes2D.push_back(new Triangle);						// Make a Triangle x2
	shapes2D.push_back(new Triangle(2.0, 2.0));

	shapes2D.push_back(new Circle);							// Make a Circle x2
	shapes2D.push_back(new Circle(2.0));

	shapes2D.push_back(new Ellipse);						// Make an Ellipse x2
	shapes2D.push_back(new Ellipse(4.0, 2.0));

	shapes2D.push_back(new Trapezoid);						// Make a Trapezoid x2
	shapes2D.push_back(new Trapezoid(2.0, 4.0, 5.0));

	shapes2D.push_back(new Sector);							// Make a Sector x2
	shapes2D.push_back(new Sector(5.0, 90));


	// ------------------------------------ Populate shapes3D with 8 3D shapes ------------------------------------
	vector <Shape3D*> shapes3D;
	shapes3D.push_back(new TriangularPyramid);							// Make a TriangularPyramid x2
	shapes3D.push_back(new TriangularPyramid(2.0, 2.0, 5.0));

	shapes3D.push_back(new RectangularPyramid);							// Make a Rectangular Pyramid x2
	shapes3D.push_back(new RectangularPyramid(2.0, 2.0, 5.0));

	shapes3D.push_back(new Cylinder);									// Make a Cylinder x2
	shapes3D.push_back(new Cylinder(2.0, 5.0));

	shapes3D.push_back(new Sphere);										// Make a Sphere x2
	shapes3D.push_back(new Sphere(2.0));


	// ------------------------------------ Populate shapes2D3D with 22 2D & 3D shapes ------------------------------------
	vector <Shape*> shapes2Dand3D;

	shapes2Dand3D.push_back(new Square);							// Make a Square x2
	shapes2Dand3D.push_back(new Square(2.0));

	shapes2Dand3D.push_back(new Rectangle);							// Make a Rectangle x2
	shapes2Dand3D.push_back(new Rectangle(2.0, 4.0));

	shapes2Dand3D.push_back(new Triangle);							// Make a Triangle x2
	shapes2Dand3D.push_back(new Triangle(2.0, 2.0));

	shapes2Dand3D.push_back(new Circle);							// Make a Circle x2
	shapes2Dand3D.push_back(new Circle(2.0));

	shapes2Dand3D.push_back(new Ellipse);							// Make an Ellipse x2
	shapes2Dand3D.push_back(new Ellipse(4.0, 2.0));

	shapes2Dand3D.push_back(new Trapezoid);							// Make a Trapezoid x2
	shapes2Dand3D.push_back(new Trapezoid(2.0, 4.0, 5.0));

	shapes2Dand3D.push_back(new Sector);							// Make a Sector x2
	shapes2Dand3D.push_back(new Sector(5.0, 90));

	shapes2Dand3D.push_back(new TriangularPyramid);					// Make a TriangularPyramid x2
	shapes2Dand3D.push_back(new TriangularPyramid(2.0, 2.0, 5.0));

	shapes2Dand3D.push_back(new RectangularPyramid);				// Make a Rectangular Pyramid x2
	shapes2Dand3D.push_back(new RectangularPyramid(2.0, 2.0, 5.0));

	shapes2Dand3D.push_back(new Cylinder);							// Make a Cylinder x2
	shapes2Dand3D.push_back(new Cylinder(2.0, 5.0));

	shapes2Dand3D.push_back(new Sphere);							// Make a Sphere x2
	shapes2Dand3D.push_back(new Sphere(2.0));


	int choice = 0;			// Declares variable to store user input
	bool running = true;	// Used to continue or stop the menu loop accordingly

	while (running) {

		if (choice == 0) {

			// Display menu of choices to the user
			cout << "----------------------------------------------------------------------------------------------- " << endl;
			cout << "[1] Test 2D shapes (14 shapes)" << endl;
			cout << "[2] Test 3D shapes (8 shapes)" << endl;
			cout << "[3] Test mixing 2D and 3D shapes (22 shapes)" << endl;
			cout << "[4] Test the scaling function" << endl;
			cout << "[5] Get largest/smallest 2D shapes" << endl;
			cout << "[6] Get largest/smallest 3D shapes" << endl;
			cout << "[7] Sort and Search" << endl;
			cout << "[8] Quit" << endl;
			cout << "----------------------------------------------------------------------------------------------- " << endl;

			cin >> choice; // store user choice

			// to catch invalid inputs
			if (cin.fail()) {
				cout << "[INVALID INPUT]" << endl;
				break;
			}


		}
		else if (choice == 1) {
			
			cout << "--------------------------------------- 2D Shapes -------------------------------------- " << endl;
			// Test 2D shapes (14 shapes)

			// Display all 2D shapes
			for (unsigned int i = 0; i < shapes2D.size(); i++) {
				cout << i + 1 << ". ";
				shapes2D[i]->Display();
			}
			
			choice = 0; // restart loop

		}
		else if (choice == 2) {

			cout << "--------------------------------------- 3D Shapes -------------------------------------- " << endl;
			// Test 3D shapes (8 shapes)

			// Display all 3D shapes
			for (unsigned int i = 0; i < shapes3D.size(); i++) {
				cout << i + 1 << ". ";
				shapes3D[i]->Display();
			}

			choice = 0; // restart loop
		}
		else if (choice == 3) {

			cout << "--------------------------------------- 2D and 3D Shapes -------------------------------------- " << endl;
			// Test mixing 2D and 3D shapes (22 shapes)

			// Display all 2D and 3D shapes
			for (unsigned int i = 0; i < shapes2Dand3D.size(); i++) {
				cout << i + 1 << ". ";
				shapes2Dand3D[i]->Display();
			}

			choice = 0; // restart loop

		}
		else if (choice == 4) {

			cout << "--------------------------------------- 2D and 3D Shapes -------------------------------------- " << endl;
			// Test the scaling function

			float scale_factor;							// Stores the factor for scaling
			cout << "Input your scale factor: ";		// Ask the user for the scale factor
			cin >> scale_factor;

			if (cin.fail()) {
				cout << "[INVALID INPUT]" << endl;
				break;
			}

			cout << "Scaling..." << endl << endl;

			// Display all the shapes after scaling with the scale factor
			for (unsigned int i = 0; i < shapes2Dand3D.size(); i++) {
				cout << i+1 << ". SCALED: ";
				shapes2Dand3D[i]->Scale(scale_factor);
				shapes2Dand3D[i]->Display();
				cout << endl;
			}

			choice = 0; // restart loop

		}
		else if (choice == 5) {

			cout << "------------------------------ Finding smallest/largest 2D Shape ----------------------------- " << endl;
			// Get largest/smallest 2D shapes

			int small_index = 0;		// Stores index of the shape w/ the SMALLEST area
			int large_index = 0;		// Stores index of the shape w/ the LARGEST area


			// since it is starting at 0 anyway the comparisions should start at 1
			for (unsigned int i = 1; i < shapes2D.size(); i++) { 
				
				if (*shapes2D[i] < *shapes2D[small_index]){	// Updates small_index if it finds a shape with a smaller area
					small_index = i;
				}

				if (*shapes2D[large_index] < *shapes2D[i]) {	// Updates large_index if it finds a shape with a smaller area
					large_index = i;
				}

			}

			cout << "Smallest 2D Shape: ";
			shapes2D[small_index]->Display();	// Display SMALLEST shape

			cout << "Largest 2D Shape: ";
			shapes2D[large_index]->Display();	// Display LARGEST shape

			choice = 0; // restart loop

		}
		else if (choice == 6) {

			cout << "------------------------------ Finding smallest/largest 2D Shape ----------------------------- " << endl;
			// Get largest/smallest 3D shapes

			int small_index = 0;		// Stores index of the shape w/ the SMALLEST area
			int large_index = 0;		// Stores index of the shape w/ the LARGEST area


			for (unsigned int i = 1; i < shapes3D.size(); i++) {

				if (*shapes3D[i] < *shapes3D[small_index]) {	// Updates small_index if it finds a shape with a smaller volume
					small_index = i;
				}

				if (*shapes3D[large_index] < *shapes3D[i]) {	// Updates small_index if it finds a shape with a smaller volume
					large_index = i;
				}

			}

			cout << "Smallest 3D Shape: ";
			shapes3D[small_index]->Display();	// Display SMALLEST 3D shape

			cout << "Largest 3D Shape: ";
			shapes3D[large_index]->Display();	// Display LARGEST 3D shape

			choice = 0; // restart loop

		}
		else if (choice == 7) {
			// Sort and Search

			// [a] First, implement your Insertion Sorting Algorithm to sort the list of 2D shapes that you have in option 1 (Test 2D shapes). -----------------------------

			vector<Shape2D*> sorted2DShapes = insertionSort(shapes2D, shapes2D.size());		// Use insertion sort to sort 2D shapes ...store into "sorted2Dshapes"

			cout << "--------------------------- Here is your sorted list of 2D shapes ---------------------------" << endl;

			for (int i = 0; i < shapes2D.size(); i++) {										// Display content of sorted2DShapes
				sorted2DShapes[i]->Display();
			}

			// [b] Then, implement your Binary Search Algorithm to search for a 2D shape, which has an area greater than or equal a certain area that will be taken as input.

			float input;	// stores user input for the area
			int output;		// stores the index of the resulting shape after the search (-1 if not found)

			// Asks user for input
			cout << "--------- NOW... --------- " << endl;
			cout << "\n Search for a 2D shape with an area >= a certain area..." << "\n Input this area: " << endl;
			cin >> input;
			
			output = binarySearch(sorted2DShapes, input, 0, shapes2D.size()-1); // use the sorted shapes

			// Outputs the results to the user
			if (output != -1) {
				cout << "Found a shape! Here is one of them..." << endl;						// if found
				sorted2DShapes[output]->Display();
			}
			else {
				cout << "Sorry! There is no shape with an area >= the area you gave" << endl;	// if not found
			}

			
			choice = 0; // restart loop
		}
		else if (choice == 8) {

			break;	// Will break out of the loop and quit the program
		
		}
		else { // For input that doesn't correspond to the menu options

			cout << "[INVALID INPUT] Please try again. " << endl;
			choice = 0;
		}
	
	
	}

	// After exiting the while loop, delete the shapes from the vectors
	for (unsigned int i = 0; i < shapes2D.size(); i++) delete shapes2D[i];
	for (unsigned int i = 0; i < shapes3D.size(); i++) delete shapes3D[i];
	for (unsigned int i = 0; i < shapes2Dand3D.size(); i++) delete shapes2Dand3D[i];

	return 0;

}
