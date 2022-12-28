#include "opStickImage.h"

opStickImage::opStickImage(controller* pCont) :operation(pCont)
{
}

opStickImage::~opStickImage()
{
}

//Execute the operation
void opStickImage::Execute()
{
	// Get User input
	GUI* pUI = pControl->GetUI();

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	pUI->PrintMessage("New Image : Select shape");
	//Read First Point and store in point P1


	if (pGr->getSelectedShape())
	{
		double width = pGr->getSelectedShape()->getWidth();
		double height = pGr->getSelectedShape()->getHeight();
		Point P1 = pGr->getSelectedShape()->getUpperLeftPoint();
		pUI->ClearStatusBar();

		//Preapre all Line parameters
		GfxInfo ImageGfxInfo;

		//get drawing, filling colors and pen width from the interface
		ImageGfxInfo.DrawClr = pUI->getCrntDrawColor();
		ImageGfxInfo.FillClr = pUI->getCrntFillColor();
		ImageGfxInfo.BorderWdth = pUI->getCrntPenWidth();


		ImageGfxInfo.isFilled = false;	//default is not filled
		ImageGfxInfo.isSelected = false;	//defualt is not selected


		//Create a Line with the above parameters
		StickImage* I = new StickImage(P1, width, height, ImageGfxInfo);


		//Add the Line to the list of shapes
		pGr->Addshape(I);
	}
	else
	{
		pUI->PrintMessage("You Should Select Shape");
	}
}

void opStickImage::Undo() {}
void opStickImage::Redo() {}