#include "opAddTriangle.h"
#include "../Shapes/Triangle.h"

#include "..\controller.h"

#include "..\GUI\GUI.h"

opAddTriangle::opAddTriangle(controller* pCont) :operation(pCont)
{}
opAddTriangle::~opAddTriangle()
{}

//Execute the operation
void opAddTriangle::Execute()
{
	Point P1, P2,P3;

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	pUI->PrintMessage("New Triangle: Click at first corner");
	//Read 1st corner and store in point P1
	pUI->GetPointClicked(P1.x, P1.y);

	string msg = "First corner is at (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
	msg += " ... Click at second corner";
	pUI->PrintMessage(msg);
	//Read 2nd corner and store in point P2
	pUI->GetPointClicked(P2.x, P2.y);

	msg += " ... Click at third corner";
	pUI->PrintMessage(msg);
	//Read 3rd corner and store in point P3
	pUI->GetPointClicked(P3.x, P3.y);

	pUI->ClearStatusBar();

	//Preapre all rectangle parameters
	GfxInfo TriangleGfxInfo;

	//get drawing, filling colors and pen width from the interface
	TriangleGfxInfo.DrawClr = pUI->getCrntDrawColor();
	TriangleGfxInfo.FillClr = pUI->getCrntFillColor();
	TriangleGfxInfo.BorderWdth = pUI->getCrntPenWidth();


	TriangleGfxInfo.isFilled = pGr->isFilled;	//default is not filled
	TriangleGfxInfo.isSelected = false;	//defualt is not selected

	//Set the save status is false
	pGr->isSaved = false;

	//Create a rectangle with the above parameters
	Triangle* R = new Triangle(P1, P2,P3, TriangleGfxInfo);


	//Add the rectangle to the list of shapes
	pGr->Addshape(R);

}
