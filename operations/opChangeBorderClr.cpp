#include"opChangeBorderClr.h"

#include"../Shapes/Shape.h"

#include"../controller.h"

#include"../GUI/GUI.h"

opChangeBorderClr::opChangeBorderClr(controller* pCont) :operation(pCont) {}

opChangeBorderClr::~opChangeBorderClr() {}

void opChangeBorderClr::Execute() {
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();

	if (pGr->getSelectedShape()) {
		//change the border color of the selected shape
		pGr->getSelectedShape()->ChngDrawClr(pGr->getPickedClr());

		//Set the save status is false
		pGr->isSaved = false;
	}
	else {
		//change the general border color of the next drawings or shapes
		pUI->setDrawColor(pGr->getPickedClr());
	}
}

void opChangeBorderClr::Undo() {}
void opChangeBorderClr::Redo() {}