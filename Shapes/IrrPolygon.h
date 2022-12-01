#pragma once
#include <vector>
#include "../Shapes/Shape.h"

class IrrPolygon : public shape
{
private:
	int verticies;
	std::vector<Point> allPoints;
public:
	IrrPolygon(std::vector<Point> allPoints,int verticies, GfxInfo shapeGfxInfo);
	virtual ~IrrPolygon();
	virtual void Draw(GUI* pUI) const;
	virtual bool inShape(int, int) const;		 //check whether a point in the shape or not
};