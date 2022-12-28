#include"opCopy.h"
#include"../controller.h"
#include"../GUI/GUI.h"
#include<iostream>
opCopy::opCopy(controller* pCont) :operation(pCont) {}

opCopy::~opCopy() {}

void opCopy::Execute() {
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
    if (pGr->getselectedshape())
    {
        //cloned another shape and then moved to the clipboard {Cloned Shapes}
        pGr->addToCloned(pGr->getselectedshape()->clone());
        cout << "Copy worked!!!!!!!!!" << endl;
    }else{pUI->PrintMessage("Select the shape you want to copy first");}
}

void opCopy::Undo() {}
void opCopy::Redo() {}