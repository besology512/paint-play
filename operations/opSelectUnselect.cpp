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
	Point P1;

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();
	pUI->GetPointClicked(P1.x, P1.y);

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	//If there is a shape in the selected point
	if (pGr->Getshape(P1.x, P1.y))
	{
		//unselect everything 
		pGr->UnselectAll();
		pGr->Getshape(P1.x, P1.y)->SetSelected(true); //make this shape is selected
	}
	else
	{
		pGr->UnselectAll();
	}


}