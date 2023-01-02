#include"opZoomout.h"

#include"../controller.h"

#include"../GUI/GUI.h"

opZoomout::opZoomout(controller* pCont) :operation(pCont) {}

opZoomout::~opZoomout() {}

void opZoomout::Execute() {

	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	int x, y;
	pUI->ClearStatusBar();
	pUI->CreateDrawToolBar();
	pUI->GetPointClicked(x, y);
	pUI->ClearStatusBar();
	pGr->ZOOMING(0.5, x, y);



}

void opZoomout::Undo() {}
void opZoomout::Redo() {}