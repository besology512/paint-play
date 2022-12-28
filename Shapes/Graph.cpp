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
		inputfile >> shapeName;
		if (shapeName == "Line")
		{
			GfxInfo LineGfxInfo;
			Point P1{}, P2{};
			newShape = new Line(P1,P2,LineGfxInfo);
			newShape->LOAD(inputfile);
			Addshape(newShape);
		}
		if (shapeName == "Triangle")
		{
			string isFilled;
			int ID;
			int x, y, z, a, b, c;
			bool k;
			Point P1, P2, P3;
			GfxInfo TriangleGfxInfo;
			inputfile >> ID >> P1.x >> P1.y >> P2.x >> P2.y >>P3.x >> P3.y >> x >> y >> z >> isFilled;
			TriangleGfxInfo.DrawClr.ucBlue = x;
			TriangleGfxInfo.DrawClr.ucGreen = y;
			TriangleGfxInfo.DrawClr.ucRed = z;
			if (isFilled == "FILL")
			{
				inputfile >> a >> b >> c;
				TriangleGfxInfo.FillClr.ucBlue = a;
				TriangleGfxInfo.FillClr.ucGreen = b;
				TriangleGfxInfo.FillClr.ucRed = c;
			}
			else
			{
				TriangleGfxInfo.isFilled = 0;
			}
			inputfile >> TriangleGfxInfo.BorderWdth;
			newShape = new Triangle(P1, P2, P3, TriangleGfxInfo);
			Addshape(newShape);
		}

		if (shapeName == "Square")
		{
			string isFilled;
			int ID;
			int x, y, z, a, b, c;
			bool k;
			Point P1, P2;
			GfxInfo SquareGfxInfo;
			inputfile >> ID >> P1.x >> P1.y >> P2.x >> P2.y >> x >> y >> z >> isFilled;
			SquareGfxInfo.DrawClr.ucBlue = x;
			SquareGfxInfo.DrawClr.ucGreen = y;
			SquareGfxInfo.DrawClr.ucRed = z;
			if (isFilled == "FILL")
			{
				inputfile >> a >> b >> c;
				SquareGfxInfo.FillClr.ucBlue = a;
				SquareGfxInfo.FillClr.ucGreen = b;
				SquareGfxInfo.FillClr.ucRed = c;
			}
			else
			{
				SquareGfxInfo.isFilled = 0;
			}
			inputfile >> SquareGfxInfo.BorderWdth;
			newShape = new Square(P1, P2, SquareGfxInfo);
			Addshape(newShape);
		}

		if (shapeName == "Rect")
		{
			string isFilled;
			int ID;
			int x, y, z, a, b, c;
			bool k;
			Point P1, P2;
			GfxInfo RectGfxInfo;
			inputfile >> ID >> P1.x >> P1.y >> P2.x >> P2.y >> x >> y >> z >> isFilled;
			RectGfxInfo.DrawClr.ucBlue = x;
			RectGfxInfo.DrawClr.ucGreen = y;
			RectGfxInfo.DrawClr.ucRed = z;
			//cout << P1.x << " " << P1.y << " " << P2.x << " " << P2.y << " " << x << " " << y << " " << z << " " << isFilled << " ";
			if (isFilled == "FILL")
			{
				inputfile >> a >> b >> c;
				RectGfxInfo.FillClr.ucBlue = a;
				RectGfxInfo.FillClr.ucGreen = b;
				RectGfxInfo.FillClr.ucRed = c;
			}
			else
			{
				RectGfxInfo.isFilled = 0;
			}
			inputfile >> RectGfxInfo.BorderWdth;
			//cout << RectGfxInfo.BorderWdth;
			newShape = new Rect(P1, P2, RectGfxInfo);
			//newShape->LOAD(inputfile);
			Addshape(newShape);
		}

		if (shapeName == "IrrPolygon")
		{
			string isFilled;
			int ID;
			int x, y, z, a, b, c;
			bool k;
			vector<Point> allPoints;
			int verticies;
			GfxInfo IrrPolygonGfxInfo;
			inputfile >> ID >> verticies;
			for (unsigned i = 0; i <= verticies; ++i)
			{
				inputfile >> allPoints[i].x
					>> allPoints[i].y ;

			}
			
			inputfile >> x >> y >> z >> isFilled;
			IrrPolygonGfxInfo.DrawClr.ucBlue = x;
			IrrPolygonGfxInfo.DrawClr.ucGreen = y;
			IrrPolygonGfxInfo.DrawClr.ucRed = z;
			if (isFilled == "FILL")
			{
				inputfile >> a >> b >> c;
				IrrPolygonGfxInfo.FillClr.ucBlue = a;
				IrrPolygonGfxInfo.FillClr.ucGreen = b;
				IrrPolygonGfxInfo.FillClr.ucRed = c;
			}
			else
			{
				IrrPolygonGfxInfo.isFilled = 0;
			}
			inputfile >> IrrPolygonGfxInfo.BorderWdth;
			newShape = new IrrPolygon(allPoints, verticies, IrrPolygonGfxInfo);
			Addshape(newShape);
		}
		if (shapeName == "RegularPolygon")
		{
			string isFilled;
			int ID;
			int x, y, z, a, b, c;
			bool k;
			Point center;
			char numOfVertices;
			char radius;
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
			newShape = new RegularPolygon(center, int((int(numOfVertices) - 48)), int((int(radius) - 48)) * 15, RegularPolygonGfxInfo);
			Addshape(newShape);
		}
		if (shapeName == "Circle")
		{
			string isFilled;
			int ID;
			int x, y, z, a, b, c;
			bool k;
			Point P1, P2;
			GfxInfo CircleGfxInfo;
			inputfile >> ID >> P1.x >> P1.y >> P2.x >> P2.y >> x >> y >> z >> isFilled;
			CircleGfxInfo.DrawClr.ucBlue = x;
			CircleGfxInfo.DrawClr.ucGreen = y;
			CircleGfxInfo.DrawClr.ucRed = z;
			if (isFilled == "FILL")
			{
				inputfile >> a >> b >> c;
				CircleGfxInfo.FillClr.ucBlue = a;
				CircleGfxInfo.FillClr.ucGreen = b;
				CircleGfxInfo.FillClr.ucRed = c;
			}
			else
			{
				CircleGfxInfo.isFilled = 0;
			}
			inputfile >> CircleGfxInfo.BorderWdth;
			newShape = new Circle(P1, P2, CircleGfxInfo);
			Addshape(newShape);
		}
		if (shapeName == "Oval")
		{
			string isFilled;
			int ID;
			int x, y, z, a, b, c;
			bool k;
			Point P1, P2;
			GfxInfo OvalGfxInfo;
			inputfile >> ID >> P1.x >> P1.y >> P2.x >> P2.y >> x >> y >> z >> isFilled;
			OvalGfxInfo.DrawClr.ucBlue = x;
			OvalGfxInfo.DrawClr.ucGreen = y;
			OvalGfxInfo.DrawClr.ucRed = z;
			if (isFilled == "FILL")
			{
				inputfile >> a >> b >> c;
				OvalGfxInfo.FillClr.ucBlue = a;
				OvalGfxInfo.FillClr.ucGreen = b;
				OvalGfxInfo.FillClr.ucRed = c;
			}
			else
			{
				OvalGfxInfo.isFilled = 0;
			}
			inputfile >> OvalGfxInfo.BorderWdth;
			newShape = new Oval(P1, P2, OvalGfxInfo);
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

