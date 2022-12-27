#pragma once
#include "Shape.h"

#include"../Shapes/Line.h"
#include"../Shapes/Triangle.h"
#include"../Shapes/Square.h"
#include"../Shapes/Rect.h"
#include"../Shapes/IrrPolygon.h"
#include"../Shapes/RegularPolygon.h"
#include"../Shapes/Circle.h"
#include"../Shapes/Oval.h"
#include <fstream>
#include <vector>
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
	vector <shape*> UndoneShapesList;
	shape* selectedShape;	//pointer to the currently selected shape
public:
	//bool counting = true;
	//int counter = 0;
	bool isFilled = false;
	Graph();
	~Graph();
	bool isSaved = false;		//boolean to check save & unsave shapes
	void Addshape(shape* pFig); //Adds a new shape to the shapesList
	shape* getSelectedShape() const;
	void Draw(GUI* pUI) const;			//Draw the graph (draw all shapes)
	void UnselectAll();          // Unselect all the shapes
	string getShapeInfo();
	shape* getselectedshape() const;
	bool getEmptyVector() const;
	void setFilled(bool);
	void DeleteShapesAfterExit();
	void PutInUndoShapes();
	void FromUndotoShapesList();
	void RemoveShape(shape* pShp);
	void DeleteShape(shape* pShp);			   // Delete a single shape from shape of list	
	shape* Getshape(int x, int y); //Search for a shape given a point inside the shape


	void Save(ofstream& outfile);	//Save all shapes to a file
	void load(ifstream& inputfile);	//Load all shapes from a file
	color getPickedClr(); //get the current color
	void setPickedClr(double&,double&,double&); //set color using color picker

};