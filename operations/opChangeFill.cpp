#include"opChangeFill.h"

#include"../Shapes/Shape.h"

#include"../controller.h"

#include"../GUI/GUI.h"

opChangeFill::opChangeFill(controller* pCont) :operation(pCont){}

opChangeFill::~opChangeFill(){}

void opChangeFill::Execute() {
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();

	if (pGr->getSelectedShape()) {
		//change the fill color of the selected shape
		pGr->lastEdited.push(pGr->getselectedshape());
		pGr->getSelectedShape()->ChngFillClr(pGr->getPickedClr());
		pGr->getselectedshape()->prevFillClrs.push(pGr->getPickedClr());
		//Set the save status is false
		pGr->isSaved = false;
	}
	else {
		//change the general fill color of the next drawings or shapes
		
		pGr->setFilled(true);
		pUI->setFillcolor(pGr->getPickedClr());
	}
}

void opChangeFill::Undo() {
	Graph* pGr = pControl->getGraph();
	shape* pShape = pGr->lastEdited.top();
	if ((pShape->prevFillClrs.size() != 1) && pShape)
	{
		pShape->undoFillCLrs.push(pShape->prevFillClrs.top());
		pShape->prevFillClrs.pop(); //deletes the last width from the stack
		if (pShape->prevFillClrs.size()==1)
		{
			pShape->setIsfilled(false);
		}
		else {
			pShape->ChngFillClr(pShape->prevFillClrs.top()); //changes the border width to the top of the stack
		}
		pGr->undolastEdited.push(pShape);
		pGr->lastEdited.pop();
	}
}
void opChangeFill::Redo() {
	Graph* pGr = pControl->getGraph();
	shape* pShape = pGr->undolastEdited.top();
	if ((pShape->undoFillCLrs.size() != 1) && pShape)
	{
		pShape->prevFillClrs.push(pShape->undoFillCLrs.top()); //puts the redo to the undo
		//deletes the last width from the stack
		if (pShape->undoFillCLrs.size()==1)
		{
			pShape->setIsfilled(false);
		}else{ pShape->ChngFillClr(pShape->undoFillCLrs.top());}
		pShape->undoFillCLrs.pop();
		pGr->lastEdited.push(pShape);
		pGr->undolastEdited.pop();
	}
}