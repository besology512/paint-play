#include "Graph.h"
#include "../GUI/GUI.h"
#include<iostream>
using namespace std;
Graph::Graph()
{
	selectedShape = nullptr;
}

Graph::~Graph()
{
}

//==================================================================================//
//						shapes Management Functions								//
//==================================================================================//

//Add a shape to the list of shapes
void Graph::Addshape(shape* pShp)
{
	//Add a new shape to the shapes vector
	shapesList.push_back(pShp);

}
////////////////////////////////////////////////////////////////////////////////////
// Remove a shape from list of shapes
void Graph::RemoveShape(shape* pShp) {
	shapesList.pop_back(); //this removes the last added shape
	//next step is to make a function that removes the shape by value in Remove shape feature
	//remove(shapesList.begin(), shapesList.end(), pShp);
}
//Draw all shapes on the user interface
void Graph::Draw(GUI* pUI) const
{
	pUI->ClearDrawArea();
	for (auto shapePointer : shapesList)
		shapePointer->Draw(pUI);
}

//Unselect all the shapes in the shapelist
void Graph::UnselectAll()
{
	for (auto shapePointer : shapesList)
		shapePointer->SetSelected(false);
	selectedShape = nullptr;
}


shape* Graph::Getshape(int x, int y) 
{
	for (auto shapePointer = shapesList.rbegin(); shapePointer != shapesList.rend(); ++shapePointer)
	{
		if ((*shapePointer)->inShape(x, y))
		{
			//I may unselect all here
			selectedShape = (*shapePointer);
			return selectedShape;
			break; // I may comment that
		}
	}

	return nullptr;
}
 
//this function is used to get the color of drawing and filling, etc from the color pallet
//default color is black
color Graph::getPickedClr() {
	return color(pickedClr.dRed, pickedClr.dGreen, pickedClr.dBlue);
}
//this function sets the color and it is called by opPickColor only
void Graph::setPickedClr(double &dRed, double &dGreen, double &dBlue) {
	pickedClr.dRed = dRed;
	pickedClr.dGreen = dGreen;
	pickedClr.dBlue = dBlue;
}

//get the pointer to the selected shape
shape* Graph::getSelectedShape() const{
	return selectedShape;
}

vector <shape*> Graph::getShapesList() const {
	return shapesList;
}

void Graph::setFilled(bool a)
{
	isFilled = a;
}

//void Graph::changeUnselcFillClr() {
//	for (auto shapePointer = begin(shapesList)+counter; shapePointer != end(shapesList); ++shapePointer) {
//		(*shapePointer)->ChngFillClr(getPickedClr());
//	}
//	cout << counter;
//}