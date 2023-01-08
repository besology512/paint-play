#include"opCopy.h"
#include"../controller.h"
#include"../GUI/GUI.h"
#include<iostream>
opCopy::opCopy(controller* pCont) :operation(pCont) {}

opCopy::~opCopy() {}

void opCopy::Execute() {
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
    if (!(pGr->getSelectedShapes().size() == 1 || pGr->getSelectedShapes().size() == 0))
    {
        for (int i = 0; i < pGr->getSelectedShapes().size(); i++)
        {
            if (pGr->getSelectedShapes()[i])
            {
                pGr->addToCloned(pGr->getSelectedShapes()[i]->clone());
                std::cout << "multiple copy done " << i;
            }
        }
    }
    if (pGr->getselectedshape() && pGr->getSelectedShapes().size() < 2)
    {
        //cloned another shape and then moved to the clipboard {Cloned Shapes}
        pGr->addToCloned(pGr->getselectedshape()->clone());
    }else{pUI->PrintMessage("Select the shape you want to copy first");}
}

void opCopy::Undo() {}
void opCopy::Redo() {}