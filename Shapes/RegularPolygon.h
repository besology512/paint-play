#pragma once

#include "../Shapes/Shape.h"
#include <fstream>


class RegularPolygon : public shape
{
private:
	int duplicateID;
	Point center;
	double numOfVertices;
	double radius;
	int sizeFactor = 1;
	std::vector<Point> regularPolygonPoints;


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
	void Move(int x,int y) override;
	void zoom(double scale, int x, int y) override;		// Zoom the shape in
	Point getUpperLeftPoint();
	void SCRAMBLE(vector <Point> v1) override;

	void stickImage(image, GUI* pUI) override;
	int getDuplicateID();
	void setDuplicateID(int);
	void addPoint(Point);
};