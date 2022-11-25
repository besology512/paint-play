#pragma once

#include "../Shapes/Shape.h"

class IrrPolygon : public shape
{
private:
	int verticies;
	Point* allPoints;
	//allPoints = new Point[verticies];
public:
	IrrPolygon(Point*,int verticies, GfxInfo shapeGfxInfo);
	virtual ~IrrPolygon();
	virtual void Draw(GUI* pUI) const;
};