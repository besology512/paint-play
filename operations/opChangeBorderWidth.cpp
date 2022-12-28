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
		pGr->getSelectedShape()->ChngBorderWidth(int(w) - 48);

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

void opChangeBorderWidth::Undo() {}
void opChangeBorderWidth::Redo() {}