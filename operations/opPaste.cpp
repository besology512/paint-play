#include"opPaste.h"

#include"../controller.h"

#include"../GUI/GUI.h"
#include<iostream>
opPaste::opPaste(controller* pCont) :operation(pCont) {}

opPaste::~opPaste() {}

void opPaste::Execute() {
    int x,y;
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
    if (!(pGr->getClonedShapes().empty()))
    {
        pUI->PrintMessage("Click Where you want to paste!");
	    pUI->GetPointClicked(x,y);
        //Paste the shape or group of shapes in the other position x , y
        for (int i = 0; i < pGr->getClonedShapes().size(); i++)
        {
            pGr->getClonedShapes()[i]->Move(x,y);
            pGr->Addshape(pGr->getClonedShapes()[i]);
            //clear clipboard here
        }
        pGr->ClearClipboard();
        cout << "Paste worked!!!!!!!!!" << endl;
    }else{pUI->PrintMessage("There is nothing in the Clipboard");}
}

void opPaste::Undo() {}
void opPaste::Redo() {}