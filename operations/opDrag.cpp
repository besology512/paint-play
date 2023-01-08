#include"opDrag.h"

#include"../controller.h"

#include"../GUI/GUI.h"

opDrag::opDrag(controller* pCont) :operation(pCont) {}

opDrag::~opDrag() {}

void opDrag::Execute() {
	////Point P1 = {0,0};
	//int x, y =0;
	//x = 0;
	//GUI* pUI = pControl->GetUI();
	//Graph* pGr = pControl->getGraph();
	////pUI->GetMousCoord(P1.x, P1.y);
	//if (pGr->getselectedshape()) {
	//	while (pUI->Dragging( x, y) != BUTTON_DOWN) {
	//		if (y > 50 && y < 550) {
	//			pGr->DragSingleShape(pGr->getselectedshape(), x, y);
	//			pUI->ClearStatusBar();
	//			pUI->ClearToolBar();
	//			pControl->UpdateInterface();
	//			Sleep(50);
	//			
	//		}
	//	}
	//}
	//else {
	//	pUI->PrintMessage("Please Select a shape");
	//}
}

void opDrag::Undo() {}
void opDrag::Redo() {}