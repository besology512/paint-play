#pragma once

#include "../Shapes/Shape.h"
#include <fstream>

class Triangle : public shape
{
private:
	int duplicateID;
	Point Corner1;
	Point Corner2;
	Point Corner3;

public:
	Triangle(Point, Point, Point, GfxInfo shapeGfxInfo);
	virtual ~Triangle();
	virtual void Draw(GUI *pUI) const;
	void SAVE(ofstream &OutFile);
	virtual bool inShape(int, int) const;				// check whether a point in the shape or not
	double getArea(int, int, int, int, int, int) const; // Get the area of the triagnle
	virtual string shapeInfo();							// give some info about the shape
	void LOAD(ifstream &Infile);
	double getWidth();
	double getHeight();
	void resize(float factor) override;
	void Rotate() override;
	shape *clone() override;
	void Move(int x, int y) override;
	void zoom(double scale, int x, int y) override;		// Zoom the shape in
	Point getUpperLeftPoint();


	void stickImage(image, GUI* pUI) override;
	int getDuplicateID();
	void setDuplicateID(int);
	void SCRAMBLE(Point randomPoint) override;
	Point getCenter() override;
};