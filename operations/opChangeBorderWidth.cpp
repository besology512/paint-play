#include"opChangeBorderWidth.h"

#include"../Shapes/Shape.h"

#include"../controller.h"

#include"../GUI/GUI.h"

opChangeBorderWidth::opChangeBorderWidth(controller* pCont) :operation(pCont) {}

opChangeBorderWidth::~opChangeBorderWidth() {}

void opChangeBorderWidth::Execute() {
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();

	if (pGr->getSelectedShape()) {
		pUI->PrintMessage("Enter the new width from 1 to 9.");
		char w;
		pUI->GetKeyClicked(w);

		while ((int(w) - 48 < 1) || (int(w) - 48 > 9))
		{
			string msg = "Error! Make sure that the new width is between 1 and 9";
			pUI->PrintMessage(msg);
			pUI->GetKeyClicked(w);
		}
		
		pUI->ClearStatusBar();
		pGr->lastEdited.push(pGr->getselectedshape());
		pGr->getSelectedShape()->ChngBorderWidth(int(w) - 48);
		pGr->getSelectedShape()->prevBorderWidth.push(int(w) - 48); // puts this new fill in the prev border to use it in undo when needed.
		//Set the save status is false
		pGr->isSaved = false;
	}
	else {
		//change the general border width of the next drawings or shapes

		pUI->PrintMessage("Enter the new general width from 1 to 9.");
		char w;
		pUI->GetKeyClicked(w);

		while ((int(w) - 48 < 1) || (int(w) - 48 > 9))
		{
			string msg = "Error! Make sure that the new width is between 1 and 9";
			pUI->PrintMessage(msg);
			pUI->GetKeyClicked(w);
		}

		pUI->ClearStatusBar();
		pUI->setBorderWidth(int(w) - 48);
	}
}
#include<iostream>
using namespace std;
void opChangeBorderWidth::Undo() {
	Graph* pGr = pControl->getGraph();
	shape* pShape = pGr->lastEdited.top();
	if ((pShape->prevBorderWidth.size() != 1)&& pShape)
	{
		pShape->undoBorderWidth.push(pShape->prevBorderWidth.top());
		pShape->prevBorderWidth.pop(); //deletes the last width from the stack
		pShape->ChngBorderWidth(pShape->prevBorderWidth.top()); //changes the border width to the top of the stack
		cout << "changed the width of the shape to" << pShape->prevBorderWidth.top();
		pGr->undolastEdited.push(pShape);
		pGr->lastEdited.pop();
	}
	cout << "the size of the stack is " << pGr->getLastShape()->prevBorderWidth.size() <<endl;
	cout << "In undo";
}
void opChangeBorderWidth::Redo() {
	Graph* pGr = pControl->getGraph();
	shape* pShape = pGr->undolastEdited.top();
	if ((pShape->undoBorderWidth.size() != 1) && pShape)
	{
		pShape->prevBorderWidth.push(pShape->undoBorderWidth.top()); //puts the redo to the undo
		pShape->undoBorderWidth.pop(); //deletes the last width from the stack
		pShape->ChngBorderWidth(pShape->undoBorderWidth.top()); //changes the border width to the top of the stack
		cout << "In redo changed the width of the shape to" << pShape->undoBorderWidth.top();
		pGr->lastEdited.push(pShape);
		pGr->undolastEdited.pop();
	}
	cout << "In undo";
}