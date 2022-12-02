#pragma once

#include"../Shapes/Shape.h"

class Square : public shape {

private:

	Point corner1;
	Point corner2;

public:
	Square(Point, Point, GfxInfo shapeGfxInfo);
	virtual ~Square();
	virtual void Draw(GUI* pUI) const;
	bool inShape(int x, int y) const;
	string shapeInfo();
	double getTriangleArea(int,int,int,int,int,int) const;
};