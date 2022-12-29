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
		pGr->getSelectedShape()->isSticked = true;
		//pGr->Draw(pUI);
		
	}
	else
	{
		pUI->PrintMessage("You Should Select Shape");
	}
}

void opStickImage::Undo() {}
void opStickImage::Redo() {}