#include "opPickColor.h"
#include "../Shapes/ColorPallet.h"
#include<iostream>
#include<sstream>
#include "..\controller.h"

#include "..\GUI\GUI.h"

opPickColor::opPickColor(controller* pCont) :operation(pCont)
{}
opPickColor::~opPickColor()
{}

//Execute the operation
void opPickColor::Execute()
{
	Point P1;
	double dRed = 0, dGreen = 0, dBlue = 0; //values of color

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	//Draw the pallet image on screen
	pUI->DrawColorPicker();
	pUI->PrintMessage("Pick Color .....");
	pUI->ClearStatusBar();

	GfxInfo PickColorGfxInfo; //just for the inheritance of shape but isn't used
	ColorPallet*R = new ColorPallet(PickColorGfxInfo);

	////Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	//Add the pallet to the list of shapes temporarily and then delete it after choice of colors
	pGr->Addshape(R);
	pUI->GetPointClicked(P1.x, P1.y);
	pUI->PickColor(P1.x, P1.y, dRed, dGreen, dBlue);
	dRed *= 255;
	dGreen *= 255;
	dBlue *= 255;
	if (P1.x >= 400 && P1.x <= 400 + 610 && P1.y >= 50 && P1.y <= 50 + 500) {
		ostringstream output;
		output << "Red: " << dRed << "  Green: " << dGreen << "  Blue: " << dBlue;
		pUI->PrintMessage(output.str());


		pGr->setPickedClr(dRed, dGreen, dBlue);

		//Set the save status is false
		pGr->isSaved = false;
	}
	pGr->RemoveShape(R);

}