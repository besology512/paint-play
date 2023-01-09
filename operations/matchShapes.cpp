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
	if (pGr->isplay)
	{
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
				firstSelectedShape->setisHidden(false);
				//put the unhide functin here for the first selectedShape
				pGr->addMatchedShape(firstSelectedShape);

			}

			pGr->UnselectAll();

		}


		if (pGr->getMatchedShapes().size() == 1)
		{

			if (pGr->getSelectedShape() && (pGr->getSelectedShape() != pGr->getMatchedShapes()[0]))
			{
				shape* secondSelectedShape = pGr->getSelectedShape();
				//put the unhide functin here for the second selectedShape
				secondSelectedShape->setisHidden(false);

				pGr->addMatchedShape(secondSelectedShape);
				pGr->UnselectAll();

				pGr->ready = true;
				return;
			}

			pGr->UnselectAll();

			//pUI->PrintMessage("The End :). Your Score : " + to_string(score) + "");
		}



		if (pGr->getMatchedShapes().size() == 2 && pGr->ready == true)
		{
			pGr->UnselectAll();


			if (pGr->getMatchedShapes()[0]->getDuplicateID() == pGr->getMatchedShapes()[1]->getDuplicateID())
			{
				pGr->UnselectAll();
				Sleep(1000);
				pGr->DeleteShape(pGr->getMatchedShapes()[0]); pGr->DeleteShape(pGr->getMatchedShapes()[1]);
				pGr->clearMatchedShapes();
				pGr->score += 3;
				pUI->PrintMessage("Congratulation You Got 3 Point. Your Score : " + to_string(pGr->score) + "");
				pGr->ready = true;

			}
			else
			{
				pGr->UnselectAll();
				// Hide the two shapes again
				Sleep(1000);
				pGr->getMatchedShapes()[0]->setisHidden(true);
				pGr->getMatchedShapes()[1]->setisHidden(true);
				pGr->clearMatchedShapes();
				pGr->score += 1;
				pUI->PrintMessage("Try Agin You Got 1 Point. Your Score : " + to_string(pGr->score) + "");
				pGr->ready = true;


			}

		}
	

	}
}
void matchShapes::Undo() 
{

}
void matchShapes::Redo() {

}