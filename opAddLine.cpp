#include "opAddLine.h"

#include "Line.h"

#include "controller.h"

#include "GUI/GUI.h"

opAddLine::opAddLine(controller* pCont) :operation(pCont)
{}
opAddLine::~opAddLine()
{}

//Execute the operation
void opAddLine::Execute()
{
	Point P1, P2;

	// Get User input
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("New Line: Click at First Point");
	//Read First Point and store in point P1
	pUI->GetPointClicked(P1.x, P1.y);

	string msg = "First Point is at (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
	msg += " ... Click At Any Point To Match The Line";
	pUI->PrintMessage(msg);
	//Read 2nd point and store in point P2
	pUI->GetPointClicked(P2.x, P2.y);
	msg += "Second Point is at (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
	pUI->PrintMessage(msg);

	pUI->ClearStatusBar();

	//Preapre all Line parameters
	GfxInfo LineGfxInfo;

	//get drawing, filling colors and pen width from the interface
	LineGfxInfo.DrawClr = pUI->getCrntDrawColor();
	LineGfxInfo.FillClr = pUI->getCrntFillColor();
	LineGfxInfo.BorderWdth = pUI->getCrntPenWidth();


	LineGfxInfo.isFilled = false;	//default is not filled
	LineGfxInfo.isSelected = false;	//defualt is not selected


	//Create a Line with the above parameters
	Line* L = new Line(P1, P2, LineGfxInfo);

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	//Add the Line to the list of shapes
	pGr->Addshape(L);

}
