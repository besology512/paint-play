#include "opSave.h"
#include "Shapes/Graph.h"
#include "operations/operation.h"
#include "GUI/GUI.h"
#include "controller.h"


opSave::opSave(controller* pCont) : operation(pCont)
{
}

opSave::~opSave()
{
}

void opSave::Execute()
{
	// Get User input
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("Enter File Name");

	string fileName = pUI->GetSrting();

	outfile.open(fileName + ".txt"); // open file and store it in folder in working directory 



	Graph* pGr = pControl->getGraph();

	pGr->Save(outfile);


	outfile.close();

	pUI->PrintMessage("Saved Succussfully");




}

