#include ".//RegularPolygon.h"

RegularPolygon::RegularPolygon(Point c, double v, double r, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	center = c;
	numOfVertices = v;
	radius = r;
}

RegularPolygon::~RegularPolygon(){}

void RegularPolygon::Draw(GUI* pUI) const
{
	//Call Output::Draw Triangle to draw a Triangle on the screen	
	pUI->DrawRegularPolygon(center, numOfVertices, radius, ShpGfxInfo);
}

bool RegularPolygon::inShape(int x, int y) const
{

	return false; //Temp
}