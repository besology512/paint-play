#include "opSave.h"
#include "Shapes/Graph.h"
#include "operations/operation.h"
#include "GUI/GUI.h"
#include "controller.h"


opSave::opSave(controller* pCont): operation(pCont)
{
}

opSave::~opSave()
{
}

void opSave::Execute()
{
	
	GUI* pUI = pControl->GetUI();
	pUI->PrintMessage("Enter File Name : ");

	// get File Name
	string fileName = pUI->GetSrting();

	pUI->PrintMessage("Saved Successfully");
	Graph* pGr = pControl->getGraph();

	pGr->Save(outfile);


}

