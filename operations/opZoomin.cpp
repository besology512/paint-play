#include"opZoomin.h"

#include"../controller.h"

#include"../GUI/GUI.h"

opZoomin::opZoomin(controller* pCont) :operation(pCont) {}

opZoomin::~opZoomin() {}

void opZoomin::Execute() {

	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	float factor = 2;
	if (pGr->getSelectedShape()) {
		
			pGr->getSelectedShape()->resize(2);
			
		
		
			
		
	}
	else {
		pUI->PrintMessage("Select the shape you want to zoom in first!");
	}
}

void opZoomin::Undo() {}
void opZoomin::Redo() {}