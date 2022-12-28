#include "Graph.h"
#include <iostream>
#include"../CMUgraphicsLib/colors.h"
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
	//shapesList.clear(); // where and when clear list ??
	outfile << size(shapesList) << "\n";
	for(auto shapesList:shapesList) // Loop on each shape in vector list 
	{
		

		shapesList->SAVE(outfile);
	}
}
void Graph::load(ifstream& inputfile)
{
	string s;
	int size;
	string shapeName;
	shape* newShape;
	inputfile >> size;
	
	while(inputfile)
	{
		int verticies{};
		GfxInfo ShpGfxInfo;
		Point P1{}, P2{}, P3{};
		vector<Point> allPoints;
		inputfile >> shapeName;
		if (shapeName == "Line")
		{
			newShape = new Line(P1,P2, ShpGfxInfo);
			newShape->LOAD(inputfile);
			Addshape(newShape);
		}
		if (shapeName == "Triangle")
		{
			newShape = new Triangle(P1, P2, P3, ShpGfxInfo);
			newShape->LOAD(inputfile);
			Addshape(newShape);
		}

		if (shapeName == "Square")
		{
			newShape = new Square(P1, P2, ShpGfxInfo);
			newShape->LOAD(inputfile);
			Addshape(newShape);
		}

		if (shapeName == "Rect")
		{
			newShape = new Rect(P1, P2, ShpGfxInfo);
			newShape->LOAD(inputfile);
			Addshape(newShape);
		}

		if (shapeName == "IrrPolygon")
		{
			continue;
			/*newShape = new IrrPolygon(allPoints, verticies, ShpGfxInfo);
			newShape->LOAD(inputfile);
			Addshape(newShape);*/
		}
		if (shapeName == "RegularPolygon")
		{
			string isFilled;
			int ID;
			int x, y, z, a, b, c;
			Point center;
			double numOfVertices;
			int radius;
			GfxInfo RegularPolygonGfxInfo;
			inputfile >> ID >> center.x >> center.y >> numOfVertices >> radius >> x >> y >> z >> isFilled;
			RegularPolygonGfxInfo.DrawClr.ucBlue = x;
			RegularPolygonGfxInfo.DrawClr.ucGreen = y;
			RegularPolygonGfxInfo.DrawClr.ucRed = z;
			if (isFilled == "FILL")
			{
				inputfile >> a >> b >> c;
				RegularPolygonGfxInfo.FillClr.ucBlue = a;
				RegularPolygonGfxInfo.FillClr.ucGreen = b;
				RegularPolygonGfxInfo.FillClr.ucRed = c;
			}
			else
			{
				RegularPolygonGfxInfo.isFilled = 0;
			}
			inputfile >> RegularPolygonGfxInfo.BorderWdth;
			newShape = new RegularPolygon(center, numOfVertices, radius, RegularPolygonGfxInfo);
			Addshape(newShape);
		}
		if (shapeName == "Circle")
		{
			newShape = new Circle(P1, P2, ShpGfxInfo);
			newShape->LOAD(inputfile);
			Addshape(newShape);
		}
		if (shapeName == "Oval")
		{
			newShape = new Oval(P1, P2, ShpGfxInfo);
			newShape->LOAD(inputfile);
			Addshape(newShape);
		}

	}
	

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

