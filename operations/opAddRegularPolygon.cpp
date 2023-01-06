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

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	pUI->PrintMessage("New Regular Polygon: Click at the Center of the Polygon");

	//Read the center and store in point center
	pUI->GetPointClicked(center.x, center.y);

	string msg = "The center is at (" + to_string(center.x) + ", " + to_string(center.y) + " )";
	msg += " Enter the number of the vertices in the regular polygon";
	pUI->PrintMessage(msg);

	//Get the number of vertices from the user
	pUI->GetKeyClicked(numOfVertices);

	while((int(numOfVertices) - 48 < 3) || (int(numOfVertices) - 48 > 9))
	{
		msg = "Error! Make sure that the number of vertices is between 3 and 9";
		pUI->PrintMessage(msg);
		pUI->GetKeyClicked(numOfVertices);
	}

	//Get the radius
	msg = "Enter the side size in the polygonal";
	pUI->PrintMessage(msg);

	pUI->GetKeyClicked(radius);

	while ((int(radius) - 48 <= 0) || (int(radius) - 48 > 9))
	{
		msg = " Error! Make Sure that the side size is between 1 and 9";
		pUI->PrintMessage(msg);
		pUI->GetKeyClicked(radius);
	}

	pUI->ClearStatusBar();

	//Preapre all regular polygon parameters
	GfxInfo RegularPolygonGfxInfo;

	//get drawing, filling colors and pen width from the interface
	RegularPolygonGfxInfo.DrawClr = pUI->getCrntDrawColor();
	RegularPolygonGfxInfo.FillClr = pUI->getCrntFillColor();
	RegularPolygonGfxInfo.BorderWdth = pUI->getCrntPenWidth();


	RegularPolygonGfxInfo.isFilled = pGr->isFilled;	//default is not filled
	RegularPolygonGfxInfo.isSelected = false;	//defualt is not selected

	//Set the save status is false
	pGr->isSaved = false;

	//Create a regular polygon with the above parameters
	RegularPolygon* RP = new RegularPolygon(center, int((int(numOfVertices) - 48)), int((int(radius) - 48)) * 15, RegularPolygonGfxInfo); //Multiplied the radius to make it bigger

	//Adding its points to a vector in the regular polygon
	const double PI = 3.141592653589;			//Defining constant PI
	double angle = (2 * PI) / numOfVertices;	//Defining the angle between two vertices

	for (int i = 0; i < int(numOfVertices); i++)
	{
		int x = center.x + radius * sin(i * angle);
		int y = center.y + radius * cos(i * angle);

		Point point; point.x = x; point.y = y;

		RP->addPoint(point);
	}

	//Add the rectangle to the list of shapes
	pGr->Addshape(RP);

}

void opAddRegularPolygon::Undo() {
	Graph* pGr = pControl->getGraph();
	pGr->PutInUndoShapes();
}
void opAddRegularPolygon::Redo() {
	Graph* pGr = pControl->getGraph();
	pGr->FromUndotoShapesList();
}