#include "opAddCircle.h"
#include "../Shapes/Circle.h"

#include "..\controller.h"

#include "..\GUI\GUI.h"

opAddCircle::opAddCircle(controller* pCont) :operation(pCont)
{}
opAddCircle::~opAddCircle()
{}

//Execute the operation
void opAddCircle::Execute()
{
	Point P1, P2;

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	pUI->PrintMessage("New Circle: Click at center");
	//Read center and store in point P1
	pUI->GetPointClicked(P1.x, P1.y);

	string msg = "Center is at (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
	msg += " ... Click at any point to match the radius";
	pUI->PrintMessage(msg);
	//Read 2nd point (the point on the arc to get the radius) and store in point P2
	pUI->GetPointClicked(P2.x, P2.y);
	msg += "Second point is at (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
	pUI->PrintMessage(msg);

	pUI->ClearStatusBar();

	//Preapre all Circle parameters
	GfxInfo CirclGfxInfo;

	//get drawing, filling colors and pen width from the interface
	CirclGfxInfo.DrawClr = pUI->getCrntDrawColor();
	CirclGfxInfo.FillClr = pUI->getCrntFillColor();
	CirclGfxInfo.BorderWdth = pUI->getCrntPenWidth();


	CirclGfxInfo.isFilled = pGr->isFilled;	//default is not filled
	CirclGfxInfo.isSelected = false;	//defualt is not selected

	//Set the save status is false
	pGr->isSaved = false;

	//Create a Circle with the above parameters
	Circle* R = new Circle(P1, P2, CirclGfxInfo);


	//Add the rectangle to the list of shapes
	pGr->Addshape(R);

}