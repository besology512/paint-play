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
		pGr->lastEdited.push(pGr->getselectedshape());
		pGr->getSelectedShape()->ChngDrawClr(pGr->getPickedClr());
		pGr->getselectedshape()->prevBorderClrs.push(pGr->getPickedClr());

		//Set the save status is false
		pGr->isSaved = false;
	}
	else {
		//change the general border color of the next drawings or shapes
		pUI->setDrawColor(pGr->getPickedClr());
	}
}

void opChangeBorderClr::Undo() {
	Graph* pGr = pControl->getGraph();
	shape* pShape = pGr->lastEdited.top();
	if ((pShape->prevBorderClrs.size() != 1) && pShape)
	{
		pShape->undoBorderClrs.push(pShape->prevBorderWidth.top());
		pShape->prevBorderClrs.pop(); //deletes the last width from the stack
		pShape->ChngDrawClr(pShape->prevBorderClrs.top()); //changes the border width to the top of the stack
		pGr->undolastEdited.push(pShape);
		pGr->lastEdited.pop();
	}
}
void opChangeBorderClr::Redo() {
	Graph* pGr = pControl->getGraph();
	shape* pShape = pGr->undolastEdited.top();
	if ((pShape->undoBorderClrs.size() != 1) && pShape)
	{
		pShape->prevBorderClrs.push(pShape->undoBorderClrs.top()); //puts the redo to the undo
		//deletes the last width from the stack
		pShape->ChngDrawClr(pShape->undoBorderClrs.top());
		pShape->undoBorderClrs.pop();
		pGr->lastEdited.push(pShape);
		pGr->undolastEdited.pop();
	}
}