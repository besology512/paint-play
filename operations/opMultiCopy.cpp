#include "opMultiCopy.h"

opMultiCopy::opMultiCopy(controller* pCont) : operation(pCont)
{
}

opMultiCopy::~opMultiCopy()
{
}

void opMultiCopy::Execute()
{
	// Get User input
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	pGr->scramble();
	pUI->PrintMessage("MultiCopy Succussfully");

}

void opMultiCopy::Undo()
{
}

void opMultiCopy::Redo()
{
}
