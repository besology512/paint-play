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
	
bool Line::inShape(int x, int y) const
{
	//double lineSlope = (point2.y - point1.y) / (point2.x - point1.x);
	//double lineEquation = (lineSlope * x) - ((lineSlope * point1.x) + point1.y); 
	//if (int(lineEquation) == y)
	//	return true;
	//else
	//	return false;

	double d = sqrt(pow(point1.x - point2.x, 2) + pow(point1.y - point2.y, 2)); //The distance between the two vertices of the line
	double d1 = sqrt(pow(point1.x - x, 2) + pow(point1.y - y, 2)); //The distance between one vertix and the point
	double d2 = sqrt(pow(x - point2.x, 2) + pow(y - point2.y, 2)); //The distance between the another vertix and the point

	if ((d*1.0005)  >= d1 + d2) // Because of the decimal errors I multiplied the length of the line by small factor
		return true;
	else
		return false;


}