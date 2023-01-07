#include "opScramble.h"

opScramble::opScramble(controller* pCont) : operation(pCont)
{
}

opScramble::~opScramble()
{
}

void opScramble::Execute()
{
	// Get User input
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	pGr->fillArray();
	pGr->scramble();
	pUI->PrintMessage("Scramble Succussfully");

}

void opScramble::Undo()
{
}

void opScramble::Redo()
{
}
