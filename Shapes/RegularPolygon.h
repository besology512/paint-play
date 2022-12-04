#pragma once

#include "../Shapes/Shape.h"
#include <fstream>


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
	void SAVE(ofstream& OutFile);
};