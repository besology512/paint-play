#include "Square.h"

Square::Square(Point P1, Point P2, GfxInfo shapeGfxInfo) : shape(shapeGfxInfo) {
	corner1 = P1;
	corner2 = P2;
}

Square::~Square()
{}

void Square::Draw(GUI* pUI) const
{
	//Call Output::DrawSquare to draw a square on the screen	
	pUI->DrawSquare(corner1, corner2, ShpGfxInfo);
}

double Square::getTriangleArea(int x1, int y1, int x2, int y2, int x3, int y3) const
{
	double area = abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
	return area;
}

void Square::SAVE(ofstream& OutFile)
{
	OutFile << "Triangle\n"
		<< "p1 (" << corner1.x << " , " << corner1.y << ")\n"
		<< "p2 (" << corner2.x << " , " << corner2.y << ")\n"
		<< "BorderWdth : " << ShpGfxInfo.BorderWdth << "\n"
		<< "isFilled : " << ShpGfxInfo.isFilled << "\n"
		<< "isSelected : " << ShpGfxInfo.isSelected << "\n"
		<< "DrawClr : (" << ShpGfxInfo.DrawClr.ucBlue << " , " << ShpGfxInfo.DrawClr.ucGreen << " , " << ShpGfxInfo.DrawClr.ucRed << ")\n"
		<< "FillClr : (" << ShpGfxInfo.FillClr.ucBlue << " , " << ShpGfxInfo.FillClr.ucGreen << " , " << ShpGfxInfo.FillClr.ucRed << ")\n\n";//color ; // Put data into file
}

bool Square::inShape(int x, int y) const 
{
	int diffx = corner1.x - corner2.x;				//get difference between X coordinates
	int diffy = corner1.y - corner2.y;
	Point P3;
	P3.x = corner1.x + diffy;
	P3.y = corner1.y - diffx;
	Point P4;
	P4.x = corner2.x + diffy;						//add differences of y to x to get p4
	P4.y = corner2.y - diffx;

	double T1 = getTriangleArea(corner1.x, corner1.y, x, y, corner2.x, corner2.y);
	double T2 = getTriangleArea(corner2.x, corner2.y, x, y, P3.x, P3.y);
	double T3 = getTriangleArea(P3.x, P3.y, x, y, P4.x, P4.y);
	double T4 = getTriangleArea(P4.x, P4.y, x, y, corner1.x, corner1.y);

	double sArea = pow(sqrt(pow(corner1.x - corner2.x, 2) + pow(corner1.y - corner2.y, 2)), 2);

	if (sArea >= T1 + T2 + T3 + T4)
		return true;
	else
		return false;

}

string Square::shapeInfo() 
{ 
	int area;
	Point center;
	string msg;

	area = sqrt(pow(corner1.x - corner2.x, 2)) * sqrt(pow(corner1.y - corner2.y, 2));
	center.x = sqrt(pow(corner1.x - corner2.x, 2)) / 2;
	center.y = sqrt(pow(corner1.y - corner2.y, 2)) / 2;

	msg = "The Square Area is " + to_string(area) + " The center is at (" + to_string(center.x) + "," + to_string(center.y) + ")";
	return msg;
}
