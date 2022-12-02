#pragma once
#include "Shape.h"
#include <fstream>
#include <vector>
using namespace std;

//forward decl
class GUI;

struct PickedColor {
	double dRed = 0;
	double dGreen = 0;
	double dBlue = 0;
	//black color is the default color
};
//A class that is responsible on everything related to shapes
class Graph
{
private:
	PickedColor pickedClr;
	vector <shape*> shapesList; //a container to hold all shapes							   
	shape* selectedShape;	//pointer to the currently selected shape
public:										
	Graph();
	~Graph();
	void Addshape(shape* pFig); //Adds a new shape to the shapesList

	void Draw(GUI* pUI) const;			//Draw the graph (draw all shapes)
	void UnselectAll();          // Unselect all the shapes
	shape* Getshape(int , int ); //Search for a shape given a point inside the shape
	string getShapeInfo();

	void RemoveShape(shape* pShp);
	void Draw(GUI* pUI) const;		//Draw the graph (draw all shapes)
	shape* Getshape(int x, int y) const; //Search for a shape given a point inside the shape


	void Save(ofstream& outfile);	//Save all shapes to a file
	void load(ifstream& inputfile);	//Load all shapes from a file
	color getPickedClr(); //get the current color
	void setPickedClr(double,double,double); //set color using color picker
};