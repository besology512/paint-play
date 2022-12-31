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
		for (int i = 1; i < 3; i++) {
			Factor = i * factor;
			pGr->getSelectedShape()->resize(Factor);
			
		}
		
			
		
	}
	else {
		pUI->PrintMessage("Select the shape you want to zoom in first!");
	}
}

void opZoomin::Undo() {}
void opZoomin::Redo() {}