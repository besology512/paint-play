#include"opRotate.h"

#include"../controller.h"

#include"../GUI/GUI.h"

opRotate::opRotate(controller* pCont) :operation(pCont) {}

opRotate::~opRotate() {}

void opRotate::Execute() {
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	if (pGr->getSelectedShape())
	{
		pGr->getSelectedShape()->Rotate();
		//Set the save status is false
		pGr->isSaved = false;
	}else{
		pUI->PrintMessage("Select the shape you want to rotate first");
	}
}