#include"opResize.h"

#include"../controller.h"

#include"../GUI/GUI.h"

opResize::opResize(controller* pCont) :operation(pCont) {}

opResize::~opResize() {}

void opResize::Execute() {
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	float factor;
	std::string input;
	if (pGr->getSelectedShape()) {
		pUI->PrintMessage("Enter the scale factor [0.25,0.5,2,4]");
		input = pUI->GetSrting();
		while (!(input == "2"|| input == "4"|| input == "0.5"|| input == "0.25"))
		{
			string msg = "Error! Make sure that you enter the values specified";
			pUI->PrintMessage(msg);
			input = pUI->GetSrting();
		}
		if (input == "0.25")
			factor = 0.25;
		if (input == "0.5")
			factor = 0.5;
		if (input == "2")
			factor = 2;
		if (input == "4")
			factor = 4;
		Factor = factor;
		pGr->getSelectedShape()->resize(factor);
		//Set the save status is false
		pGr->isSaved = false;
	}
	else {
		pUI->PrintMessage("Select the shape you want to resize first!");
	}
}

void opResize::Undo() {
	Graph* pGr = pControl->getGraph();
	pGr->getLastShape()->resize(1 / Factor);
}
void opResize::Redo() {
	Graph* pGr = pControl->getGraph();
	pGr->getLastShape()->resize(Factor);
}