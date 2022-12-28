#pragma once

#include "../Shapes/Shape.h"
#include <fstream>


class RegularPolygon : public shape
{
private:
	Point center;
	double numOfVertices;
	double radius;
	int sizeFactor = 1;
public:
	RegularPolygon(Point, double, double, GfxInfo shapeGfxInfo);
	virtual ~RegularPolygon();
	virtual void Draw(GUI* pUI) const;
	void SAVE(ofstream& OutFile);
	virtual bool inShape(int, int) const;		 //check whether a point in the shape or not
	virtual string shapeInfo();					// give some info about the shape
	void LOAD(ifstream& Infile);
	double getWidth();
	double getHeight();
	void resize(float factor) override;
	void Rotate() override;
	shape* clone() override;
};