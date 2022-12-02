#include"opChangeFill.h"

#include"../Shapes/Shape.h"

#include"../controller.h"

#include"../GUI/GUI.h"
#include<iostream>

opChangeFill::opChangeFill(controller* pCont) :operation(pCont){}

opChangeFill::~opChangeFill(){}

void opChangeFill::Execute() {
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	if (pGr->counting) {
		pGr->counter = pGr->getShapesList().size();
	}

	if (pGr->getSelectedShape()) {
		//change the fill color of the selected shape
		pGr->getSelectedShape()->ChngFillClr(pGr->getPickedClr());
	}
	else {
		//change the general fill color of the next drawings or shapes

		pGr->counting = false;
		cout << pGr->counter<<"this is from opChange"<<endl;
		std::cout << "works";
		pGr->changeUnselcFillClr();
		//pUI->setFillcolor(pGr->getPickedClr());
		//int numberofShapes = pGr->getShapesList().size();
		/*for (auto shapePointer = begin(pGr->getShapesList()); shapePointer!= end(pGr->getShapesList()); ++shapePointer) {
			(*shapePointer)->ChngFillClr(pGr->getPickedClr());
		}*/
		//pGr->changeUnselcFillClr();
	}
	

	//GfxInfo SquareGfxInfo;

	//get drawing, filling colors and pen width from the interface
	//SquareGfxInfo.DrawClr = pUI->getCrntDrawColor();
	//SquareGfxInfo.FillClr = pUI->getCrntFillColor();
	//SquareGfxInfo.BorderWdth = pUI->getCrntPenWidth();


	//SquareGfxInfo.isFilled = false;	//default is not filled
	//SquareGfxInfo.isSelected = false;	//defualt is not selected
	//Add the Square to the list of shapes
}