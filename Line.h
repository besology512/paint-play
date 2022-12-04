#pragma once

#include "Shapes/Shape.h"
#include <fstream>

class Line : public shape 
{

	private:
		Point point1;
		Point point2;
	

	public:
		Line(Point p1, Point p2, GfxInfo shapeGfxInfo);
		virtual ~Line();
		virtual void Draw(GUI* pUI) const;
		void SAVE(ofstream& OutFile);
		virtual bool inShape(int, int) const;		 //check whether a point in the shape or not
		virtual string shapeInfo();					// give some info about the shape


};

