#include "opAddIrrPolygon.h"
#include "../Shapes/IrrPolygon.h"

#include "..\controller.h"

#include "..\GUI\GUI.h"

opAddIrrPolygon::opAddIrrPolygon(controller* pCont) :operation(pCont)
{}
opAddIrrPolygon::~opAddIrrPolygon()
{}

//Execute the operation
void opAddIrrPolygon::Execute()
{
	std::vector<Point> allPoints;
	int verticies;


	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("New Irrigular Polygon: type in number of verticies from 4 to 9");
	char inputChar;
	pUI->GetKeyClicked(inputChar);
	while (1)
	{
		if (inputChar == '4') { verticies = 4; break; }
		else if (inputChar == '5') { verticies = 5; break; }
		else if (inputChar == '6') { verticies = 6; break; }
		else if (inputChar == '7') { verticies = 7; break; }
		else if (inputChar == '8') { verticies = 8; break; }
		else if (inputChar == '9') { verticies = 9; break; }
		else { pUI->PrintMessage("You should type only numbers from 4 to 9 try again..."); }
	}
	pUI->PrintMessage(to_string(verticies)+" verticies.... just click them");
	//Read center and store in point P1
	int x;
	int y;
	for (int i = 0; i < verticies; i++)
	{
		pUI->GetPointClicked(x, y);
		Point iPoint;
		iPoint.x = x;
		iPoint.y = y;
		allPoints.push_back(iPoint);
		string msg = "Point " + to_string(i + 1) + " is at " +"(" + to_string(x) + ", " + to_string(y) + ")";
		msg += " ... Click at Point "+ to_string(i + 2);
		pUI->PrintMessage(msg);
	}
	
	pUI->ClearStatusBar();

	//Preapre all Irregular Polygon parameters
	GfxInfo IrrPolGfxInfo;

	//get drawing, filling colors and pen width from the interface
	IrrPolGfxInfo.DrawClr = pUI->getCrntDrawColor();
	IrrPolGfxInfo.FillClr = pUI->getCrntFillColor();
	IrrPolGfxInfo.BorderWdth = pUI->getCrntPenWidth();


	IrrPolGfxInfo.isFilled = false;	//default is not filled
	IrrPolGfxInfo.isSelected = false;	//defualt is not selected


	//Create a Circle with the above parameters
	IrrPolygon* R = new IrrPolygon(allPoints,verticies, IrrPolGfxInfo);
	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	//Add the rectangle to the list of shapes
	pGr->Addshape(R);

}