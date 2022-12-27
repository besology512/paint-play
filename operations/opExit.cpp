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
	
	if (pGr->getEmptyVector())			//check if the vector shape is empty to exit directly
		exit(0);
	
	else {
		if (pGr->isSaved == false) {			//check by flag is there were changes unsaved

			pUI->PrintMessage("There are changes unsaved ...Do you want to save it?(Yes/No)");
			while (true) {
				string choice = pUI->GetSrting();


				if (choice == "Yes" || choice == "yes") {

					pUI->PrintMessage("Enter File Name");

					string fileName = pUI->GetSrting();
					outfile.open(fileName + ".txt"); // open file and store it in folder in working directory
					Graph* pGr = pControl->getGraph();
					outfile << (int)pUI->getCrntDrawColor().ucBlue << " "
						<< (int)pUI->getCrntDrawColor().ucGreen << " "
						<< (int)pUI->getCrntDrawColor().ucRed << " "
						<< (int)pUI->getCrntFillColor().ucBlue << " "
						<< (int)pUI->getCrntFillColor().ucGreen << " "
						<< (int)pUI->getCrntFillColor().ucRed << " "
						<< pUI->getCrntPenWidth() << "\n";
					pGr->Save(outfile);
					outfile.close();
					pUI->PrintMessage("Saved Succussfully");
					pGr->DeleteShapesAfterExit();
					exit(0);
				}

				else if (choice == "No" || choice == "no") {
					
					pGr->DeleteShapesAfterExit();
					exit(0);
				}
				else
					pUI->PrintMessage("Please enter yes / no");
			}
		}
		else {
			pGr->DeleteShapesAfterExit();
			exit(0);
		}
	}
}

void opExit::Undo() {}
void opExit::Redo() {}