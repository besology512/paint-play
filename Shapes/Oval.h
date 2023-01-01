#pragma once

#include "shape.h"
#include <fstream>

class Oval : public shape
{
private:
	Point Corner1;
	Point Corner2;
	int sizeFactor = 1;

public:
	Oval(Point, Point, GfxInfo shapeGfxInfo);
	virtual ~Oval();
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
	void Move(int x,int y) override;
	Point getUpperLeftPoint();
	void stickImage(image, GUI* pUI) override;
};