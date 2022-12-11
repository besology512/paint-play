#include "Graph.h"

#include "..//opAddLine.h"  //WHY INCLUDING OP LINE HERE??
#include <iostream>
#include"../CMUgraphicsLib/colors.h"
#include"../Shapes/Rect.h"
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
	int size;
	string shapeName;
	shape* newShape;
	inputfile >> size;
	//for (int i = 0; i < size; i++)
	while(inputfile)
	{
		inputfile >> shapeName;
		if (shapeName == "Rect")
		{
			string isFilled;
			Point P1, P2;
			GfxInfo RectGfxInfo;
			inputfile >> P1.x >> P1.y >> P2.x >> P2.y
				>> RectGfxInfo.DrawClr.ucBlue >> RectGfxInfo.DrawClr.ucGreen >> RectGfxInfo.DrawClr.ucRed >> isFilled;
			cout << (int)RectGfxInfo.DrawClr.ucBlue;
			//RectGfxInfo.DrawClr = color((int)RectGfxInfo.DrawClr.ucBlue, (int)RectGfxInfo.DrawClr.ucGreen,(int)RectGfxInfo.DrawClr.ucRed);
			if (isFilled == "FILL")
			{
				inputfile >> RectGfxInfo.FillClr.ucBlue >> RectGfxInfo.FillClr.ucGreen >> RectGfxInfo.FillClr.ucRed;
			}
			else
			{
				inputfile >> isFilled;
			}
			inputfile >> RectGfxInfo.BorderWdth;
			newShape = new Rect(P1, P2, RectGfxInfo);
			//newShape->LOAD(inputfile);
			Addshape(newShape);
		}
	}
	











	//string array[4];
	//
	//getline(inputfile, array[0]);
	////getline(inputfile, array[1], ' ');
	////getline(inputfile, array[2], ' ');
	//getline(inputfile, array[1]);
	//string * arr2 = new string[stoi(array[1])*10];
	//for (int i = 0;i < stoi(array[1])*10;i++)
	//{
	//	getline(inputfile, arr2[i], ' ');
	//}
	//for (int i = 0;i < stoi(array[1]) * 10;i++)
	//{
	//	if (arr2[i] == "RECT") {
	//		Point p1, p2;
	//		GfxInfo info;

	//		p1.x = stoi(arr2[i + 2]);
	//		p1.y = stoi(arr2[i + 3]);
	//		p2.x = stoi(arr2[i + 4]);
	//		p2.y = stoi(arr2[i + 5]);
	//		color c = (0,0,0);
	//		info.DrawClr = c; // to initialize the draw color
	//		if (arr2[i + 7] == "NO_FILL") {
	//			info.FillClr = changestringtoints("white"); // to make the fillcolor white
	//		}
	//		else
	//			info.FillClr = changestringtoints(arr2[i + 7]); //to initialize the fill color
	//		info.BorderWdth = stoi(arr2[i + 8]);
	//		Rect* R = new Rect(p1, p2, info);
	//		R->setid(stoi(arr2[i + 1])); // setting the id of the rectagle
	//		Addshape(R);

	//	}
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

