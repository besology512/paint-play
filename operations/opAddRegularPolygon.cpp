#include ".//opAddRegularPolygon.h"
#include "../Shapes/RegularPolygon.h"

#include "..\controller.h"

#include "..\GUI\GUI.h"

opAddRegularPolygon::opAddRegularPolygon(controller* pCont) :operation(pCont)
{}
opAddRegularPolygon::~opAddRegularPolygon()
{}


//Execute the operation
void opAddRegularPolygon::Execute()
{
	Point center;
	char numOfVertices;
	char radius;

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("New Regular Polygon: Click at the Center of the Polygon");
	//Read 1st corner and store in point P1
	pUI->GetPointClicked(center.x, center.y);

	string msg = "The center is at (" + to_string(center.x) + ", " + to_string(center.y) + " )";
	msg += " Enter the number of vertices for the regular polygon";
	pUI->PrintMessage(msg);

	//Get the number of vertices from the user
	pUI->GetKeyClicked(numOfVertices);

	while((int(numOfVertices) - 48 < 3) || (int(numOfVertices) - 48 > 9))
	{
		msg = "Error! Please Enter a number of the vertices between 3 and 9";
		pUI->PrintMessage(msg);
		pUI->GetKeyClicked(numOfVertices);
	}

	//Get the radius
	msg = "Enter the size of the regular polygon";
	pUI->PrintMessage(msg);

	pUI->GetKeyClicked(radius);

	while ((int(radius) - 48 <= 0) || (int(radius) - 48 > 9))
	{
		msg = " Error! Please Enter a number of the radius between 1 and 9";
		pUI->PrintMessage(msg);
		pUI->GetKeyClicked(radius);
	}

	pUI->ClearStatusBar();

	//Preapre all rectangle parameters
	GfxInfo RectGfxInfo;

	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pUI->getCrntDrawColor();
	RectGfxInfo.FillClr = pUI->getCrntFillColor();
	RectGfxInfo.BorderWdth = pUI->getCrntPenWidth();


	RectGfxInfo.isFilled = false;	//default is not filled
	RectGfxInfo.isSelected = false;	//defualt is not selected


	//Create a regular polygon with the above parameters
	RegularPolygon* RP = new RegularPolygon(center, int((int(numOfVertices) - 48)), int((int(radius) - 48)) * 15, RectGfxInfo); //Multiplied the radius to make it bigger

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	//Add the rectangle to the list of shapes
	pGr->Addshape(RP);

}
