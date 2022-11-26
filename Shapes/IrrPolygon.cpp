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
	//Call Output::Draw Triangle to draw a Triangle on the screen	
	pUI->DrawIrrPolygon(allPoints, verticies, ShpGfxInfo);
}