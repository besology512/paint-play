#include "opDuplicateGraph.h"

#include "..\controller.h"
#include "../Shapes/Shape.h"

#include "..\GUI\GUI.h"
#include"..\Shapes\Graph.h"
#include"..\operations\operation.h"

opDuplicateGraph::opDuplicateGraph(controller* pCont) : operation(pCont)
{}
opDuplicateGraph::~opDuplicateGraph()
{}

//Execute the operation
void opDuplicateGraph::Execute() {
	int x, y;
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();

	pGr->duplicateShapes();
	// ok for
	//1- Set Id for each shape and its replica 
	//2- copy and paste all the shapes







}

void opDuplicateGraph::Undo() {}
void opDuplicateGraph::Redo() {}