/*
 * Name: Devin Delfino
 *
 * Filename: locations.cpp
 *
 * Description: This program add functionality the the Location class, as well as its derived classes
 *
 */

#include "locations.h"	//includes locations.h
GLenum rgb;				//global used in tkmap.c for bitmap text
#include "tkmap.c"		// required for bitmap text

Location::Location()
// Empty Constructor
{
	//
}

Location::~Location()
// Empty Destructor
{
	//delete[] xcoords;
	//delete[] ycoords;
}

string Location::getName()
// Returns the name of the Location object
// Pre: A Location object or one of its derived objects has been constructed
// Post: The name of the object will be returned as a string
{
	return name;
}

void Location::highlight()
{
// Highlights the object on the map by changing its color to bright yellow
// Pre: The user has entered keyboard input that requires certain objects to be highlighted
// Post: The object calling this method will be colored bright yellow, and global boolean variable
// will swap its values
	glColor3f(0.953, 0.953, 0.082);
	glBegin(GL_POLYGON);
		for(int i=0;i<4;i++)
		{
			glVertex3f(xcoords[i],ycoords[i],0.0);
		}
	glEnd();
}

void Location::reDraw()
// Draws the shape of the object on the campus map, whether it is the first render, or a rerendering
// of the object after it has been highlighted.
// Pre: Either the program has just started running and the locations are being drawn, or the location
// 		is being redrawn its original color after the user had chosen to highlight.
// Post: The object will be returned to its usual color
{
	glColor3f(r,g,b);
	glBegin(GL_POLYGON);
		for(int i=0;i<4;i++)
		{
			glVertex3f(xcoords[i],ycoords[i],0.0);
		}
	glEnd();
}

void Location::label()
// Draws the corresponding label for the object, according to its name datamember
// Pre: Either the program has just started running and the labels are being drawn, or the labels
//		are being toggled on by user input via keyboard.
// Post: The object's label will be visible on the map, and super interactive mode will be disabled
{
	glColor3f(0,0,0);
	glRasterPos2f(xLabel,yLabel);
	for(int i=0;i<name.size();i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,name[i]);
	}
}

bool Location::findPosition(float x,float y)
// Returns a boolean indicating if a given x,y coordinate pair is located within the boundaries
// of the object
// Parameters: x - a float representing the x coordinate of the given point
//			   y - a float representing the y coordinate of the given point
// Pre: The program is either just beginning, or the user is currently in super interactive mode
// Post: Returns true if the given point is found within the objects boundaries
{
	if((xcoords[1]<x) && (x<xcoords[3]) && (ycoords[0] < y) && (y < ycoords[2]))
	{
		return true;
	}
	else
	{
		return false;
	}
}

//-----------------------------------------------------------------

Housing::Housing(string n,float* x,float* y,float xlab,float ylab)
// Initializes a Housing object (Parameterized Constructor)
// Parameters: n - a string representing the name of the location
//			   x - a float pointer that holds an array of floats representing x values
//			   y - a float pointer that holds an array of floats representing y values
//			   xlab - a float indicating the x coordinate of the location's label
//			   ylab - a float indication the y coordinate of the location's label
// Pre: The program has just started, and it is running through all of its draw functions
// Post: A Housing object will be initialized, and the object and its label will be drawn to the map
{
	r = 0.6;
	g =  0.4;
	b = 1;
	name = n;
	xLabel = xlab;
	yLabel = ylab;
	xcoords = x;
	ycoords = y;
	// will be in draw method
	reDraw();
}

Grass::Grass(string n,float* x,float* y,float xlab,float ylab)
// Initializes a Grass object (Parameterized Constructor)
// Parameters: n - a string representing the name of the location
//			   x - a float pointer that holds an array of floats representing x values
//			   y - a float pointer that holds an array of floats representing y values
//			   xlab - a float indicating the x coordinate of the location's label
//			   ylab - a float indication the y coordinate of the location's label
// Pre: The program has just started, and it is running through all of its draw functions
// Post: A Grass object will be initialized, and the object and its label will be drawn to the map
{
	r = 0.322;
	g = 0.435;
	b = 0.208;
	name = n;
	xLabel = xlab;
	yLabel = ylab;
	xcoords = x;
	ycoords = y;
	// will be in draw method
	reDraw();
}

Pavement::Pavement(string n,float* x,float* y,float xlab,float ylab)
// Initializes a Pavement object (Parameterized Constructor)
// Parameters: n - a string representing the name of the location
//			   x - a float pointer that holds an array of floats representing x values
//			   y - a float pointer that holds an array of floats representing y values
//			   xlab - a float indicating the x coordinate of the location's label
//			   ylab - a float indication the y coordinate of the location's label
// Pre: The program has just started, and it is running through all of its draw functions
// Post: A Pavement object will be initialized, and the object and its label will be drawn to the map
{
	r = 0.533;
	g = 0.533;
	b = 0.533;
	name = n;
	xLabel = xlab;
	yLabel = ylab;
	xcoords = x;
	ycoords = y;
	// will be in draw method
	reDraw();
}

