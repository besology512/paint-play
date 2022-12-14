#include "opAddOval.h"
#include "..\shapes\Oval.h"

#include "..\controller.h"

#include "..\GUI\GUI.h"

opAddOval::opAddOval(controller* pCont):operation(pCont)
{}
opAddOval::~opAddOval()
{}

//Execute the operation
void opAddOval::Execute()
{
	Point P1, P2;

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	pUI->PrintMessage("New Oval: Click at first corner");
	//Read 1st corner and store in point P1
	pUI->GetPointClicked(P1.x, P1.y);

	string msg = "First corner is at (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
	msg += " ... Click at second corner";
	pUI->PrintMessage(msg);
	//Read 2nd corner and store in point P2
	pUI->GetPointClicked(P2.x, P2.y);
	pUI->ClearStatusBar();

	//Preapre all oval parameters
	GfxInfo OvalGfxInfo;

	//get drawing, filling colors and pen width from the interface
	OvalGfxInfo.DrawClr = pUI->getCrntDrawColor();
	OvalGfxInfo.FillClr = pUI->getCrntFillColor();
	OvalGfxInfo.BorderWdth = pUI->getCrntPenWidth();


	OvalGfxInfo.isFilled = pGr->isFilled;	//default is not filled
	OvalGfxInfo.isSelected = false;	//defualt is not selected

	//Set the save status is false
	pGr->isSaved = false;

	//Create a oval with the above parameters
	Oval* O = new Oval(P1, P2, OvalGfxInfo);


	//Add the Oval to the list of shapes
	pGr->Addshape(O);

}
void opAddOval::Undo() {
	Graph* pGr = pControl->getGraph();
	pGr->PutInUndoShapes();
}
void opAddOval::Redo() {
	Graph* pGr = pControl->getGraph();
	pGr->FromUndotoShapesList();
}