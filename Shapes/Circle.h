#pragma once

#include "../Shapes/Shape.h"

class Circle: public shape
{
private:
	Point Center;
	Point PointOnCircle;
public:
	Circle(Point,Point, GfxInfo shapeGfxInfo);
	virtual ~Circle();
	virtual void Draw(GUI* pUI) const;
};