Dining::Dining(string n,float* x,float* y,float xlab,float ylab)
// Initializes a Dining object (Parameterized Constructor)
// Parameters: n - a string representing the name of the location
//			   x - a float pointer that holds an array of floats representing x values
//			   y - a float pointer that holds an array of floats representing y values
//			   xlab - a float indicating the x coordinate of the location's label
//			   ylab - a float indication the y coordinate of the location's label
// Pre: The program has just started, and it is running through all of its draw functions
// Post: A Dining object will be initialized, and the object and its label will be drawn to the map
{
	r = 0.714;
	g = 0.584;
	b = 0.129;
	name = n;
	xLabel = xlab;
	yLabel = ylab;
	xcoords = x;
	ycoords = y;
	// will be in draw method
	reDraw();
}

Academic::Academic(string n,float* x,float* y,float xlab,float ylab)
// Initializes an Academic object (Parameterized Constructor)
// Parameters: n - a string representing the name of the location
//			   x - a float pointer that holds an array of floats representing x values
//			   y - a float pointer that holds an array of floats representing y values
//			   xlab - a float indicating the x coordinate of the location's label
//			   ylab - a float indication the y coordinate of the location's label
// Pre: The program has just started, and it is running through all of its draw functions
// Post: An Academic object will be initialized, and the object and its label will be drawn to the map
{
	r = 0.498;
	g = 0.09;
	b = 0.412;
	name = n;
	xLabel = xlab;
	yLabel = ylab;
	xcoords = x;
	ycoords = y;
	// will be in draw method
	reDraw();
}

CampusBuilding::CampusBuilding(string n,float* x,float* y,float xlab,float ylab)
// Initializes a CampusBuilding object (Parameterized Constructor)
// Parameters: n - a string representing the name of the location
//			   x - a float pointer that holds an array of floats representing x values
//			   y - a float pointer that holds an array of floats representing y values
//			   xlab - a float indicating the x coordinate of the location's label
//			   ylab - a float indication the y coordinate of the location's label
// Pre: The program has just started, and it is running through all of its draw functions
// Post: A CampusBuilding object will be initialized, and the object and its label will be drawn to the map
{
	r = 0.867;
	g = 0.118;
	b = 0.184;
	name = n;
	xLabel = xlab;
	yLabel = ylab;
	xcoords = x;
	ycoords = y;
	// will be in draw method
	reDraw();
}

Circle::Circle(string n)
// Initializes a Circle object (Parameterized Constructor)
// Parameters: n - a string representing the name of the location
// Pre: The program has just started, and it is running through all of its draw functions
// Post: A Circle object will be initialized, and the object and its label will be drawn to the map
{
	r = 0.714;
	g = 0.584;
	b = 0.129;
	name = n;
	
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(60.2, 61.8); // center of circle
	for(int i = 0; i <= 30;i++)
	{
		glVertex2f(
		60.2 + (1.2 * cos(i * (2.0f*3.14159) / 20)),
		61.8 + (1.2 * sin(i * (2.0f*3.14159) / 20)));
	}
	glEnd();
}

Abstract::Abstract(string n, short numV,float origX,float origY, float* x,float* y,float xlab, float ylab, char type)
// Initializes an Abstract object (Parameterized Constructor)
// Parameters: n - a string representing the name of the location
//			   numV - a short representing the number of vertices in the abstract object
//			   origX - a float representing the x value of the center point (origin) of the circle
//			   origY - a float representing the y value of the center point (origin) of the circle
//			   x - a float pointer that holds an array of floats representing x values
//			   y - a float pointer that holds an array of floats representing y values
//			   xlab - a float indicating the x coordinate of the location's label
//			   ylab - a float indication the y coordinate of the location's label
//			   type - a char indicating what type of object this is (options are 'p','g', or 'w')
// Pre: The program has just started, and it is running through all of its draw functions
// Post: An Abstract object will be initialized, and the object and its label will be drawn to the map
{
	name = n;
	xLabel = xlab;
	yLabel = ylab;
	if(type=='p')
	{
		r = 0.533;
		g = 0.533;
		b = 0.533;
	}
	else if(type=='g')
	{
		r = 0.322;
		g = 0.435;
		b = 0.208;
	}
	else
	{
		r = 0.11;
		g = 0.42;
		b = 0.627;
	}
	glColor3f(r,g,b);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(origX,origY);
	for(int i=0;i<numV;i++)
	{
		glVertex2f(x[i],y[i]);
	}
	glEnd();
}