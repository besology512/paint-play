#include "matchShapes.h"
#include <iostream>

#include "..\controller.h"

#include "..\GUI\GUI.h"

matchShapes::matchShapes(controller* pCont) :operation(pCont)
{}
matchShapes::~matchShapes()
{}

//Execute the operation
void matchShapes::Execute()
{
// This function should be called everytime the user click on a shape in the play mode, or it could be integrated with the start game function

//Get a Pointer to the Input / Output Interfaces
GUI* pUI = pControl->GetUI();

//Get a pointer to the graph
Graph* pGr = pControl->getGraph();

// First for selecting:
Point P;
pUI->GetMousCoord(P.x, P.y);

if (pGr->Getshape(P.x, P.y))
{
	pGr->UnselectAll(); 							//unselect everything
	pGr->Getshape(P.x, P.y)->SetSelected(true);		//make this shape is selected
	pUI->PrintMessage(pGr->Getshape(P.x, P.y)->shapeInfo()); //Update the status bar with the shape info
	pGr->addSelectedShape(pGr->Getshape(P.x, P.y));

}
else
{
	pGr->UnselectAll();
	pUI->ClearStatusBar();
}

// For matching:

if (pGr->getMatchedShapes().size() == 0)
{
	if (pGr->getSelectedShape())
	{
		shape* firstSelectedShape = pGr->getSelectedShape();
		//put the unhide functin here for the first selectedShape
		pGr->addMatchedShape(firstSelectedShape);

	}

	pGr->UnselectAll();


}
else if (pGr->getMatchedShapes().size() == 1)
{
	if (pGr->getSelectedShape() && (pGr->getSelectedShape()!= pGr->getMatchedShapes()[0]))
	{
		shape* secondSelectedShape = pGr->getSelectedShape();
		//put the unhide functin here for the second selectedShape
		pGr->addMatchedShape(secondSelectedShape);
		pGr->UnselectAll();

		if (pGr->getMatchedShapes()[0]->getDuplicateID() == pGr->getMatchedShapes()[1]->getDuplicateID())
		{
			pGr->DeleteShape(pGr->getMatchedShapes()[0]); pGr->DeleteShape(pGr->getMatchedShapes()[1]);
			pGr->clearMatchedShapes();
		}
		else
		{
			// Hide the two shapes again
			pGr->clearMatchedShapes();
		}
	}
pGr->UnselectAll();


}

}

void matchShapes::Undo() {

}
void matchShapes::Redo() {

}