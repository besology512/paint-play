#include"opZoomin.h"

#include"../controller.h"

#include"../GUI/GUI.h"

opZoomin::opZoomin(controller* pCont) :operation(pCont) {}

opZoomin::~opZoomin() {}

void opZoomin::Execute() {

	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	int x, y;
	pUI->ClearStatusBar();
	pUI->CreateDrawToolBar();
	pUI->GetPointClicked(x,y);
	pUI->ClearStatusBar();
	pGr->ZOOMING(1.5, x, y);


	
}

void opZoomin::Undo() {}
void opZoomin::Redo() {}