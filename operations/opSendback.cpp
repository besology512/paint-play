#include "opSendback.h"

#include "..\controller.h"

#include "..\GUI\GUI.h"

opSendback::opSendback(controller* pCont) :operation(pCont)
{}
opSendback::~opSendback()
{}

//Execute the operation
void opSendback::Execute() {

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	//pUI->PrintMessage("Select the shape to be deleted");


	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();


	if (pGr->getselectedshape()) {
		pGr->DeleteShape(pGr->getselectedshape());
		pGr->SendbackShape(pGr->getselectedshape());
		pGr->UnselectAll();
		
		//Set the save status is false
		pGr->isSaved = false;
	}
	else {
		pUI->PrintMessage("Please select a shape to send it back");
	}
}

void opSendback::Undo() {
}
void opSendback::Redo() {
}