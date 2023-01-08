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
    if (!(pGr->getClonedShapes().empty()) && ((pGr->getClonedShapes().size()) > 1))
    {
        pUI->PrintMessage("Click Where you want to paste!");
	    pUI->GetPointClicked(x,y);
        int relativeX = 0;
        int relativeY = 0;
        for (int i = 0; i < pGr->getClonedShapes().size()-1; i++)
        {
            relativeX += pGr->getClonedShapes()[i]->getCenter().x;
            relativeY += pGr->getClonedShapes()[i]->getCenter().y;
        }
        relativeX /= pGr->getClonedShapes().size();
        relativeY /= pGr->getClonedShapes().size();
        int diffX = x- relativeX;
        int diffY = y- relativeY;
        //Paste the shape or group of shapes in the other position x , y
        for (int i = 0; i < pGr->getClonedShapes().size(); i++)
        {
            pGr->getClonedShapes()[i]->Move(pGr->getClonedShapes()[i]->getCenter().x
                ,relativeY+y-pGr->getClonedShapes()[i]->getCenter().x);
            pGr->Addshape(pGr->getClonedShapes()[i]);
            //clear clipboard here
        }
        pGr->ClearClipboard();
        cout << "Paste worked!!!!!!!!!" << endl;
    }
    else if ((pGr->getClonedShapes().size()) == 1) {
    pUI->GetPointClicked(x, y);
    pGr->getClonedShapes()[0]->Move(x, y);
    pGr->Addshape(pGr->getClonedShapes()[0]);
    pGr->ClearClipboard();
}
    else{pUI->PrintMessage("There is nothing in the Clipboard");}
}

void opPaste::Undo() {}
void opPaste::Redo() {}