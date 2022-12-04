#pragma once
#include <vector>
#include "../Shapes/Shape.h"
#include <fstream>

class IrrPolygon : public shape
{
private:
	int verticies;
	std::vector<Point> allPoints;
	int counter;
public:
	IrrPolygon(std::vector<Point> allPoints,int verticies, GfxInfo shapeGfxInfo);
	virtual ~IrrPolygon();
	virtual void Draw(GUI* pUI) const;

	void SAVE(ofstream& OutFile);
	virtual bool inShape(int, int) const;		 //check whether a point in the shape or not
	virtual string shapeInfo();					// give some info about the shape

};