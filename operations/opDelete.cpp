#include "opDelete.h"

#include "..\controller.h"
#include "../Shapes/Shape.h"

#include "..\GUI\GUI.h"

opDelete::opDelete(controller* pCont) :operation(pCont)
{}
opDelete::~opDelete()
{}

//Execute the operation
void opDelete::Execute() {

	//Point P;

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	//pUI->PrintMessage("Select the shape to be deleted");
	

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();
	
	if (pGr->getselectedshape()) {
		pGr->DeleteShape(pGr->getselectedshape());
		pGr->UnselectAll();
		pUI->PrintMessage("The Shape has been deleted sucessfully"); //Update the status bar with the shape info
	}
	else {
		pUI->PrintMessage("Please select a shape to delete it");
	}
	
	////If there is a shape in the selected point
	//if (pGr->Getshape(P.x, P.y))
	//{
	//	pGr->UnselectAll(); 							//unselect everything 
	//	shape* pShp= pGr->Getshape(P.x, P.y);		//make this shape is selected
	//	pGr->DeleteShape(pShp);
	//	//pUI->PrintMessage(pGr->Getshape(P.x, P.y)->shapeInfo()); //Update the status bar with the shape info	
	//}
	//else
	//{
	//	pGr->UnselectAll();
	//	pUI->ClearStatusBar();
	//}
}