#include"opRedo.h"

#include"../controller.h"

#include"../GUI/GUI.h"

opRedo::opRedo(controller* pCont) :operation(pCont) {}

opRedo::~opRedo() {}

void opRedo::Execute() {
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	if (pControl->getUndoneOperation())
	{
		pControl->getUndoneOperation()->Redo();
		pControl->RedoOperation();
		//Set the save status is false
		pGr->isSaved = false;
	}
	else {
		pUI->PrintMessage("There is nothing to be undone");
	}
}

void opRedo::Undo() {}
void opRedo::Redo() {}