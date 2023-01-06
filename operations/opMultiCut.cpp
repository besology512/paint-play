#include "opMultiCut.h"

opMultiCut::opMultiCut(controller* pCont) : operation(pCont)
{
}

opMultiCut::~opMultiCut()
{
}

void opMultiCut::Execute()
{
	// Get User input
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	pGr->scramble();
	pUI->PrintMessage("MultiCut Succussfully");

}

void opMultiCut::Undo()
{
}

void opMultiCut::Redo()
{
}
