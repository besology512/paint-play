#include ".//Circle.h"

Circle::Circle(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Center = P1;
	PointOnCircle = P2;
}

Circle::~Circle()
{}

void Circle::Draw(GUI* pUI) const
{
	//Call Output::Draw Triangle to draw a Triangle on the screen	
	pUI->DrawCircle(Center, PointOnCircle, ShpGfxInfo);
}

bool Circle::inShape(int x, int y) const
{
	double radius = sqrt(pow(Center.x - PointOnCircle.x,2) + pow(Center.y - PointOnCircle.y,2));
	double d = sqrt(pow(x - Center.x, 2) + pow(y - Center.y, 2));	 //distance formula for the circle

	if (d <= radius)
		return true;
	else
		return false;
}