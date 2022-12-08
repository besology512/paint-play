#pragma once
#include "Shape.h"
#include <fstream>
#include <vector>
#include "../operations/operation.h"
#include "../controller.h"

using namespace std;

//forward decl
class GUI;

struct PickedColor {
	double dRed;
	double dGreen;
	double dBlue;
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
	//bool counting = true;
	//int counter = 0;
	bool isFilled = false;
	Graph();
	~Graph();
	void Addshape(shape* pFig); //Adds a new shape to the shapesList
	shape* getSelectedShape() const;
	void Draw(GUI* pUI) const;			//Draw the graph (draw all shapes)
	void UnselectAll();          // Unselect all the shapes
	string getShapeInfo();
	shape* getselectedshape() const;
	void setFilled(bool);

	void RemoveShape(shape* pShp);
	void DeleteShape(shape* pShp);			   // Delete a single shape from shape of list	
	shape* Getshape(int x, int y); //Search for a shape given a point inside the shape


	void Save(ofstream& outfile);	//Save all shapes to a file
	void Load(ifstream& inputfile);	//Load all shapes from a file
	color getPickedClr(); //get the current color
	void setPickedClr(double&,double&,double&); //set color using color picker
	// for load
	ifstream inputfile; // make output file to use in Save function
	string str; // variable that take data from getline function 
	int data;
	int* arrayL;
	int size;
	int i;
};