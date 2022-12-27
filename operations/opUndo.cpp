

#include"opUndo.h"

#include"../controller.h"

#include"../GUI/GUI.h"

opUndo::opUndo(controller* pCont) :operation(pCont) {}

opUndo::~opUndo() {}

void opUndo::Execute() {
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	if (pControl->getLastOperation())
	{
		pControl->getLastOperation()->Undo();
		pControl->UndoOperation();
		//Set the save status is false
		pGr->isSaved = false;
	}
	else {
		pUI->PrintMessage("There is nothing to be undone");
	}
}

void opUndo::Undo() {}
void opUndo::Redo() {}