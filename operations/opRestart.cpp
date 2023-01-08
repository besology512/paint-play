#include"opRestart.h"

#include "..\controller.h"

#include "..\GUI\GUI.h"

opRestart::opRestart(controller* pCont) :operation(pCont)
{}
opRestart::~opRestart()
{}

//Execute the operation
void opRestart::Execute() {

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("You clicked on restart button");

	Graph* pGr = pControl->getGraph();
	pGr->reDraw(pUI);

	pUI->PrintMessage("You clicked on restart button");
}

void opRestart::Undo() {}
void opRestart::Redo() {}