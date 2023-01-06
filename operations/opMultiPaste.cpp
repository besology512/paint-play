#include "opMultiPaste.h"

opMultiPaste::opMultiPaste(controller* pCont) : operation(pCont)
{
}

opMultiPaste::~opMultiPaste()
{
}

void opMultiPaste::Execute()
{
	// Get User input
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	pGr->scramble();
	pUI->PrintMessage("MultiPaste Succussfully");

}

void opMultiPaste::Undo()
{
}

void opMultiPaste::Redo()
{
}
