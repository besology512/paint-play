#include "OpSwitch.h"

#include "..\controller.h"

#include "..\GUI\GUI.h"

opSwitch::opSwitch(controller* pCont) :operation(pCont)
{}
opSwitch::~opSwitch()
{}

//Execute the operation
void opSwitch::Execute() {

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();
	
	pUI->ClearToolBar();

	//pUI->ClearDrawArea();

	pUI->ClearStatusBar();
	
	pUI->CreatePlayToolBar();
}

void opSwitch::Undo() {}