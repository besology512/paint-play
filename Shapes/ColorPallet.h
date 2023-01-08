#pragma once

#include "../Shapes/Shape.h"
#include <fstream>
//this class is only made so I can add the color pallet to the ShapeList and loop to draw them.
class ColorPallet : public shape
{
public:
	ColorPallet(GfxInfo shapeGfxInfo);
	virtual ~ColorPallet();
	virtual void Draw(GUI* pUI) const;
	virtual bool inShape(int, int) const;		 //check whether a point in the shape or not
	virtual string shapeInfo();					// give some info about the shape
	void SAVE(ofstream& OutFile);
	void LOAD(ifstream& Infile);
	double getWidth();
	double getHeight();
	void resize(float factor) override;
	void Rotate() override;
	shape* clone() override;
	void Move(int x,int y) override;
	void zoom(double scale, int x, int y) override;		// Zoom the shape in
	Point getUpperLeftPoint();
	void SCRAMBLE(vector <Point> v1) override;
	void stickImage(image, GUI* pUI) override;
	int getDuplicateID();
	void setDuplicateID(int);
	Point getCenter() override;
};