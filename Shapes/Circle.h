#pragma once

#include "../Shapes/Shape.h"
#include <fstream>


class Circle: public shape
{
private:
	Point Center;
	Point PointOnCircle;
	int sizeFactor = 1;
public:
	Circle(Point,Point, GfxInfo shapeGfxInfo);
	virtual ~Circle();
	virtual void Draw(GUI* pUI) const;
	void SAVE(ofstream& OutFile);
	virtual bool inShape(int, int) const;
	virtual string shapeInfo();					// give some info about the shape
	void LOAD(ifstream& Infile);
	double getWidth();
	double getHeight();
	void resize(float factor) override;
	void Rotate() override;
	shape* clone() override;
	void Move(int x,int y) override;
};