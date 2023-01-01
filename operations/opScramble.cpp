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

	pUI->PrintMessage("Enter File Name");

}

void opScramble::Undo()
{
}

void opScramble::Redo()
{
}
