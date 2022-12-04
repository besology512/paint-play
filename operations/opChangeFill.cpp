#include"opChangeFill.h"

#include"../Shapes/Shape.h"

#include"../controller.h"

#include"../GUI/GUI.h"

opChangeFill::opChangeFill(controller* pCont) :operation(pCont){}

opChangeFill::~opChangeFill(){}

void opChangeFill::Execute() {
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();

	if (pGr->getSelectedShape()) {
		//change the fill color of the selected shape
		pGr->getSelectedShape()->ChngFillClr(pGr->getPickedClr());
	}
	else {
		//change the general fill color of the next drawings or shapes
		
		pGr->setFilled(true);
		pUI->setFillcolor(pGr->getPickedClr());
	}
}