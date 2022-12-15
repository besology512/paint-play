#include "opExit.h"

#include "..\controller.h"
#include "../Shapes/Shape.h"

#include "..\GUI\GUI.h"
#include"..\Shapes\Graph.h"
#include"..\operations\operation.h"


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
	
	if (pGr->getEmptyVector())
		exit(0);
	
	else {
		if (pGr->isSaved == false) {

			pUI->PrintMessage("There is changes unsaved ...Do you want to save is?(Yes/No)");
			while (true) {
				string choice = pUI->GetSrting();


				/*while (choice != "Yes" || choice != "yes" || choice != "No" || choice != "no") {
					pUI->PrintMessage("Please enter yes / no");
				}*/

				if (choice == "Yes" || choice == "yes") {

					pUI->PrintMessage("Enter File Name");

					string fileName = pUI->GetSrting();

					outfile.open(fileName + ".txt"); // open file and store it in folder in working directory

					pGr->Save(outfile);

					outfile.close();

					exit(0);
				}

				else if (choice == "No" || choice == "no")
					exit(0);
				else
					pUI->PrintMessage("Please enter yes / no");
			}
		}
		else
			exit(0);
	}
}
