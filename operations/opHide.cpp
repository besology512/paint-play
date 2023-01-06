#include"opHide.h"

#include"../controller.h"

#include"../GUI/GUI.h"

opHide::opHide(controller* pCont) :operation(pCont) {}

opHide::~opHide() {}

void opHide::Execute() {

	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	
	pGr->Hideing(pUI);
}

void opHide::Undo() {}
void opHide::Redo() {}