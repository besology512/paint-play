#include "opSelectUnselect.h"

#include "..\controller.h"
#include "..\GUI\GUI.h"


opSelectUnselect::opSelectUnselect(controller* pCont) :operation(pCont)
{}
opSelectUnselect::~opSelectUnselect()
{}

//Execute the operation
void opSelectUnselect::Execute()
{
	Point P;

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	pUI->GetMousCoord(P.x, P.y);

	//If there is a shape in the selected point
	if (pGr->Getshape(P.x, P.y))
	{
		pGr->UnselectAll(); 							//unselect everything 
		pGr->Getshape(P.x, P.y)->SetSelected(true);		//make this shape is selected
		
		// To Do (Update the status bar with info about the selected shape)
	}
	else
	{
		pGr->UnselectAll();
		//Clear the status bar
	}
}