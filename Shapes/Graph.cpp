#include "Graph.h"

#include "..//opAddLine.h"  //WHY INCLUDING OP LINE HERE??
#include <iostream>
#include "../GUI/GUI.h"
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
// get slected shape
shape* Graph::getselectedshape()const {
	return selectedShape;
}
// Remove a shape from list of shapes
void Graph::RemoveShape(shape* pShp) {
	shapesList.pop_back(); //this removes the last added shape
	//next step is to make a function that removes the shape by value in Remove shape feature
	//remove(shapesList.begin(), shapesList.end(), pShp);
}
///////////////////////////////////////////////////////////////////////////////////

// Delete a single shape from list of shape
void Graph::DeleteShape(shape* pShp) {
	std::vector<shape*>::iterator it;
	// std::find function call
	it = std::find(shapesList.begin(), shapesList.end(), pShp);
	shapesList.erase(it);

	

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

void Graph::Save(ofstream& outfile)
{


	for(auto shapesList:shapesList) // Loop on each shape in vector list 
	{
		

		shapesList->SAVE(outfile);
	}

}

void Graph::Load(ifstream& inputfile)
{

	arrayL = new int(size);
	i = 0;
	while (getline(inputfile, str))
	{
		data = stoi(str);
		arrayL[i] = data;
		i++;
	}

	//for (auto shapesList : shapesList) // Loop on each shape in vector list 
	//{


	//	shapesList->LOAD(inputfile); // LOAD captial function that exist in each shape 
	//}
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

void Graph::setFilled(bool a)
{
	isFilled = a;
}

