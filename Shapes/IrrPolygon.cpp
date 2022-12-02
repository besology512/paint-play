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

bool IrrPolygon::inShape(int x, int y) const
{

	int i, j, c = 0;
	for (i = 0, j = verticies - 1; i < verticies; j = i++)
	{
		if (((allPoints[i].y > y) != (allPoints[j].y > y)) && (x < (allPoints[j].x - allPoints[i].x) * (y - allPoints[i].y) / (allPoints[j].y - allPoints[i].y) + allPoints[i].x))
			c = !c;
	}

	if (c)
		return true;
	else
		return false;
}