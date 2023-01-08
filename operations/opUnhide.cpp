#include"opUnhide.h"

#include"../controller.h"

#include"../GUI/GUI.h"

opUnhide::opUnhide(controller* pCont) :operation(pCont) {}

opUnhide::~opUnhide() {}

void opUnhide::Execute() {

	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();

	pGr->Unhideing(pUI);
}

void opUnhide::Undo() {}
void opUnhide::Redo() {}