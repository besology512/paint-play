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
#include<stack>
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
	vector <shape*> ClonedShapes;
	shape* selectedShape;	//pointer to the currently selected shape
	vector <Point> vectorPoints; // vector has grid of points 
	vector <shape*> selectedShapes;
	vector <shape*> matchedShapes;

public:
	stack<shape*> lastEdited;
	stack<shape*> undolastEdited;
	stack<shape*> UndolastEdited;
	bool isFilled = false;
	Graph();
	~Graph();
	bool isSaved = false;		//boolean to check save & unsave shapes
	void Addshape(shape* pFig); //Adds a new shape to the shapesList
	void addSelectedShape(shape* pFig);
	void deleteSelectedShapes();
	shape* getSelectedShape() const;
	void Draw(GUI* pUI) const;			//Draw the graph (draw all shapes)
	void UnselectAll();          // Unselect all the shapes
	string getShapeInfo();
	shape* getLastShape() const;
	shape* getLastRedoShape() const;
	shape* getselectedshape() const;
	bool getEmptyVector() const;
	void setFilled(bool);
	void DeleteShapesAfterExit();
	void PutInUndoShapes();
	void FromUndotoShapesList();
	void ZOOMING(double scale, int x, int y);
	void Hideing(GUI* pUI);							//to hide shapes when switch to play mode
	void Unhideing(GUI* pUI);							//to hide shapes when switch to play mode

	void RemoveShape(shape* pShp);
	void DeleteShape(shape* pShp);			   // Delete a single shape from shape of list	
	void SendbackShape(shape* pShp);           // Send a single shpe to the last indes in the vector
	shape* Getshape(int x, int y); //Search for a shape given a point inside the shape
	void addToCloned(shape* pShp);
	vector <shape*> getClonedShapes();
	vector <shape*> getMatchedShapes();
	void Save(ofstream& outfile);	//Save all shapes to a file
	void load(ifstream& inputfile);	//Load all shapes from a file
	void scramble();				// scramble function to pass on all shapes
	color getPickedClr(); //get the current color
	void setPickedClr(double&,double&,double&); //set color using color picker
	void ClearClipboard();
	void fillArray(); //fill array with point to use in scramble 
	void duplicateShapes();
	void addMatchedShape(shape*);
	void clearMatchedShapes();

};