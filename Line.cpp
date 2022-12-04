#include "Line.h"

Line::Line(Point p1, Point p2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	point1 = p1;
	point2 = p2;
}

Line::~Line()
{
}

void Line::Draw(GUI* pUI) const
{
	pUI->DrawLine(point1, point2, ShpGfxInfo);


}

void Line::SAVE(ofstream& OutFile)
{

	OutFile << "Line\n"
		<< "p1 (" << point1.x << " , " << point1.y << ")\n"
		"p2 (" << point2.x << " , " << point2.y << ")\n"
		<< "BorderWdth : " << ShpGfxInfo.BorderWdth << "\n"
		<< "isFilled : " << ShpGfxInfo.isFilled << "\n"
		<< "isSelected : " << ShpGfxInfo.isSelected << "\n"
		<< "DrawClr : (" << ShpGfxInfo.DrawClr.ucBlue << " , " << ShpGfxInfo.DrawClr.ucGreen << " , " << ShpGfxInfo.DrawClr.ucRed << ")\n"
		<< "FillClr : (" << ShpGfxInfo.FillClr.ucBlue << " , " << ShpGfxInfo.FillClr.ucGreen << " , " << ShpGfxInfo.FillClr.ucRed << ")\n\n";//color ; // Put data into file


}