#include"operations/opExit.h"

#include "..\controller.h"
#include "../Shapes/Shape.h"

#include "..\GUI\GUI.h"

#include "Shapes/Graph.h"
#include "operations/operation.h"


opExit::opExit(controller* pCont) :operation(pCont)
{}
opExit::~opExit()
{}

//Execute the operation
void opExit::Execute() {
	
	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	if (isSaved == false) {

		pUI->PrintMessage("There is changes unsaved ...Do you want to save is?(Yes/No)");

		string choice = pUI->GetSrting();

		if (choice == "Yes" || choice == "yes") {

			pGr->Save(outfile);
			exit(0);
		}


	}
	else
		exit(0);
}
