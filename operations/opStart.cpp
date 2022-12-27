#include"opStart.h"

#include "..\controller.h"

#include "..\GUI\GUI.h"

opStart::opStart(controller* pCont) :operation(pCont)
{}
opStart::~opStart()
{}

//Execute the operation
void opStart::Execute() {

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("You clicked on start button");
}
void opStart::Undo() {}
void opStart::Redo() {}