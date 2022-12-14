#pragma once
#include "shape.h"
#include <fstream>

class Rect : public shape
{
private:
	int duplicateID;
	Point Corner1;	
	Point Corner2;
	Point Corner3;
	string isFilled;
	int sizeFactor = 1;
public:
	Rect(Point , Point, GfxInfo shapeGfxInfo );
	virtual ~Rect();
	virtual void Draw(GUI* pUI) const;
	void SAVE(ofstream& OutFile) override;
	virtual bool inShape(int, int) const;		 //check whether a point in the shape or not
	virtual string shapeInfo() ;					// give some info about the shape
	void LOAD(ifstream& Infile) override;
	double getWidth();
	double getHeight();
	void resize(float factor) override;
	void Rotate() override;
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

