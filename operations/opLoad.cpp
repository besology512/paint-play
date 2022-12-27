#include "opLoad.h"
#include "../Shapes/Graph.h"
#include "../operations/operation.h"
#include "../GUI/GUI.h"
#include "../controller.h"
#include <iostream>
using namespace std;
opLoad::opLoad(controller* pCont) : operation(pCont)
{
}

opLoad::~opLoad()
{
}

void opLoad::Execute()
{
	// Get User input
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("Enter File Name");

	string fileName = pUI->GetSrting();

	inputfile.open(fileName + ".txt");

	Graph* pGr = pControl->getGraph();

	if (inputfile)
	{
		int x, y, z, a , b ,c,BW;
		inputfile >> x >> y >> z >> a >> b >> c >> BW; // taking the first line that have integer values of color 
		color Drawcolor(x, y, z);
		color Fillcolor(a, b, c);
		pUI->setDrawColor(Drawcolor);
		pUI->setFillcolor(Fillcolor);
		pUI->setBorderWidth(BW);
		

		pGr->load(inputfile);


		inputfile.close();

		pUI->PrintMessage("Loaded Succussfully");
	}
	else
	{
		pUI->PrintMessage("Wrong name file");
	}

	
}

void opLoad::Undo() {/*it must delete all selected*/}
void opLoad::Redo() {/*it must delete all selected*/}