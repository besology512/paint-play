#pragma once

#include "../Shapes/Shape.h"

class RegularPolygon : public shape
{
private:
	Point center;
	double numOfVertices;
	double radius;

public:
	RegularPolygon(Point, double, double, GfxInfo shapeGfxInfo);
	virtual ~RegularPolygon();
	virtual void Draw(GUI* pUI) const;
	virtual bool inShape(int, int) const;		 //check whether a point in the shape or not
	virtual string shapeInfo();					// give some info about the shape
};