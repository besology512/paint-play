#include ".//Triangle.h"

Triangle::Triangle(Point P1, Point P2, Point P3, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
}

Triangle::~Triangle()
{}

void Triangle::Draw(GUI* pUI) const
{
	//Call Output::Draw Triangle to draw a Triangle on the screen	
	pUI->DrawTriangle(Corner1, Corner2, Corner3,ShpGfxInfo);
}

void Triangle::SAVE(ofstream& OutFile)
{
	OutFile << "Triangle\n"
		<< "p1 (" << Corner1.x << " , " << Corner1.y << ")\n"
		<< "p2 (" << Corner2.x << " , " << Corner2.y << ")\n"
		<< "p3 (" << Corner3.x << " , " << Corner3.y << ")\n"
		<< "BorderWdth : " << ShpGfxInfo.BorderWdth << "\n"
		<< "isFilled : " << ShpGfxInfo.isFilled << "\n"
		<< "isSelected : " << ShpGfxInfo.isSelected << "\n"
		<< "DrawClr : (" << ShpGfxInfo.DrawClr.ucBlue << " , " << ShpGfxInfo.DrawClr.ucGreen << " , " << ShpGfxInfo.DrawClr.ucRed << ")\n"
		<< "FillClr : (" << ShpGfxInfo.FillClr.ucBlue << " , " << ShpGfxInfo.FillClr.ucGreen << " , " << ShpGfxInfo.FillClr.ucRed << ")\n\n";//color ; // Put data into file
}
