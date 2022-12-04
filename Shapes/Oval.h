#pragma once

#include "shape.h"
#include <fstream>

class Oval : public shape
{
private:
	Point Corner1;
	Point Corner2;

public:
	Oval(Point, Point, GfxInfo shapeGfxInfo);
	virtual ~Oval();
	virtual void Draw(GUI* pUI) const;
	void SAVE(ofstream& OutFile);
	virtual bool inShape(int, int) const;		 //check whether a point in the shape or not
	virtual string shapeInfo();					// give some info about the shape

};