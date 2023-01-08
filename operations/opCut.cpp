#include"opCut.h"

#include"../controller.h"

#include"../GUI/GUI.h"
#include<iostream>
opCut::opCut(controller* pCont) :operation(pCont) {}

opCut::~opCut() {}

void opCut::Execute() {
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
        for (int i = 0; i < pGr->getSelectedShapes().size()-1; i++)
        {
            if (pGr->getSelectedShapes()[i])
            {
                pGr->DeleteShape(pGr->getSelectedShapes()[i]);
            }
        }
    }
    if (pGr->getselectedshape())
    {
        //cloned another shape and then moved to the clipboard {Cloned Shapes}
        pGr->addToCloned(pGr->getselectedshape()->clone());
        pGr->DeleteShape(pGr->getselectedshape());
        cout << "Cut worked!!!!!!!!!" << endl;
    }else{pUI->PrintMessage("Select the shape you want to Cut first");}
}

void opCut::Undo() {}
void opCut::Redo() {}