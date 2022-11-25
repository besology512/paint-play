#pragma once

#include "Shapes/Shape.h"
class Line : public shape 
{

	private:
		Point point1;
		Point point2;

	public:
		Line(Point p1, Point p2, GfxInfo shapeGfxInfo);
		virtual ~Line();
		virtual void Draw(GUI* pUI) const;


};

