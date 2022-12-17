#include "controller.h"
#include "operations\opAddRect.h"
#include"operations/opAddTriangle.h"
#include"operations/opAddCircle.h"
#include"operations/opAddOval.h"
#include"operations/opAddSquare.h"
#include"operations/opAddIrrPolygon.h"
#include"operations/opAddRegularPolygon.h"
#include"operations/opSelectUnselect.h"
#include "opAddLine.h"
#include "opSave.h"
#include "operations/opPickColor.h"
#include"operations/OpSwitch.h"
#include"operations/opDelete.h"
#include"operations/opChangeFill.h"
#include"operations/opChangeBorderClr.h"
#include"operations/opChangeBorderWidth.h"
#include "opLoad.h"
#include "opStickImage.h"



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
		case DRAW_RECT:
			pOp = new opAddRect(this);
			break;

		case DRAW_LINE:
			pOp = new opAddLine(this);
			break;

		case DRAW_TRI:
			pOp = new opAddTriangle(this);
			break;

		case DRAW_CIRC:
			pOp = new opAddCircle(this);
			break;

		case DRAW_OVAL:
			pOp = new opAddOval(this);
			break;
		case DRAW_SQUARE:
			pOp = new opAddSquare(this);
			break;

		case DRAW_IRR_POLYGON:
			pOp = new opAddIrrPolygon(this);
			break;
      
		case DRAW_REGULAR_POLYGON:
			pOp = new opAddRegularPolygon(this);
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
		case DEL:
			pOp = new opDelete(this);
			break;
		case CHNG_FILL_CLR:
			pOp = new opChangeFill(this);
			break;
		case CHNG_BORDER_CLR:
			pOp = new opChangeBorderClr(this);
			break;
		case CHNG_BORDER_WIDTH:
			pOp = new opChangeBorderWidth(this);
			break;
		case STICK_IMAGE:
			pOp = new opStickImage(this);
			break;

		case EXIT:
			///create Exitoperation here
			
			break;

		case DRAWING_AREA:
			//select and unselect operation here//
			pOp = new opSelectUnselect(this);
			break;
		
		case STATUS:	//a click on the status bar ==> no operation
			break;
	}

	return pOp;
	
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
			delete pOpr;	//operation is not needed any more ==> delete it
			pOpr = nullptr;
		}

		//Update the interface
		UpdateInterface();

	} while (OpType != EXIT);

}