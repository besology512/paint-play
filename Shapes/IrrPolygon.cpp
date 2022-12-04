#include ".//IrrPolygon.h"

IrrPolygon::IrrPolygon(std::vector<Point> allPoints, int verticies, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	this->verticies = verticies;
	this->allPoints = allPoints;
}

IrrPolygon::~IrrPolygon()
{}

void IrrPolygon::Draw(GUI* pUI) const
{
	//Call Output::DrawIrrPolygon polygon to draw an irrigular polygon on the screen	
	pUI->DrawIrrPolygon(allPoints, verticies, ShpGfxInfo);
}

void IrrPolygon::SAVE(ofstream& OutFile)
{
	OutFile << "IrrPolygon\n"
		<< "verticies : " << verticies;

	for (auto allPoints : allPoints)
	{
		OutFile << "p" <<counter++ <<" (" << allPoints.x << " , " << allPoints.y << ")\n";

			
	}

		OutFile << "BorderWdth : " << ShpGfxInfo.BorderWdth << "\n"
		<< "isFilled : " << ShpGfxInfo.isFilled << "\n"
		<< "isSelected : " << ShpGfxInfo.isSelected << "\n"
		<< "DrawClr : (" << ShpGfxInfo.DrawClr.ucBlue << " , " << ShpGfxInfo.DrawClr.ucGreen << " , " << ShpGfxInfo.DrawClr.ucRed << ")\n"
		<< "FillClr : (" << ShpGfxInfo.FillClr.ucBlue << " , " << ShpGfxInfo.FillClr.ucGreen << " , " << ShpGfxInfo.FillClr.ucRed << ")\n\n";
}
