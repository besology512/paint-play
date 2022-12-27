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
		pUI->PrintMessage("The Shape has been deleted sucessfully"); 
		//Set the save status is false
		pGr->isSaved = false;
	}
	else {
		pUI->PrintMessage("Please select a shape to delete it");
	}
}

void opDelete::Undo() {
	Graph* pGr = pControl->getGraph();
	pGr->FromUndotoShapesList();
}
void opDelete::Redo() {
	Graph* pGr = pControl->getGraph();
	pGr->PutInUndoShapes();
}