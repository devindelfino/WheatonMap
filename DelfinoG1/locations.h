/*
 * Name: Devin Delfino
 *
 * Filename: locations.h
 *
 * Description: This program draws a map of the Wheaton College Campus.
 * 				Complete with all buildings, parking lots, and nearby roads,
 *  			this map allows the user to interactively navigate through Wheaton.
 *				The setup of this program includes a custom Location class, as well as Housing,
 *				Dining, Pavement, Grass, Academic, CampusBuilding, Circle, and Abstract derived class that
 *				all inherit from the parent class Location. Encapsulated within these classes are various
 *				data members including two floating point values representing the coordinates of the label,
 *				a string representing the name of the Location, two float pointers that will later point to
 *				two arrays of x and y float values, and three floats representing the red, green, and blue
 *				values that are combined to create colors.
 *
 * Input: This program has a variety of different keyboard commands that allow the user to interact with the map.
 *		  These keyboard inputs include the 'c', 'f', 'd', 'l', 'k', 's', 'L', 'R', '7', '8', '9', '0', and 'q'.
 *		  The effects are as follows: 'c' highlights the Chapel, 'f' highlights Haas Athletic Center, 'd' highlights
 *		  all student dorms and houses, 'l' highlights the library, 's' highlights the MARS Science Center, 'q' quits the program, 'k' toggles
 *		  the legend on/of, 'w' toggles the foot paths on/off, 'R' toggles the roads on/off, and 'L' toggles the labels
 *		  on/off. When labels are off with a keyboard input of 'R', the program enters super interactive mode, and a small
 *		  dark blue circle can be controlled using the '7', '8', '9', and '0' keys where '7' is left, '8' is down,
 *		  '9' is up, and '0' is right.
 *			    
 * Output: At the start of the program, directions on how to use the map effectively are included in the console window
 * 		   as standard output. Being a visual map, the program will obviously display images to another window allowing
 *		   the user to control the functionality. The map will respond accordingly to the user's keyboard inputs, and when in
 *		   super interactive mode, the names of the locations will be displayed in the visual window whenever the blue cursor
 *		   is located in an important location on campus.
 */

using namespace std;		// stdlib
#include <iostream>			// cout statements
#include <GL/glut.h>		// openGL required glut.h
#include <math.h>			// math.h is required for the sin() and cos() function used in generating circles
//#include <vector>			// vectors are used to store various types of Location objects

#ifndef LOC
#define LOC

class Location
{
protected:
	float xLabel;					// a floating point value representing the x value of the coordinate pair for the location's label
	float yLabel;					// a floating point value representing the 7 value of the coordinate pair for the location's label
	string name;					// a string representing the name of the location
	float* xcoords;					// a float pointer used to store an array of floats for the x coordinates of the vertices
	float* ycoords;					// a float pointer used to store an array of floats for the y coordinates of the vertices
	float r, g, b;					// floats representing the colors for the particular class
public:
	Location();						// empty constructor for Location object
	~Location();					// destructor
	void reDraw();					// a method that draws the object 
	void highlight();				// a method that highlights the object by turning it neon yellow
	void label();					// a method drawing the label of the object
	bool findPosition(float,float);	// a method that takes in an x and y coordinate pair of floats and check to see if they lie inside the object's boundaries
	string getName();				// returns the name of the object
};

class Housing : public Location
{
public:
	Housing(string,float*,float*,float,float);	//Parameterized constructor for the derived class Housing
};

class Academic : public Location
{
public:
	Academic(string,float*,float*,float,float); //Parameterized constructor for the derived class Academic
};

class Grass : public Location
{
public:
	Grass(string,float*,float*,float,float);	//Parameterized constructor for the derived class Grass

};

class Dining : public Location
{
public:
	Dining(string,float*,float*,float,float);	//Parameterized constructor for the derived class Dining
};

class CampusBuilding : public Location
{
public:
	CampusBuilding(string,float*,float*,float,float);	//Parameterized constructor for the derived class CampusBuilding
};

class Pavement : public Location
{
public:
	Pavement(string,float*,float*,float,float);			//Parameterized constructor for the derived class Pavement
};

class Circle : public Location
{
public:
	Circle(string);										//Parameterized constructor for the derived class Circle
};

class Abstract : public Location
{
public:
	Abstract(string, short,float,float, float*,float*,float, float, char);	//Parameterized constructor for the derived class Abstract
};

#endif