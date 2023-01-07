#pragma once
#include "../Shapes/Shape.h"
#include <fstream>
class StickImage : public shape
{
private:
	image picture;
	Point point1;
	double width,height;


public:
	StickImage(Point p1, double Width, double Height, GfxInfo shapeGfxInfo);
	virtual ~StickImage();
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
	void SCRAMBLE(vector <Point> v1) override;
};

