#pragma once

#include "../Shapes/Shape.h"
#include <fstream>

class Line : public shape 
{

private:
	int duplicateID;
	Point point1;
	Point point2;


public:
	Line(Point p1, Point p2, GfxInfo shapeGfxInfo);
	virtual ~Line();
	virtual void Draw(GUI* pUI) const;
	void SAVE(ofstream& OutFile);
	virtual bool inShape(int, int) const;		 //check whether a point in the shape or not
	virtual string shapeInfo();					// give some info about the shape
	void LOAD(ifstream& Infile);
	double getWidth();
	void resize(float factor) override;
	void Rotate() override;
	double getHeight();
	shape* clone() override;
	void Move(int x,int y) override;
	void zoom(double scale, int x, int y) override;		// Zoom the shape in
	Point getUpperLeftPoint();
	void SCRAMBLE(Point randomPoint) override;


	void stickImage(image, GUI* pUI) override;
	int getDuplicateID();
	void setDuplicateID(int);
	Point getCenter() override;
};

