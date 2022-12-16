#pragma once

#include "../Shapes/Shape.h"
#include <fstream>


class Circle: public shape
{
private:
	Point Center;
	Point PointOnCircle;
public:
	Circle(Point,Point, GfxInfo shapeGfxInfo);
	virtual ~Circle();
	virtual void Draw(GUI* pUI) const;
	void SAVE(ofstream& OutFile);
	virtual bool inShape(int, int) const;
	virtual string shapeInfo();					// give some info about the shape
	void LOAD(ifstream& Infile);

};