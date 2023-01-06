#include "controller.h"
#include "operations\opAddRect.h"
#include"operations/opAddTriangle.h"
#include"operations/opAddCircle.h"
#include"operations/opAddOval.h"
#include"operations/opAddSquare.h"
#include"operations/opAddIrrPolygon.h"
#include"operations/opAddRegularPolygon.h"
#include"operations/opSelectUnselect.h"
#include "operations/opAddLine.h"
#include "operations/opSave.h"
#include "operations/opPickColor.h"
#include"operations/OpSwitch.h"
#include"operations/opDelete.h"
#include"operations/opChangeFill.h"
#include"operations/opChangeBorderClr.h"
#include"operations/opChangeBorderWidth.h"
#include ".//operations/opLoad.h"
#include "operations/opStickImage.h"
#include"operations/opExit.h"
#include"operations/opRestart.h"
#include"operations/opstart.h"
#include"operations/opResize.h"
#include"operations/opRotate.h"
#include"operations/opUndo.h"
#include"operations/opRedo.h"
#include"operations/opCopy.h"
#include"operations/opPaste.h"
#include"operations/opCut.h"
#include "operations/opScramble.h"
#include "operations/opMultiCopy.h"
#include "operations/opMultiCut.h"
#include "operations/opMultiPaste.h"

#include "operations/opZoomin.h"
#include "operations/opZoomout.h"
#include"operations/opSendback.h"
#include"operations/opDuplicateGraph.h"


//Constructor
controller::controller()
{
	pGraph = new Graph;
	pGUI = new GUI;	//Create GUI object
}

//==================================================================================//
//								operations-Related Functions							//
//==================================================================================//
operationType controller::GetUseroperation() const
{
	//Ask the input to get the operation from the user.
	return pGUI->GetUseroperation();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an operation and executes it
operation* controller::createOperation(operationType OpType)
{
	operation* pOp = nullptr;
	
	//According to operation Type, create the corresponding operation object
	switch (OpType)
	{
		case UNDO:
			pOp = new opUndo(this);
			break;
		case REDO:
			pOp = new opRedo(this);
			break;
		case DRAW_RECT:
			pOp = new opAddRect(this);
			addToCurrentOperation(pOp);
			break;

		case DRAW_LINE:
			pOp = new opAddLine(this);
			addToCurrentOperation(pOp);
			break;

		case DRAW_TRI:
			pOp = new opAddTriangle(this);
			addToCurrentOperation(pOp);
			break;

		case DRAW_CIRC:
			pOp = new opAddCircle(this);
			addToCurrentOperation(pOp);
			break;

		case DRAW_OVAL:
			pOp = new opAddOval(this);
			addToCurrentOperation(pOp);
			break;
		case DRAW_SQUARE:
			pOp = new opAddSquare(this);
			addToCurrentOperation(pOp);
			break;

		case DRAW_IRR_POLYGON:
			pOp = new opAddIrrPolygon(this);
			addToCurrentOperation(pOp);
			break;
      
		case DRAW_REGULAR_POLYGON:
			pOp = new opAddRegularPolygon(this);
			addToCurrentOperation(pOp);
			break;
		case SEND_BACK:
			pOp = new opSendback(this);
			break;
		case SAVE:
			pOp = new opSave(this);
			break;
		case LOAD:
			pOp = new opLoad(this);
			break;
		case PICK_COLOR:
			pOp = new opPickColor(this);
			break;
		case SWITCH:
			pOp = new opSwitch(this);
			break;
		case COPY:
			pOp = new opCopy(this);
			break;
		case PASTE:
			pOp = new opPaste(this);
			break;
		case CUT:
			pOp = new opCut(this);
			break;
		case DEL:
			pOp = new opDelete(this);
			addToCurrentOperation(pOp);
			break;
		case CHNG_FILL_CLR:
			pOp = new opChangeFill(this);
			//addToCurrentOperation(pOp);
			break;
		case CHNG_BORDER_CLR:
			pOp = new opChangeBorderClr(this);
			//addToCurrentOperation(pOp);
			break;
		case CHNG_BORDER_WIDTH:
			pOp = new opChangeBorderWidth(this);
			//addToCurrentOperation(pOp);
			break;
		case ZOOM_IN:
			pOp = new opZoomin(this);
			//addToCurrentOperation(pOp);
			break;
		case ZOOM_OUT:
			pOp = new opZoomout(this);
			//addToCurrentOperation(pOp);
			break;
		case RESIZE:
			pOp = new opResize(this);
			addToCurrentOperation(pOp);
			break;
		case ROTATE:
			pOp = new opRotate(this);
			addToCurrentOperation(pOp);
			break;
		case STICK_IMAGE:
			pOp = new opStickImage(this);
			break;
		case SCRAMBLE:
			pOp = new opScramble(this);
			break;
		case MULTICOPY:
			pOp = new opMultiCopy(this);
			break;
		case MULTICUT:
			pOp = new opMultiCut(this);
			break;
		case MULTIPASTE:
			pOp = new opMultiPaste(this);
			break;
		case START:
			pOp = new opStart(this);
			break;
		case RESTART:
			pOp = new opRestart(this);
			break;
		case DUPLICATE_GRAPH:
			pOp = new opDuplicateGraph(this);
			break;
		case EXIT:
			pOp = new opExit(this);										///create Exitoperation here
			break;

		case DRAWING_AREA:

			pOp = new opSelectUnselect(this);

			break;
		
		case STATUS:	//a click on the status bar ==> no operation
			break;
	}

	return pOp;
	delete pOp;
	
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all shapes on the user interface
void controller::UpdateInterface() const
{	
	pGraph->Draw(pGUI);
	
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the UI
GUI *controller::GetUI() const
{	return pGUI; }
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the Graph
Graph* controller::getGraph() const
{
	return pGraph;
}



//Destructor
controller::~controller()
{
	delete pGUI;
	delete pGraph;
	
}



//==================================================================================//
//							Run function											//
//==================================================================================//
void controller::Run()
{
	operationType OpType;
	do
	{
		//1. Ask the GUI to read the required operation from the user
		OpType = GetUseroperation();

		//2. Create an operation coresspondingly
		operation* pOpr = createOperation(OpType);
		 
		//3. Execute the created operation
		if (pOpr)
		{
			pOpr->Execute();//Execute
			//delete pOpr;	//operation is not needed any more ==> delete it
			//pOpr = nullptr;
		}

		//Update the interface
		UpdateInterface();

	} while (OpType != EXIT);

}

void controller::addToCurrentOperation(operation* newOperation) {
	if (newOperation) {
		Operations.emplace(newOperation);
	}
}

operation* controller::getLastOperation() {
	if (!Operations.empty())
	{
		return Operations.top();
	}
	else {
		pGUI->PrintMessage("There is no operations to be undone");
		return nullptr;
	}
}
operation* controller::getUndoneOperation() {
	if (!UndoneOperations.empty())
	{
		return UndoneOperations.top();
	}
	else {
		pGUI->PrintMessage("There is no operation to be redone");
		return nullptr;
	}
}

void controller::UndoOperation() {
	if (getLastOperation())
	{
		UndoneOperations.emplace(getLastOperation());
		Operations.pop();
	}
}

void controller::RedoOperation() {
	if (getUndoneOperation())
	{
		Operations.emplace(getUndoneOperation());
		UndoneOperations.pop();
	}
}